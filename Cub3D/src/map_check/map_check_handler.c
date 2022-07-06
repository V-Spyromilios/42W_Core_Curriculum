/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espyromi <espyromi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:08:56 by espyromi          #+#    #+#             */
/*   Updated: 2022/06/28 20:51:05 by espyromi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	check_line_content(char *line, t_data *data, t_window *mlx)
{
	int	is_valid;

	is_valid = 0;
	if (line[0] == 'N' && line[1] == 'O')
		is_valid = map_tex_check(data, mlx, line, 0);
	else if (line[0] == 'S' && line[1] == 'O')
		is_valid = map_tex_check(data, mlx, line, 1);
	else if (line[0] == 'W' && line[1] == 'E')
		is_valid = map_tex_check(data, mlx, line, 2);
	else if (line[0] == 'E' && line[1] == 'A')
		is_valid = map_tex_check(data, mlx, line, 3);
	else if (line[0] == 'F')
		is_valid = map_color_check(data, line, 0);
	else if (line[0] == 'C')
		is_valid = map_color_check(data, line, 1);
	return (is_valid);
}

int	check_game_components(char *line, t_data *data)
{
	if (*line != '1' && *line != ' ')
		return (0);
	line++;
	while (*line && *line != '\n')
	{
		if (*line == 'N' || *line == 'E' || *line == 'S' || *line == 'W')
			data->player += 1;
		else if (*line == '0' || *line == '1' || *line == ' ')
			;
		else
			return (0);
		line++;
	}
	if (*(line - 1) != '1' && *(line - 1) != ' ')
		return (0);
	return (1);
}

int	free_map_arr(int nr_of_lines, char **map_arr)
{
	int	i;

	i = 0;
	while (i < nr_of_lines)
	{
		free(map_arr[i]);
		i++;
	}
	free(map_arr);
	return (0);
}

int	is_map_valid(t_window *mlx, t_data *data, t_list **map)
{
	char	**map_arr;

	if (!read_textures(mlx, data))
	{
		return (0);
	}
	map_arr = convert_map_to_arr(map, data->lines_in_map);
	if (map_arr == NULL)
		return (0);
	if (closed_map_check(map, data->lines_in_map, map_arr) == 0)
	{
		free_map_arr(data->lines_in_map, map_arr);
		return (0);
	}
	if (data->player != 1)
	{
		free_map_arr(data->lines_in_map, map_arr);
		return (0);
	}
	free_map_arr(data->lines_in_map, map_arr);
	return (1);
}

int	check_fd(int fd)
{
	if (fd < 0 || fd > MAX_FD)
	{
		throw_error(4);
		return (0);
	}
	return (1);
}
