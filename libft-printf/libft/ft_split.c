/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:54:22 by tappourc          #+#    #+#             */
/*   Updated: 2023/11/05 11:42:43 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_part(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if ((str[i] != c && str[i + 1] == c)
			|| (str[i] != c && str[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static void	ft_splitter(const char *s, char c, char **res)
{
	int	index;
	int	part;

	index = -1;
	while (s[++index] != '\0')
	{
		if (s[index] == c)
			continue ;
		part = index;
		while (s[part] != c && s[part] != '\0')
			part++;
		*res = ft_substr((char const *)s, index, (part - index));
		res++;
		index = part - 1;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	count;

	if (!s)
		return (NULL);
	count = count_part((char *)s, c);
	res = ft_calloc((count + 1), sizeof(char *));
	if (!res)
		return (NULL);
	ft_splitter(s, c, res);
	return (res);
}
