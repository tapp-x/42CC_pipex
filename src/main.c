/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 19:32:06 by tappourc          #+#    #+#             */
/*   Updated: 2024/01/29 09:22:04 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	main(int ac, char **av, char **env)
{
	int	fd_in;
	int	exit_code;

	if (ac != 5)
		ft_exit_clean("Not enough args\n");
	check_open(av[1], av[ac - 1]);
	fd_in = open(av[1], O_RDONLY, 0644);
	if (fd_in == -1)
		first_exec(av[4]);
	else
	{
		close(fd_in);
		first_exec(av[1]);
	}
	make_pipe(av[2], env);
	exit_code = last_exec(av[ac - 2], env, av[ac - 1]);
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
	waitpid(-1, &status, 0);
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
