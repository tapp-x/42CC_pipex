/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:03:03 by tappourc          #+#    #+#             */
/*   Updated: 2023/11/02 18:37:22 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	p;

	i = 0;
	str = (unsigned char *)s;
	p = (unsigned char)c;
	while (i < n)
	{
		if (str[i] == p)
		{
			str += i;
			return (str);
		}
		i++;
	}
	return (NULL);
}
