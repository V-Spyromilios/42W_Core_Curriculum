/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espyromi <espyromi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:46:41 by espyromi          #+#    #+#             */
/*   Updated: 2022/06/28 21:30:30 by espyromi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	initialize(t_window *mlx)
{
	ft_bzero(mlx, sizeof(t_window));
	initialize_with_zeros(mlx);
	mlx->img.tile_size = 50;
	mlx->height = 11 * mlx->img.tile_size;
	mlx->width = 15 * mlx->img.tile_size;
	mlx->screen.height = 480;
	mlx->screen.width = 854;
	mlx->screen.wall_height = 48000;
	mlx->screen.distance = (double *)malloc(mlx->screen.width
			* sizeof(double));
	mlx->screen.worient = (char *)malloc(mlx->screen.width
			* sizeof(char));
	mlx->screen.w_heights = (double *)malloc(mlx->screen.width
			* sizeof(double));
	mlx->screen.w_hits_xy = (double *)malloc(2 * mlx->screen.width
			* sizeof(double));
}

void	initialize_with_zeros(t_window *mlx)
{
	mlx->img.is_color = 0;
	mlx->img.is_texture = 0;
	mlx->img.lines_in_file = 0;
	mlx->img.lines_in_map = 0;
	mlx->img.line_len = 0;
	mlx->img.player = 0;
	mlx->img.curr_line = 0;
	mlx->map = 0;
	mlx->keys.up = 0;
	mlx->keys.down = 0;
	mlx->keys.left = 0;
	mlx->keys.right = 0;
	mlx->keys.turn_left = 0;
	mlx->keys.turn_right = 0;
	mlx->keys.end = 0;
}
