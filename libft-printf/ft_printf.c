/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:39:46 by tappourc          #+#    #+#             */
/*   Updated: 2023/11/25 10:02:05 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftp.h"

int	ft_printf(const char *s, ...)
{
	int		count;
	int		i;
	va_list	ap;

	count = 0;
	i = 0;
	if (!s)
		return (-1);
	va_start(ap, s);
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			count += ft_match_format(ap, s[i + 1]);
			if (s[i + 1] == '\0')
				count += ft_putchar('%');
			i += 2;
			continue ;
		}
		ft_putchar(s[i]);
		count++;
		i++;
	}
	return (count);
}

int	ft_match_format(va_list ap, char c)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (c == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (c == 'd' || c == 'i')
		count += ft_putnbr(va_arg(ap, int));
	else if (c == 'x' || (c == 'X') || (c == 'p'))
		count += print_hex(va_arg(ap, unsigned long int), c);
	else if (c == 'u')
		count += ft_putnbr_unsigned(va_arg(ap, unsigned int));
	else if (c == '%')
		count += ft_putchar('%');
	return (count);
}
