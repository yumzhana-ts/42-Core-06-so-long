/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 21:39:55 by ytsyrend          #+#    #+#             */
/*   Updated: 2023/09/05 21:39:59 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../headers/ft_printf.h"

/**prints string with values in differents formats*/
int	ft_printf(const char *string, ...)
{
	va_list	args_after_string;
	int		length;
	int		i;

	i = 0;
	length = 0;
	va_start(args_after_string, string);
	while (string[i] != '\0')
	{
		if (string[i] == '%' && ft_strchr("cspdiuxX%", string[i + 1]) != 0)
		{
			length += ft_choose_format(args_after_string, string[i + 1]);
			i++;
		}
		else
			length += ft_putchar(string[i]);
		i++;
	}
	va_end(args_after_string);
	return (length);
}
/**while loop counts lenght of string
 * 
*/

/**Použití "(nil)" je způsob, jak vizuálně označit, že pointer je NULL, 
 * místo toho, aby se tiskla jen nulová adresa, což může být méně čitelné 
 * pro lidi čtoucí výstup. Tento zpusob je u printf bezny*/
int	ft_choose_format(va_list args, const char format_char)
{
	unsigned long long	ptr;

	if (format_char == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (format_char == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (format_char == 'p')
	{
		ptr = va_arg(args, unsigned long long);
		if (ptr)
			return (ft_make_hexa(ptr, format_char));
		return (ft_putstr("(nil)"));
	}
	else if (format_char == 'd' || format_char == 'i')
		return (ft_printnmb(va_arg(args, int)));
	else if (format_char == 'u')
		return (ft_print_unsigned(va_arg(args, unsigned int)));
	else if (format_char == 'x' || format_char == 'X')
		return (ft_make_hexa(va_arg(args, unsigned int), format_char));
	else if (format_char == '%')
		return (ft_putchar('%'));
	else
		return (-1);
}

/*
int	main()
{
	void *pointer = malloc(1);
	//ft_printf("toto je pointer: %p \n a toto je znak: %c 
//			\n a toto je string: %s", pointer, "ca", "ahoj");
	// printf("%c \n",'T');
	// ft_printf("toto je cislo i: %i \n, a toto d: %d", 1523478, 4859);
	ft_printf("\n %i \n", ft_printf("%p", pointer));
	printf("\n %i \n\n", ft_printf("%p", pointer));

	ft_printf("\n %i \n", ft_printf("%c", 'S'));
	printf("\n %i \n\n", ft_printf("%c", 'S'));

	ft_printf("\n %i \n", ft_printf("%d", "pointer"));
	printf("\n %i \n\n", ft_printf("%d", "pointer"));
	
	ft_printf("\n %i \n", ft_printf("%c", 'p'));
	printf("\n %i \n\n", ft_printf("%c", 'p'));
	
	ft_printf("\n %i \n", ft_printf("%%"));
	printf("\n %i \n\n", ft_printf("%%"));

	ft_printf("\n %i \n", ft_printf("%d", 2147483647));
	printf("\n %i \n\n", ft_printf("ahoj %d, %p", 2147483647, pointer));

	ft_printf("\n %i \n", ft_printf("%a", 'p'));
	printf("\n %i \n\n", ft_printf("%a", 'p'));


	ft_printf("\n hexadecimal nmb %i \n", ft_printf("%x", -1563978));
	printf("\n %i \n\n", ft_printf("%x", -1563978));

	ft_printf("\n %i \n", ft_printf("%X", -1));
	printf("\n %i \n\n", ft_printf("%X", -1));

	ft_printf("toto je pointer: %p \n a toto je znak: %c \n 
	a toto je string: %s", pointer, 'c', "ahoj");

	return 0;
}*/
