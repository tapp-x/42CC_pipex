/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:59:49 by tappourc          #+#    #+#             */
/*   Updated: 2023/11/25 10:02:05 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftp.h"

int	print_hex(unsigned long int nb, char choice)
{
	int	count;

	count = 0;
	if (choice == 'x')
		count = (print_hex_low(nb));
	if (choice == 'X')
		count = (print_hex_up(nb));
	if (choice == 'p')
	{
		if (nb != 0)
		{
			ft_putstr("0x");
			count += 2;
		}
		count += (print_hex_ptr(nb));
	}
	return (count);
}

int	print_hex_low(unsigned int nb)
{
	char	*base;
	int		count;

	count = 0;
	base = "0123456789abcdef";
	if (nb >= 16)
		count += print_hex_low(nb / 16);
	count += ft_putchar(base[nb % 16]);
	return (count);
}

int	print_hex_ptr(unsigned long int nb)
{
	char	*base;
	int		count;

	count = 0;
	base = "0123456789abcdef";
	if (nb == 0)
	{
		ft_putstr("(nil)");
		count = 5;
		return (count);
	}
	if (nb >= 16)
		count += print_hex_ptr(nb / 16);
	count += ft_putchar(base[nb % 16]);
	return (count);
}

int	print_hex_up(unsigned int nb)
{
	char	*base;
	int		count;

	count = 0;
	base = "0123456789ABCDEF";
	if (nb >= 16)
		count += print_hex_up(nb / 16);
	count += ft_putchar(base[nb % 16]);
	return (count);
}
