/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 02:36:32 by ytsyrend          #+#    #+#             */
/*   Updated: 2023/11/15 02:37:01 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

/*Place and updates the player's position in the game structure */
void	place_player(t_complete *game, int height, int width)
{
	mlx_put_image_to_window(game->mlxpointer,
		game->winpointer, game->player, width * 40, height * 40);
	game->y_axis = height;
	game->x_axis = width;
}

/*Places a collectible on the window at the specified position and increment*/
void	place_collectable(t_complete *game, int height, int width)
{
	mlx_put_image_to_window(game->mlxpointer,
		game->winpointer, game->collectable, width * 40, height * 40);
	game->collectables++;
}

/*Loads various images using XPM files into the game structure.*/
void	place_images_in_game(t_complete *game)
{
	int	i;
	int	j;

	game->floor = mlx_xpm_file_to_image(game->mlxpointer,
			"sprites/floor.xpm", &i, &j);
	game->barrier = mlx_xpm_file_to_image(game->mlxpointer,
			"sprites/wall.xpm", &i, &j);
	game->player = mlx_xpm_file_to_image(game->mlxpointer,
			"sprites/player.xpm", &i, &j);
	game->exit = mlx_xpm_file_to_image(game->mlxpointer,
			"sprites/exit.xpm", &i, &j);
	game->fire = mlx_xpm_file_to_image(game->mlxpointer,
			"sprites/fire.xpm", &i, &j);
	game->collectable = mlx_xpm_file_to_image(game->mlxpointer,
			"sprites/item.xpm", &i, &j);
}

/*Based on the type of element in the game map at a given position, 
it either places an image on the window 
or calls one of the placement functions.*/
void	process_graphics(t_complete *game, int height, int width)
{
	if (game->map[height][width] == '1')
		mlx_put_image_to_window(game->mlxpointer,
			game->winpointer, game->barrier, width * 40, height * 40);
	if (game->map[height][width] == 'C')
		place_collectable(game, height, width);
	if (game->map[height][width] == 'P')
		place_player(game, height, width);
	if (game->map[height][width] == 'E')
		mlx_put_image_to_window(game->mlxpointer,
			game->winpointer, game->exit, width * 40, height * 40);
	if (game->map[height][width] == 'F')
		mlx_put_image_to_window(game->mlxpointer,
			game->winpointer, game->fire, width * 40, height * 40);
	if (game->map[height][width] == '0')
		mlx_put_image_to_window(game->mlxpointer,
			game->winpointer, game->floor, width * 40, height * 40);
}

/*Iterates through the game map and calls to process graphics*/
void	adding_in_graphics(t_complete *game)
{
	int	height;
	int	width;

	game->collectables = 0;
	height = 0;
	while (height < game->heightmap)
	{
		width = 0;
		while (game->map[height][width])
		{
			process_graphics(game, height, width);
			width++;
		}
		height++;
	}
}
