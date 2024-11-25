/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:28:03 by tappourc          #+#    #+#             */
/*   Updated: 2023/11/02 11:37:04 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		index;
	char	*res;

	i = 0;
	index = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
		i++;
	res = malloc((i + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (s[index] != '\0')
	{
		res[index] = (*f)(index, s[index]);
		index++;
	}
	res[index] = '\0';
	return (res);
}
