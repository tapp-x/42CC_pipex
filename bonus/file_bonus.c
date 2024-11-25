/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 10:19:20 by tappourc          #+#    #+#             */
/*   Updated: 2024/01/28 10:19:55 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	select_file(int ac, char **av)
{
	int	select_fd;

	select_fd = check_open(av[1], av[ac - 1]);
	if (select_fd == 0)
		first_exec(av[1]);
	else
		first_exec(av[ac - 1]);
}
