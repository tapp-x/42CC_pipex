/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:32:08 by tappourc          #+#    #+#             */
/*   Updated: 2023/11/25 10:02:05 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftp.h"

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		count += 11;
		return (count);
	}
	if (n < 0)
	{
		count += ft_putchar('-');
		n = n * -1;
	}
	if (n >= 10)
	{
		count += ft_putnbr(n / 10);
		count += ft_putchar((n % 10) + 48);
	}
	else
		count += ft_putchar(n + 48);
	return (count);
}
