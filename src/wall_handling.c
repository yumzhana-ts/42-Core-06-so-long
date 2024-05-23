/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 02:37:46 by ytsyrend          #+#    #+#             */
/*   Updated: 2023/11/15 02:37:50 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

/*Checks if the first and last rows of the map 
contain walls ('1'), returning 0 if not, and 1 otherwise.*/
int	horizontalwall(t_complete *game)
{
	int	i;
	int	j;

	i = game->widthmap;
	j = 0;
	while (j < i)
	{
		if (game->map[0][i] == '1' && game->map[game->heightmap - 1][j] == '1')
			return (0);
		j++;
	}
	return (1);
}

/*Checks if the first and last columns of the map 
contain walls ('1'), returning 0 if not, and 1 otherwise.*/
int	verticalwall(t_complete *game)
{
	int	height;
	int	width;

	height = 0;
	width = game->widthmap;
	while (height < game->heightmap)
	{
		if (!(game->map[height][0] == '1' && game->map \
		[height][width - 1] == '1'))
			return (0);
		height++;
	}
	return (1);
}

/*If either horizontal or vertical walls are missing, 
prints an error message, then exits the program using exit_point.*/
void	if_walls(t_complete *game)
{
	int	verticalwalls;
	int	horizontalwalls;

	verticalwalls = verticalwall(game);
	horizontalwalls = horizontalwall(game);
	if (!verticalwalls || !horizontalwalls)
	{
		ft_printf("Error\nThe map is missing walls.\n");
		exit_point(game);
	}
}
