/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 02:35:28 by ytsyrend          #+#    #+#             */
/*   Updated: 2023/11/15 02:35:41 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

/*updates player movement and collectible interactions.*/
void	handle_lose(t_complete *game)
{
	ft_printf("\nYou lose!\n");
	exit_point(game);
}

void	handle_win(t_complete *game)
{
	ft_printf("\nAchievement unlocked!\n");
	exit_point(game);
}

void	move_player(t_complete *game, int i, int j)
{
	game->map[j][i] = 'P';
	game->x_axis = i;
	game->y_axis = j;
	game->counter++;
}

int	update_move(t_complete *game, int i, int j)
{
	if (game->map[j][i] == 'F')
	{
		handle_lose(game);
	}
	else if (game->map[j][i] == 'E')
	{
		if (game->collectables != 0)
			return (0);
		handle_win(game);
	}
	else if (game->map[j][i] == '0')
	{
		move_player(game, i, j);
	}
	else if (game->map[j][i] == 'C')
	{
		move_player(game, i, j);
		game->collectables--;
	}
	return (1);
}

/*user input for game controls and updates 
the game state accordingly*/
int	controls_working(int command, t_complete *game)
{
	int	works;

	works = 0;
	if (command == 65307)
		exit_point(game);
	else
	{
		works = controls_ws_working(command, game);
		if (!works)
			works = controls_ad_working(command, game);
	}
	if (works)
		adding_in_graphics(game);
	return (1);
}
