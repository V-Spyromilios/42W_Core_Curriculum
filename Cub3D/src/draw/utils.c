/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espyromi <espyromi@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:00:21 by espyromi          #+#    #+#             */
/*   Updated: 2022/06/29 11:50:54 by espyromi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	to_coord(int width, double x, double y)
{
	int	ret;

	ret = (int)floor(y) * width + (int)floor(x);
	return (ret);
}

void	copy_coord(double from[2], double to[2])
{
	to[0] = from[0];
	to[1] = from[1];
}

void	create_coord(int xy[2], int x, int y)
{
	xy[0] = x;
	xy[1] = y;
}

int	sum_neighbours(t_window *mlx, int *data, double xy1[2])
{
	int	i;
	int	j;
	int	sum;

	sum = 0;
	i = -1;
	while (i < 2)
	{
		j = -1;
		while (j < 2)
		{
			if (data[to_coord(mlx->width, xy1[0] + i, xy1[1] + j)] == C_WALL)
				sum++;
			j++;
		}
		i++;
	}
	return (sum);
}

int	convert_color(int rgb[3])
{
	int	color;

	color = 65536 * rgb[0] + 256 * rgb[1] + rgb[2];
	return (color);
}
