/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espyromi <espyromi@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 21:07:58 by espyromi          #+#    #+#             */
/*   Updated: 2022/06/29 11:50:28 by espyromi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	draw_screen_rectangle(t_window *mlx, int xy1[2], int xy2[2], int color)
{
	int	i;
	int	j;

	i = xy1[0];
	while (i < xy2[0])
	{
		j = xy1[1];
		while (j < xy2[1])
		{
			mlx->screen.img.data[to_coord(mlx->screen.width, i, j)] = color;
			j++;
		}
		i++;
	}
}

void	draw_screen_vertical(t_window *mlx, int x, int distance, int color)
{
	double	j;
	double	height;

	height = mlx->screen.w_heights[x];
	j = mlx->screen.height / 2 - height / 2;
	while (j < mlx->screen.height / 2 + height / 2)
	{
		mlx->screen.img.data[to_coord(mlx->screen.width, x, round(j))] = color;
		j++;
	}
}

void	draw_texture_on_wall(t_window *mlx, int i)
{
	double	wallxy[2];
	int		texxy[2];
	double	step;
	double	j;
	double	height;

	height = mlx->screen.w_heights[i];
	if (mlx->screen.worient[i] == 'N' || mlx->screen.worient[i] == 'S')
		wallxy[0] = mlx->screen.w_hits_xy[2 * i];
	else
		wallxy[0] = mlx->screen.w_hits_xy[2 * i + 1];
	wallxy[0] = fmod(wallxy[0], mlx->img.tile_size) / mlx->img.tile_size;
	texxy[0] = wallxy[0] * mlx->img.texture_w;
	step = 1.0 * mlx->img.texture_h / height;
	j = mlx->screen.height / 2 - height / 2;
	wallxy[1] = 0;
	while (j < mlx->screen.height / 2 + height / 2)
	{
		texxy[1] = (int)wallxy[1];
		if (texxy[1] > mlx->img.texture_h - 1)
			texxy[1] = mlx->img.texture_h - 1;
		wallxy[1] += step;
		calc_orientation(mlx, texxy, i, j);
		j++;
	}
}

void	draw_screen(t_window *mlx)
{
	int	xy1[2];
	int	xy2[2];
	int	i;

	mlx->screen.c_ceil = convert_color(mlx->img.c_ceil);
	mlx->screen.c_floor = convert_color(mlx->img.c_floor);
	create_coord(xy1, 0, 0);
	create_coord(xy2, mlx->screen.width, mlx->screen.height / 2);
	draw_screen_rectangle(mlx, xy1, xy2, mlx->screen.c_ceil);
	create_coord(xy1, 0, mlx->screen.height / 2);
	create_coord(xy2, mlx->screen.width, mlx->screen.height);
	draw_screen_rectangle(mlx, xy1, xy2, mlx->screen.c_floor);
	correct_rays(mlx);
	i = 0;
	while (i < mlx->screen.width)
	{
		draw_texture_on_wall(mlx, i);
		i++;
	}
}
