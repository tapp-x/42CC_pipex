/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:31:50 by tappourc          #+#    #+#             */
/*   Updated: 2024/01/28 10:06:04 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex_bonus.h"

int	main(int ac, char **av, char **env)
{
	int		i;
	int		exit_code;

	i = 2;
	if (ac <= 4 || ((ft_strncmp(av[1], "here_doc", 8) == 0) && ac < 6))
		ft_exit_clean("Not enough arguments\n");
	if (ft_strncmp(av[1], "here_doc", 8) == 0)
	{
		manage_hdoc(av);
		i++;
	}
	else
		select_file(ac, av);
	while (i < ac - 2)
	{
		make_pipe(av[i], env);
		i++;
	}
	exit_code = last_exec(av[ac - 2], env, av[ac - 1], av);
	return (exit_code);
}

void	make_pipe(char *cmd, char **env)
{
	int		fd[2];
	int		status;
	pid_t	pid;

	if (pipe(fd) == -1)
	{
		ft_exit_error("pipe failed\n", 1);
		return ;
	}
	pid = fork();
	if (pid == -1)
	{
		ft_exit_error("fork failed\n", 1);
		return ;
	}
	else if (pid == 0)
		child(fd, cmd, env);

	waitpid(pid, &status, 0);
	parent(fd);
	return ;
}

void	child(int fd[2], char *cmd, char **env)
{
	close(fd[0]);
	dup2(fd[1], 1);
	close(fd[1]);
	ft_exec(cmd, env);
}

void	parent(int fd[2])
{
	close(fd[1]);
	dup2(fd[0], 0);
	close(fd[0]);
}

void	manage_hdoc(char **av)
{
	int		fd[2];
	int		read;
	pid_t	pid;

	read = 0;
	if (pipe(fd) == -1)
		ft_exit_error("pipe failed\n", 1);
	pid = fork();
	if (pid == -1)
		ft_exit_error("fork failed\n", 1);
	else if (!pid)
	{
		close(fd[0]);
		while (read != 1)
			read = read_std(av, fd[1]);
		close(fd[1]);
		exit(0);
	}
	wait(NULL);
	parent(fd);
}
