/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:40:46 by ytsyrend          #+#    #+#             */
/*   Updated: 2023/11/14 17:40:50 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include "get_next_line.h"
# include "../minilibx/mlx.h"
# include "../headers/ft_printf.h"

typedef struct t_start
{
	int		fd;
	int		heightmap;
	int		widthmap;
	int		playercount;
	int		columncount;
	int		exitcount;
	int		x_axis;
	int		y_axis;
	int		counter;
	int		collectables;

	char	**map;

	void	*floor;
	void	*barrier;
	void	*player;
	void	*exit;
	void	*fire;
	void	*collectable;
	void	*mlxpointer;
	void	*winpointer;

}	t_complete;

int			update_move(t_complete *game, int i, int j);
int			exit_point(t_complete *game);
int			map_reading(t_complete *game, char **argv);
int			controls_working(int command, t_complete *game);
int			controls_ad_working(int command, t_complete *game);
int			controls_ws_working(int command, t_complete *game);
void		adding_in_graphics(t_complete *game);
void		process_graphics(t_complete *game, int height, int width);
void		place_images_in_game(t_complete *game);
void		check_errors(t_complete *game);
void		character_valid(t_complete *game);
void		count_checker(t_complete *game, int height, int width);
void		if_walls(t_complete *game);
int			verticalwall(t_complete *game);
int			horizontalwall(t_complete *game);

#endif
