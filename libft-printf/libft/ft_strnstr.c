/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:26:29 by tappourc          #+#    #+#             */
/*   Updated: 2023/11/05 11:29:31 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	y;
	char	*str;

	i = 0;
	str = (char *)big;
	if (little[0] == 0)
		return (str);
	if (!big && len == 0)
		return (NULL);
	while (big[i] != '\0' && i < len)
	{
		y = 0;
		while (str[i] == little[y] && little[y] != '\0' && i < len)
		{
			if (little[y + 1] == 0)
				str += (i - y);
			if (little[y + 1] == 0)
				return (str);
			i++;
			y++;
		}
		i = (i - y) + 1;
	}
	return (NULL);
}
