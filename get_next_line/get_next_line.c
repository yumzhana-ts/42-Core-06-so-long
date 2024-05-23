/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 14:44:46 by ytsyrend          #+#    #+#             */
/*   Updated: 2023/09/29 15:56:31 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <fcntl.h>

char	*get_read_line(int fd, char *memory)
{
	ssize_t	bytes_read;
	char	*buffer;
	char	*temp;

	bytes_read = 1;
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof (char));
	if (!buffer)
		return (NULL);
	while (bytes_read > 0 && ft_strchr(memory, '\n') == 0)
	{
		temp = memory;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		memory = ft_strjoin(memory, buffer);
		free(temp);
	}
	free(buffer);
	return (memory);
}

char	*get_line(char *memory)
{
	int		i;
	char	*next_line;

	i = 0;
	if (!*memory)
		return (NULL);
	while (memory[i] != '\n' && memory[i])
		i++;
	next_line = malloc(sizeof (char) * (i + 2));
	if (!next_line)
		return (NULL);
	i = 0;
	while (memory[i] != '\n' && memory[i])
	{
		next_line[i] = memory[i];
		i++;
	}
	if (memory[i] == '\n')
	{
		next_line[i] = memory[i];
		i++;
	}
	next_line[i] = '\0';
	return (next_line);
}

char	*get_over_line(char *memory)
{
	char	*new_line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (memory[i] != '\n' && memory[i])
		i++;
	if (!memory[i])
	{
		free(memory);
		return (NULL);
	}
	new_line = malloc((ft_strlen(memory) - i + 1) * sizeof(char));
	if (!new_line)
		return (NULL);
	i++;
	while (memory[i])
		new_line[j++] = memory[i++];
	new_line[j] = '\0';
	free(memory);
	return (new_line);
}

char	*get_next_line(int fd)
{
	static char	*memory = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	memory = get_read_line(fd, memory);
	if (!memory)
		return (NULL);
	line = get_line(memory);
	memory = get_over_line(memory);
	return (line);
}
