/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:46:36 by tappourc          #+#    #+#             */
/*   Updated: 2023/11/04 10:48:35 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_strlen_s(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strrchr(const char *s, int c)
{
	size_t	index;
	char	*str;

	index = ft_strlen_s(s);
	str = (char *)s;
	while (index > 0)
	{
		if (str[index] == c % 128)
		{
			str += index;
			return (str);
		}
		index --;
	}
	if (str[0] != c % 128)
		return (NULL);
	return (str);
}
