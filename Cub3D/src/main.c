/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espyromi <espyromi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:46:46 by espyromi          #+#    #+#             */
/*   Updated: 2022/06/28 22:00:14 by espyromi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	create_map(int fd, t_window *mlx)
{
	char	*line;

	line = get_next_line(fd);
	while (line != NULL)
	{
		ft_lstadd_back(&(mlx->map), ft_lstnew(line));
		line = get_next_line(fd);
	}
}

int	refresh_win(t_window *mlx)
{
	cpy_map(mlx);
	ray_cast(mlx);
	draw_screen(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->screen.img.img, 0, 0);
	return (0);
}

int	handle_loop(t_window *mlx)
{
	int	refresh;

	refresh = check_keys(mlx);
	if (refresh)
		refresh_win(mlx);
	return (0);
}

void	start_game(t_window *mlx)
{
	mlx->screen.c_ceil = convert_color(mlx->img.c_ceil);
	mlx->screen.c_floor = convert_color(mlx->img.c_floor);
	mlx->height = ft_lstsize(mlx->map) * mlx->img.tile_size;
	mlx->width = (ft_strlen(mlx->map->content) - 1) * mlx->img.tile_size;
	mlx->screen.img.img = mlx_new_image(mlx->mlx, mlx->screen.width,
			mlx->screen.height);
	mlx->screen.img.data = (int *)mlx_get_data_addr(mlx->screen.img.img,
			&mlx->screen.img.bpp, &mlx->screen.img.size_l,
			&mlx->screen.img.endian);
	mlx->mlx_win = mlx_new_window(mlx->mlx, mlx->screen.width, \
	mlx->screen.height, "_Βαγγέλης_");
	draw_map(mlx);
	ray_cast(mlx);
	draw_screen(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->screen.img.img, 0, 0);
	mlx_key_hook(mlx->mlx_win, handle_key_press, (void *)mlx);
	mlx_hook(mlx->mlx_win, 2, 1L << 0, handle_key_press, mlx);
	mlx_hook(mlx->mlx_win, 3, 1L << 1, handle_key_release, mlx);
	mlx_hook(mlx->mlx_win, 17, 1L << 17, exit_game, mlx);
	mlx_hook(mlx->mlx_win, 15, 1L << 16, refresh_win, mlx);
	refresh_win(mlx);
	mlx_loop_hook(mlx->mlx, handle_loop, mlx);
	mlx_loop(mlx->mlx);
	exit_game(mlx);
}

int	main(int argc, char **argv)
{
	t_window	mlx;
	int			fd;
	int			n_of_lines;

	if (argc == 2)
	{
		mlx.map = 0;
		mlx.img.tile_size = 100;
		fd = open(argv[1], O_RDONLY);
		if (!check_fd(fd) || !check_file_extension(argv[1]))
			return (0);
		initialize(&mlx);
		mlx.img.lines_in_file = count_lines_in_file(argv[1]);
		mlx.mlx = mlx_init();
		if (!mlx.mlx)
		{
			throw_error(1);
			exit_game(&mlx);
		}
		if (!map_check(fd, &(mlx.map), &(mlx.img), &mlx))
			exit_game(&mlx);
		start_game(&mlx);
		return (0);
	}
	return (0);
}
