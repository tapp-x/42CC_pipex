/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:35:32 by tappourc          #+#    #+#             */
/*   Updated: 2023/11/04 19:06:55 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlen_s(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

static void	ft_bzero_s(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	size;
	char	*result;

	i = -1;
	if (!s)
		return (NULL);
	size = ft_strlen_s(s);
	if (len >= size)
		len = size - (size_t)start;
	if (start > size)
		len = 0;
	result = malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	if (start >= ft_strlen_s(s))
		ft_bzero_s(result, (len + 1));
	if (start >= ft_strlen_s(s))
		return (result);
	while (s[start + ++i] != '\0' && i < len)
		result[i] = s[start + i];
	result[i] = '\0';
	return (result);
}
