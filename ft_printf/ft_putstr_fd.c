/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 21:39:15 by ytsyrend          #+#    #+#             */
/*   Updated: 2023/09/05 21:39:19 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../headers/ft_printf.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}

//mozna bude potreba unsigned int
/*	lze i pouzit predchozi funkci; mozna bude potreba podminka if
if (!s)
	return ;
while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}*/
