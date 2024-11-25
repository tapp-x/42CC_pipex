/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:07:50 by tappourc          #+#    #+#             */
/*   Updated: 2024/01/29 10:35:47 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_exit_error(char *msg, int status)
{
	ft_putstr_fd(msg, 2);
	exit(status);
}

void	ft_exit_clean(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(1);
}

void	check_open(char *file1, char *file2)
{
	int	fd[2];

	fd[0] = open(file1, O_RDONLY, 0644);
	fd[1] = open(file2, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (fd[0] == -1 && fd[1] == -1)
		ft_exit_error("file 1 & file2 permission denied\n", 1);
	if (fd[0] != -1)
		close(fd[0]);
	if (fd[1] != -1)
		close(fd[1]);
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
