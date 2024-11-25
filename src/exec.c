/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 09:59:22 by tappourc          #+#    #+#             */
/*   Updated: 2024/01/26 09:08:16 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	ft_exec(char *cmd, char **env)
{
	char	**command;
	char	*good_path;
	int		exit_status;
	int		y;

	y = 0;
	command = ft_split(cmd, ' ');
	while (command[y])
		y++;
	good_path = build_all_path(command[0], env);
	if (good_path == NULL)
	{
		free_tab(command);
		free(good_path);
		ft_exit_error("failed to find command\n", 127);
	}
	exit_status = execve(good_path, command, env);
	if (exit_status == -1)
	{
		free_tab(command);
		free(good_path);
		exit(exit_status);
	}
	return (0);
}

int	search_path(char **env)
{
	int		i;
	int		found;

	i = 0;
	found = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			found++;
			break ;
		}
		i++;
	}
	if (found == 0)
		return (-1);
	return (i);
}

char	*build_all_path(char *cmd, char **env)
{
	char	**path;
	char	*tmp;
	char	*go_ex;
	char	*first;
	int		i;

	i = search_path(env);
	if (i == -1)
		return (NULL);
	path = ft_split(env[i], ':');
	first = path[0];
	path[0] = ft_substr(first, 5, (ft_strlen(first) - 5));
	free(first);
	i = -1;
	while (path[++i] != NULL)
	{
		tmp = ft_strjoin(path[i], "/");
		go_ex = ft_strjoin(tmp, cmd);
		free(tmp);
		if (go_ex != NULL && (access(go_ex, F_OK | X_OK) == 0))
			return (go_ex);
		free(go_ex);
	}
	free_tab(path);
	return (NULL);
}

void	first_exec(char *filename)
{
	int	fd_in;

	fd_in = open(filename, O_RDONLY, 0644);
	if (fd_in == -1)
	{
		close(fd_in);
		return ;
	}
	dup2(fd_in, 0);
	close(fd_in);
}

int	last_exec(char *cmd, char **env, char *filename)
{
	int		fd_out;
	int		exit_code;
	int		status;
	int		w;
	pid_t	pid;

	fd_out = open(filename, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (fd_out == -1)
		ft_exit_error("open fd error\n", 1);
	dup2(fd_out, 1);
	close(fd_out);
	pid = fork();
	if (pid == -1)
		ft_exit_error("fork failed\n", 1);
	else if (!pid)
		exit_code = ft_exec(cmd, env);
	w = waitpid(-1, &status, 0);
	if (WIFEXITED(status) || w == -1)
		return (exit_code);
	return (0);
}
