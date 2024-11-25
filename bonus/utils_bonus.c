/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 09:49:02 by tappourc          #+#    #+#             */
/*   Updated: 2024/01/29 10:36:25 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex_bonus.h"

void	ft_exit_error(char *msg, int status)
{
	ft_putstr_fd(msg, 2);
	exit(status);
}

void	ft_exit_clean(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(0);
}

int	check_open(char *file1, char *file2)
{
	int	fd[2];

	fd[0] = open(file1, O_RDONLY, 0644);
	fd[1] = open(file2, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (fd[0] == -1 && fd[1] == -1)
		ft_exit_error("file 1 & file2 permission denied\n", 1);
	if (fd[0] == -1)
	{
		close(fd[1]);
		return (1);
	}
	if (fd[0] != -1)
		close(fd[0]);
	if (fd[1] != -1)
		close(fd[1]);
	return (0);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	read_std(char **av, int fd)
{
	char	*tmp;

	tmp = get_next_line(0);
	if ((ft_strncmp(av[2], tmp, ft_strlen(av[2])) == 0)
		&& ft_strlen(av[2]) == ft_strlen(tmp) - 1)
	{
		free(tmp);
		return (1);
	}
	ft_putstr_fd(tmp, fd);
	free(tmp);
	return (0);
}
