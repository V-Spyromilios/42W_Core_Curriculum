/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espyromi <espyromi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 15:42:10 by espyromi          #+#    #+#             */
/*   Updated: 2022/06/28 21:31:00 by espyromi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	draw_line(t_window *mlx, double xy1[2], double xy2[2], int color)
{
	double	dx;
	double	dy;
	double	m;

	xy1[0] = floor(xy1[0]);
	xy1[1] = floor(xy1[1]);
	xy2[0] = floor(xy2[0]);
	xy2[1] = floor(xy2[1]);
	dx = xy2[0] - xy1[0];
	dy = xy2[1] - xy1[1];
	if (fabs(dx) > fabs(dy))
		m = fabs(dx);
	else
		m = fabs(dy);
	dx = dx / m;
	dy = dy / m;
	while (fabs(xy2[0] - xy1[0]) > 0.01 || fabs(xy2[1] - xy1[1]) > 0.01)
	{
		mlx->img.data[to_coord(mlx->width, xy1[0], xy1[1])] = color;
		xy1[0] += dx;
		xy1[1] += dy;
	}
}

void	draw_rectangle(t_window *mlx, int x, int y, int color)
{
	int	i;
	int	j;

	x *= mlx->img.tile_size;
	y *= mlx->img.tile_size;
	i = 0;
	while (i < mlx->img.tile_size)
	{
		j = 0;
		while (j < mlx->img.tile_size)
		{
			mlx->img.data[to_coord(mlx->width, x + j, y + i)] = color;
			mlx->img.data_bg[to_coord(mlx->width, x + j, y + i)] = color;
			j++;
		}
		i++;
	}
}

void	draw_player(t_window *mlx, int color)
{
	int	i;
	int	j;
	int	x;
	int	y;

	x = mlx->player.xy[0] - 1;
	y = mlx->player.xy[1] - 1;
	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			mlx->img.data[to_coord(mlx->width, x + j, y + i)] = color;
			j++;
		}
		i++;
	}
}

void	draw_map_line(t_window *mlx, char *line, int y_row, int x_col)
{
	while (x_col < mlx->width / mlx->img.tile_size)
	{
		if (line[x_col] == '1' || line[x_col] == ' ')
			draw_rectangle(mlx, x_col, y_row, C_WALL);
		else if (line[x_col] == '0')
			draw_rectangle(mlx, x_col, y_row, C_SPACE);
		else
		{
			mlx->player.xy[0] = x_col * mlx->img.tile_size
				+ mlx->img.tile_size / 2;
			mlx->player.xy[1] = y_row * mlx->img.tile_size
				+ mlx->img.tile_size / 2;
			if (line[x_col] == 'E')
				mlx->player.orientation = 0;
			else if (line[x_col] == 'S')
				mlx->player.orientation = 90;
			else if (line[x_col] == 'W')
				mlx->player.orientation = 180;
			else
				mlx->player.orientation = 270;
			draw_rectangle(mlx, x_col, y_row, C_SPACE);
			draw_player(mlx, C_PLAYER);
		}
		x_col++;
	}
}

void	draw_map(t_window *mlx)
{
	int		x_col;
	int		y_row;
	t_list	*act;
	char	*line;

	mlx->img.img = mlx_new_image(mlx->mlx, mlx->width, mlx->height);
	mlx->img.data = (int *)mlx_get_data_addr(mlx->img.img, &mlx->img.bpp,
			&mlx->img.size_l, &mlx->img.endian);
	mlx->img.img_bg = mlx_new_image(mlx->mlx, mlx->width, mlx->height);
	mlx->img.data_bg = (int *)mlx_get_data_addr(mlx->img.img_bg, &mlx->img.bpp,
			&mlx->img.size_l, &mlx->img.endian);
	y_row = 0;
	act = mlx->map;
	while (y_row < mlx->height / mlx->img.tile_size)
	{
		line = (char *) act->content;
		x_col = 0;
		draw_map_line(mlx, line, y_row, x_col);
		act = act->next;
		y_row++;
	}
}
