/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_ws.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 02:35:01 by ytsyrend          #+#    #+#             */
/*   Updated: 2023/11/15 02:35:07 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

/*Checks for obstacles in the new position and updates the game state.
Updates the game map and prints information about the game state.
Returns 1 if the move is successful, 0 otherwise.*/
static int	move_vertical(t_complete *game, int direction)
{
	int	x;
	int	y;
	int	k;

	x = game->x_axis;
	y = game->y_axis + direction;
	if (game->map[y][x] == '1')
		return (0);
	k = update_move(game, x, y);
	if (!k)
		return (0);
	if (direction < 0)
		game->map[y + 1][x] = '0';
	else
		game->map[y - 1][x] = '0';
	ft_printf("Steps Count: %i\n", game->counter);
	ft_printf("Remaining Hearts: %i\n", game->collectables);
	return (1);
}

static int	keyboard_w(t_complete *game)
{
	return (move_vertical(game, -1));
}

static int	keyboard_s(t_complete *game)
{
	return (move_vertical(game, 1));
}

/*processes keyboard input for 'W' and 'S' keys*/
int	controls_ws_working(int command, t_complete *game)
{
	int	works;

	works = 0;
	if (command == 119)
		works = keyboard_w(game);
	if (command == 115)
		works = keyboard_s(game);
	return (works);
}
