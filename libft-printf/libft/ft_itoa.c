/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 09:41:17 by tappourc          #+#    #+#             */
/*   Updated: 2023/11/02 18:33:30 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_size(int n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n / 10 != 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long int	i;
	long int	x;
	long int	size;
	char		*result;

	i = 0;
	x = n;
	size = (count_size(x) - 1);
	result = malloc((size + 2) * sizeof(char));
	if (!result)
		return (NULL);
	if (x < 0)
	{
		result[i] = '-';
		i++;
		x = -x;
	}
	result[size + 1] = '\0';
	while (i <= (size))
	{
		result[size] = (x % 10) + '0';
		x /= 10;
		size--;
	}
	return (result);
}
