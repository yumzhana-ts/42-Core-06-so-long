/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_ad.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 02:34:35 by ytsyrend          #+#    #+#             */
/*   Updated: 2023/11/15 02:34:42 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

/*Checks for obstacles in the new position and updates the game state.
Updates the game map and prints information about the game state.
Returns 1 if the move is successful, 0 otherwise.*/
static int	move_horizontal(t_complete *game, int direction)
{
	int	x;
	int	y;
	int	k;

	x = game->x_axis + direction;
	y = game->y_axis;
	if (game->map[y][x] == '1')
		return (0);
	k = update_move(game, x, y);
	if (!k)
		return (0);
	if (direction < 0)
		game->map[y][x + 1] = '0';
	else
		game->map[y][x - 1] = '0';
	ft_printf("Steps Count: %i\n", game->counter);
	ft_printf("Remaining Hearts: %i\n", game->collectables);
	return (1);
}

static int	keyboard_a(t_complete *game)
{
	return (move_horizontal(game, -1));
}

static int	keyboard_d(t_complete *game)
{
	return (move_horizontal(game, 1));
}

/*processes keyboard input for 'A' and 'D' keys*/
int	controls_ad_working(int command, t_complete *game)
{
	int	works;

	works = 0;
	if (command == 97)
		works = keyboard_a(game);
	else if (command == 100)
		works = keyboard_d(game);
	return (works);
}
