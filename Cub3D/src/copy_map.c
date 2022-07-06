/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espyromi <espyromi@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 11:23:26 by espyromi          #+#    #+#             */
/*   Updated: 2022/06/29 11:47:20 by espyromi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	cpy_map(t_window *mlx)
{
	int	x_col;
	int	y_row;

	y_row = 0;
	while (y_row < mlx->height)
	{
		x_col = 0;
		while (x_col < mlx->width)
		{
			mlx->img.data[to_coord(mlx->width, x_col, y_row)]
				= mlx->img.data_bg[to_coord(mlx->width, x_col, y_row)];
			x_col++;
		}
		y_row++;
	}
	draw_player(mlx, C_PLAYER);
}
