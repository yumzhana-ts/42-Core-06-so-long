/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 14:45:00 by ytsyrend          #+#    #+#             */
/*   Updated: 2023/09/29 15:42:07 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*concatenated;
	char	*result;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	concatenated = (char *)malloc((len_s1 + len_s2 + 1) * sizeof(char));
	result = concatenated;
	if (result == NULL)
		return (result);
	if (s1)
	{
		while (*s1)
			*concatenated++ = *s1++;
	}
	if (s2)
	{
		while (*s2)
			*concatenated++ = *s2++;
	}
	*concatenated = '\0';
	return (result);
}

size_t	ft_strlen(const char *string)
{
	size_t	len;

	len = 0;
	if (!string)
		return (0);
	while (*string)
	{
		len++;
		string++;
	}
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}
