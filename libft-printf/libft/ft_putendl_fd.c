/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:57:00 by tappourc          #+#    #+#             */
/*   Updated: 2023/11/01 18:01:25 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int		i;
	char	bc;

	bc = '\n';
	i = -1;
	if (!s)
		return ;
	while (s[++i] != '\0')
		write(fd, &s[i], 1);
	write(fd, &bc, 1);
}
