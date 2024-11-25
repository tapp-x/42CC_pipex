/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:33:40 by tappourc          #+#    #+#             */
/*   Updated: 2024/01/20 09:50:08 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *str1, char const *str2)
{
	size_t	i;
	size_t	s1_len;
	size_t	s2_len;
	char	*result;

	if (!str1 || !str2)
		return (0);
	if (!str1)
		return (ft_strdup(str2));
	i = -1;
	s1_len = ft_strlen((char *)str1);
	s2_len = ft_strlen((char *)str2);
	result = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (result == NULL)
		return (0);
	while (str1[++i])
		result[i] = str1[i];
	i = -1;
	while (str2[++i])
		result[s1_len + i] = str2[i];
	result[s1_len + i] = 0;
	return ((char *)result);
}
