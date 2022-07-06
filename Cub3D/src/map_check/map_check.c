/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espyromi <espyromi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:46:56 by espyromi          #+#    #+#             */
/*   Updated: 2022/06/28 21:06:12 by espyromi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	is_empty_line(char *line)
{
	int	i;

	i = 0;
	if (!line || line[i] == '\n')
		return (1);
	while (line[i] != '\0')
	{
		if (line[i] != ' ' || line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int	count_lines_in_file(char *file)
{
	char	*line;
	int		fd;
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd <= 0 || fd > MAX_FD)
		return (0);
	line = get_next_line(fd);
	i++;
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	free(line);
	return (i);
}

int	check_file_extension(char *filename)
{
	char	*file_ending;

	if (!filename)
		return (0);
	file_ending = ft_substr(filename, ft_strlen(filename) - 4, 4);
	file_ending[4] = '\0';
	if (ft_strncmp(file_ending, ".cub", 5) != 0)
	{
		throw_error(3);
		free(file_ending);
		return (0);
	}
	free(file_ending);
	return (1);
}

int	readin_map(t_list **map, t_data *data, t_window *mlx, char *line)
{
	if (is_empty_line(line) == 1)
	{
		free(line);
		data->curr_line++;
	}
	else if (check_line_content(line, data, mlx) == 1)
	{
		free(line);
		data->curr_line++;
	}
	else if (check_game_components(line, data) == 1 && \
		data->is_texture == 4 && data->is_color == 2)
	{
		ft_lstadd_back(map, ft_lstnew(line));
		data->curr_line++;
		data->lines_in_map++;
	}
	else
	{
		free(line);
		return (0);
	}
	return (1);
}

int	map_check(int fd, t_list **map, t_data *data, t_window *mlx)
{
	char	*line;

	line = get_next_line(fd);
	while (data->curr_line < data->lines_in_file)
	{
		if (data->curr_line > 0)
			line = get_next_line(fd);
		if (readin_map(map, data, mlx, line) == 0)
		{
			throw_error(2);
			return (0);
		}
	}
	close(fd);
	if (is_map_valid(mlx, data, map) == 0)
	{
		throw_error(2);
		return (0);
	}
	return (1);
}
