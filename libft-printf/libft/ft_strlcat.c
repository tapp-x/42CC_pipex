/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:19:18 by tappourc          #+#    #+#             */
/*   Updated: 2023/11/02 18:19:52 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlen_s(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

static size_t	ft_strnlen_s(char *s, size_t size)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && i < size)
		i++;
	return (i);
}

static size_t	ft_strlcpy_s(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	srclen;

	srclen = ft_strlen_s((char *)src);
	i = 0;
	if (size == 0)
		return (srclen);
	while ((src[i] != '\0' && i < (size - 1)))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (srclen);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len;
	size_t	cpy_len;
	size_t	src_len;

	src_len = ft_strlen_s((char *)src);
	if (size == 0)
		return (src_len);
	len = ft_strnlen_s(dest, size);
	cpy_len = ft_strlcpy_s(dest + len, src, size - len);
	if (len == size)
		return (len + src_len);
	return (len + cpy_len);
}
