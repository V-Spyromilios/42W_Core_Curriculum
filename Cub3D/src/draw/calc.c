/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espyromi <espyromi@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 21:21:20 by espyromi          #+#    #+#             */
/*   Updated: 2022/06/29 11:49:11 by espyromi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	calc_orientation(t_window *mlx, int texxy[2], int i, int j)
{
	if (round(j) >= 0 && round(j) < mlx->screen.height)
	{
		if (mlx->screen.worient[i] == 'N')
			mlx->screen.img.data[to_coord(mlx->screen.width, i, round(j))] \
			= mlx->img.tex_no.data[to_coord(mlx->img.texture_w, \
			texxy[0], texxy[1])];
		else if (mlx->screen.worient[i] == 'E')
			mlx->screen.img.data[to_coord(mlx->screen.width, i, round(j))] \
			= mlx->img.tex_ea.data[to_coord(mlx->img.texture_w, \
			texxy[0], texxy[1])];
		else if (mlx->screen.worient[i] == 'S')
			mlx->screen.img.data[to_coord(mlx->screen.width, i, round(j))] \
			= mlx->img.tex_so.data[to_coord(mlx->img.texture_w, \
			texxy[0], texxy[1])];
		else if (mlx->screen.worient[i] == 'W')
			mlx->screen.img.data[to_coord(mlx->screen.width, i, round(j))] \
			= mlx->img.tex_we.data[to_coord(mlx->img.texture_w, \
			texxy[0], texxy[1])];
	}
}

int	is_it_we(t_window *mlx, int *data, double *xy1, int s)
{
	if (data[to_coord(mlx->width, xy1[0] - 1, xy1[1])] != \
	data[to_coord(mlx->width, xy1[0] + 1, xy1[1])]
		&& data[to_coord(mlx->width, xy1[0] + s, xy1[1])] == C_WALL)
		return (1);
	else
		return (0);
}

double	calc_dist(t_window *mlx, double xy1[2], \
		char *w_orient, double p_orient)
{
	double	distant;
	double	dxy[2];
	int		*data;

	dxy[0] = xy1[0] - mlx->player.xy[0];
	dxy[1] = xy1[1] - mlx->player.xy[1];
	data = mlx->img.data_bg;
	distant = sqrt(pow(dxy[0], 2) + pow(dxy[1], 2));
	if (dxy[0] >= 0 && dxy[1] >= 0 && is_it_we(mlx, data, xy1, 1))
		*w_orient = 'W';
	else if (dxy[0] >= 0 && dxy[1] >= 0)
		*w_orient = 'N';
	else if (dxy[0] >= 0 && dxy[1] < 0 && is_it_we(mlx, data, xy1, 1))
		*w_orient = 'W';
	else if (dxy[0] >= 0 && dxy[1] < 0)
		*w_orient = 'S';
	else if (dxy[0] < 0 && dxy[1] >= 0 && is_it_we(mlx, data, xy1, -1))
		*w_orient = 'E';
	else if (dxy[0] < 0 && dxy[1] >= 0)
		*w_orient = 'N';
	else if (dxy[0] < 0 && dxy[1] < 0 && is_it_we(mlx, data, xy1, -1))
		*w_orient = 'E';
	else if (dxy[0] < 0 && dxy[1] < 0)
		*w_orient = 'S';
	return (distant);
}
