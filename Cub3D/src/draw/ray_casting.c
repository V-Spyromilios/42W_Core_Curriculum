/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espyromi <espyromi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 21:20:02 by espyromi          #+#    #+#             */
/*   Updated: 2022/06/28 21:31:07 by espyromi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	is_it_wall(t_window *mlx, double xy[2])
{
	int	i;
	int	j;
	int	sum;

	if (mlx->img.data_bg[to_coord(mlx->width, xy[0], xy[1])] == C_WALL)
		return (1);
	i = -1;
	while (i < 2)
	{
		j = -1;
		while (j < 2)
		{
			if (mlx->img.data_bg[to_coord(mlx->width, \
			xy[0] + i, xy[1] + j)] == C_WALL)
			{
				xy[0] = xy[0] + i;
				xy[1] = xy[1] + j;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

char	cast_till_wall(t_window *mlx, double xy1[2], double orientation)
{
	double	xy2[2];
	char	hv;

	copy_coord(mlx->player.xy, xy1);
	while (xy1[0] > 0 && xy1[1] > 0 && xy1[0] < mlx->width
		&& xy1[1] < mlx->height && !is_it_wall(mlx, xy1))
	{
		hv = get_next_point(mlx, xy1, xy2, orientation);
		copy_coord(xy2, xy1);
	}
	return (hv);
}

void	draw_fov(t_window *mlx, double xy1[2], char *wall_orientation)
{
	double	xy0[2];

	copy_coord(mlx->player.xy, xy0);
	if (xy1[0] > 0 && xy1[1] > 0 && xy1[0] < mlx->width
		&& xy1[1] < mlx->height)
	{
		if (*wall_orientation == 'N')
			draw_line(mlx, xy0, xy1, C_RAY_N);
		else if (*wall_orientation == 'E')
			draw_line(mlx, xy0, xy1, C_RAY_E);
		else if (*wall_orientation == 'S')
			draw_line(mlx, xy0, xy1, C_RAY_S);
		else if (*wall_orientation == 'W')
			draw_line(mlx, xy0, xy1, C_RAY_W);
	}
}

void	correct_rays(t_window *mlx)
{
	int		i;

	i = 0;
	while (i < mlx->screen.width)
	{
		if (mlx->screen.distance[i] < 0.001)
			mlx->screen.distance[i] = 0.001;
		mlx->screen.w_heights[i] = mlx->screen.wall_height / \
		(mlx->screen.distance[i]);
		i++;
	}
}

void	ray_cast(t_window *mlx)
{
	double	xy1[2];
	double	orient;
	char	wall_orient;
	int		turn;

	turn = 0;
	orient = mlx->player.orientation - 45;
	if (orient < 0)
		orient += 360;
	while (turn++ < mlx->screen.width)
	{
		wall_orient = cast_till_wall(mlx, xy1, orient);
		mlx->screen.distance[turn] = calc_dist(mlx, xy1, &wall_orient, orient);
		mlx->screen.worient[turn] = wall_orient;
		mlx->screen.w_hits_xy[2 * turn] = xy1[0];
		mlx->screen.w_hits_xy[2 * turn + 1] = xy1[1];
		draw_fov(mlx, xy1, &wall_orient);
		orient += (90.0 / mlx->screen.width);
		if (orient >= 360.0)
			orient -= 360.0;
	}
}
