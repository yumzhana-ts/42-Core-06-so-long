/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_hexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 21:36:26 by ytsyrend          #+#    #+#             */
/*   Updated: 2023/09/05 21:36:32 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../headers/ft_printf.h"

/** the function writes digits and returns the value that represent amount 
 * of printed digits*/
size_t	ft_wr_digits_recurse(unsigned long long int nbToHexa,
		const char *digits)
{
	if (nbToHexa >= 16)
	{
		ft_wr_digits_recurse(nbToHexa / 16, digits);
		ft_wr_digits_recurse(nbToHexa % 16, digits);
	}
	else
		write(1, &digits[nbToHexa], 1);
	return (ft_len_digit_recurse(nbToHexa, 16));
}

/** return the amount of digits printed*/
size_t	ft_len_digit_recurse(unsigned long long int nbToHexa,
		unsigned long long int lenDigits)
{
	size_t	i;

	i = 1;
	while (nbToHexa >= lenDigits)
	{
		nbToHexa /= lenDigits;
		i++;
	}
	return (i);
}

/**funtion prints the number and returns the length 
 * of hexadecimal number or adress*/
int	ft_make_hexa(unsigned long long int numbToMakeHexa, char format)
{
	char	*digits;
	int		len_nbr;

	len_nbr = 0;
	if (format == 'p')
		len_nbr += (int)write(1, "0x", 2);
	if (format == 'X')
		digits = "0123456789ABCDEF";
	else
		digits = "0123456789abcdef";
	len_nbr += ft_wr_digits_recurse(numbToMakeHexa, digits);
	return (len_nbr);
}
