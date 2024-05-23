/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 21:38:23 by ytsyrend          #+#    #+#             */
/*   Updated: 2023/09/05 21:44:49 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdio.h>
//<stdlib.h>: Tento hlavičkový soubor definuje funkce malloc a free, 
// a také definuje typ size_t.<unistd.h>: Tento hlavičkový soubor definuje
//  funkci read a také definuje typ ssize_t v rámci POSIX standardu.
# include <stdlib.h>
# include <unistd.h>
//# include <fcntl.h>
# include <stdarg.h>

int		ft_putchar(char c);
int		ft_putstr(char *s);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *string);
char	*ft_strchr(const char *s, int c);
int		ft_printf(const char *string, ...);
int		ft_make_hexa(unsigned long long int numbToMakeHexa, char format);
int		ft_choose_format(va_list args, const char format_char);
size_t	ft_wr_digits_recurse(unsigned long long int nbToHexa,
			const char *digits);
size_t	ft_len_digit_recurse(unsigned long long int nbToHexa,
			unsigned long long int lenDigits);
int		ft_printnmb(int nmb);
int		ft_print_unsigned(unsigned int n);

#endif
