/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espyromi <espyromi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 11:24:03 by espyromi          #+#    #+#             */
/*   Updated: 2022/06/28 21:34:10 by espyromi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	move_player(t_window *mlx, double xy[2], double dx, double dy)
{
	double	orient;

	orient = (mlx->player.orientation) * 0.0174532925;
	xy[0] += -sin(orient) * dx + cos(orient) * dy;
	xy[1] += cos(orient) * dx + sin(orient) * dy;
}

int	should_refresh(t_window *mlx)
{
	if (mlx->keys.up || mlx->keys.down || mlx->keys.right || mlx->keys.left
		|| mlx->keys.turn_left || mlx->keys.turn_right)
		return (1);
	else
		return (0);
}

int	check_keys(t_window *mlx)
{
	double	xy[2];

	if (mlx->keys.turn_left)
		mlx->player.orientation -= 3;
	if (mlx->keys.turn_right)
		mlx->player.orientation += 3;
	if (mlx->player.orientation < 0)
		mlx->player.orientation += 360;
	if (mlx->player.orientation >= 360)
		mlx->player.orientation -= 360;
	copy_coord(mlx->player.xy, xy);
	if (mlx->keys.up)
		move_player(mlx, xy, 0, 5);
	if (mlx->keys.left)
		move_player(mlx, xy, 5, 0);
	if (mlx->keys.down)
		move_player(mlx, xy, 0, -5);
	if (mlx->keys.right)
		move_player(mlx, xy, -5, 0);
	if ((mlx->keys.up || mlx->keys.down || mlx->keys.right || mlx->keys.left)
		&& !is_it_wall(mlx, xy))
		copy_coord(xy, mlx->player.xy);
	if (mlx->keys.end)
		exit_game(mlx);
	return (should_refresh(mlx));
}

int	handle_key_press(int key, t_window *mlx)
{
	if (key == UP)
		mlx->keys.up = 1;
	if (key == LEFT)
		mlx->keys.left = 1;
	if (key == DOWN)
		mlx->keys.down = 1;
	if (key == RIGHT)
		mlx->keys.right = 1;
	if (key == LARROW)
		mlx->keys.turn_left = 1;
	if (key == RARROW)
		mlx->keys.turn_right = 1;
	if (key == ESC)
		mlx->keys.end = 1;
	return (0);
}

int	handle_key_release(int key, t_window *mlx)
{
	if (key == UP)
		mlx->keys.up = 0;
	if (key == LEFT)
		mlx->keys.left = 0;
	if (key == DOWN)
		mlx->keys.down = 0;
	if (key == RIGHT)
		mlx->keys.right = 0;
	if (key == LARROW)
		mlx->keys.turn_left = 0;
	if (key == RARROW)
		mlx->keys.turn_right = 0;
	return (0);
}
