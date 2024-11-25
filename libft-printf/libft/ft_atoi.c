/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:06:46 by tappourc          #+#    #+#             */
/*   Updated: 2023/11/05 14:49:52 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_space(char c)
{
	if ((c > 7 && c < 14) || (c == 32))
		return (0);
	return (1);
}

int	ft_atoi(const char *nptr)
{
	int		neg;
	int		nb;
	int		i;

	i = 0;
	nb = 0;
	neg = 1;
	while (nptr[i] != '\0')
	{
		while (ft_is_space(nptr[i]) == 0)
			i++;
		if ((nptr[i] == 43) || (nptr[i] == 45))
		{
			if (nptr[i] == 45)
				neg *= -1;
			i++;
		}
		while (nptr[i] > 47 && nptr[i] < 58)
		{
			nb = nb * 10 + (nptr[i] - '0');
			i++;
		}
		return (nb * neg);
	}
	return (0);
}
