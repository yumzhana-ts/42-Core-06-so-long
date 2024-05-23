/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 21:39:34 by ytsyrend          #+#    #+#             */
/*   Updated: 2023/09/05 21:39:38 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../headers/ft_printf.h"

size_t	ft_strlen(const char *string)
{
	size_t	len;

	len = 0;
	while (*string)
	{
		len++;
		string++;
	}
	return (len);
}
