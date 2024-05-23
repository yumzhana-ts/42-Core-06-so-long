/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnmb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 21:40:24 by ytsyrend          #+#    #+#             */
/*   Updated: 2023/09/05 21:40:30 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../headers/ft_printf.h"

int	ft_print_unsigned(unsigned int n)
{
	int	size;

	size = 0;
	if (n == 0)
		size += ft_putchar('0');
	else
	{
		if (n / 10 != 0)
			ft_print_unsigned(n / 10);
		ft_putchar((n % 10) + '0');
		while (n > 0)
		{
			n /= 10;
			size++;
		}
	}
	return (size);
}

int	ft_printnmb(int nmb)
{
	int	size;

	size = 0;
	if (nmb == 0)
		size += ft_putchar('0');
	if (nmb == -2147483648)
	{
		size += ft_putstr("-2147483648");
		return (size);
	}
	if (nmb < 0)
	{
		size += ft_putchar('-');
		nmb = -nmb;
	}
	if (nmb > 0)
		size += ft_print_unsigned((unsigned int)nmb);
	return (size);
}
