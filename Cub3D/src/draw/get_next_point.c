/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_point.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espyromi <espyromi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 21:20:27 by espyromi          #+#    #+#             */
/*   Updated: 2022/06/28 21:30:56 by espyromi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

char	gnp_special_orientations(
	t_window *mlx, double xy1[2], double dxy1[2], double orient)
{
	if (orient == 0 || orient == 180)
	{
		dxy1[0] = (int) floor(xy1[0]) % mlx->img.tile_size;
		if (orient == 0)
			dxy1[0] = mlx->img.tile_size - dxy1[0];
		else if (dxy1[0] == 0)
			dxy1[0] = -mlx->img.tile_size;
		else
			dxy1[0] = -dxy1[0];
		dxy1[1] = 0;
		return ('h');
	}
	else
	{
		dxy1[0] = 0;
		dxy1[1] = (int) floor(xy1[1]) % mlx->img.tile_size;
		if (orient == 90)
			dxy1[1] = mlx->img.tile_size - dxy1[1];
		else if (dxy1[1] == 0)
			dxy1[1] = -mlx->img.tile_size;
		else
			dxy1[1] = -dxy1[1];
		return ('v');
	}
}

char	gnp_other_dxy(
	t_window *mlx, double xy1[2], double dxy1[2], double orient)
{
	double	dxy2[2];

	if (orient > 0 && orient < 180)
		dxy2[1] = mlx->img.tile_size - (int) ceil(xy1[1]) % mlx->img.tile_size;
	else
	{
		dxy2[1] = -(int) floor(xy1[1]) % mlx->img.tile_size;
		if (dxy2[1] == 0)
			dxy2[1] = -mlx->img.tile_size;
	}
	dxy2[0] = dxy2[1] / tan(orient * 0.0174532925);
	if (!(fabs(dxy1[0] * dxy1[1]) < fabs(dxy2[0] * dxy2[1]))
		&& dxy1[1] != 0 && dxy1[0] != 0)
	{
		dxy1[0] = dxy2[0];
		dxy1[1] = dxy2[1];
		return ('v');
	}
	else
		return ('h');
}

char	get_next_point(t_window *mlx,
	double xy1[2], double xy2[2], double orient)
{
	double	dxy1[2];
	char	hv;

	if (orient == 0 || orient == 90 || orient == 180 || orient == 270)
		hv = gnp_special_orientations(mlx, xy1, dxy1, orient);
	else
	{
		if (orient > 90 && orient < 270)
		{
			dxy1[0] = -(int) floor(xy1[0]) % mlx->img.tile_size;
			if (dxy1[0] == 0)
				dxy1[0] = -mlx->img.tile_size;
		}
		else
			dxy1[0] = mlx->img.tile_size
				- (int) ceil(xy1[0]) % mlx->img.tile_size;
		dxy1[1] = dxy1[0] * tan(orient * 0.0174532925);
		hv = gnp_other_dxy(mlx, xy1, dxy1, orient);
	}
	xy2[0] = xy1[0] + dxy1[0];
	xy2[1] = xy1[1] + dxy1[1];
	return (hv);
}
