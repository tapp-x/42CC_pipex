/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:36:18 by tappourc          #+#    #+#             */
/*   Updated: 2023/11/04 12:26:27 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t		i;
	void		*ptr;

	i = nmemb * size;
	if ((int)i < 0 || ((int)nmemb < 0 && (int)size < 0))
		return (NULL);
	ptr = malloc(i);
	if (nmemb == 0)
		return (ptr);
	if (!ptr)
		return (ptr);
	ft_bzero_s(ptr, i);
	return (ptr);
}
