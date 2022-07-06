/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espyromi <espyromi@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 11:19:55 by espyromi          #+#    #+#             */
/*   Updated: 2022/06/29 11:51:43 by espyromi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	free_str(char *str, int ret)
{
	free(str);
	return (ret);
}

int	is_inner_game_char(char c)
{
	if (c != '0' && c != 'N' && c != 'S' \
	&& c != 'W' && c != 'E' && c != '1')
		return (0);
	return (1);
}

char	**convert_map_to_arr(t_list **map, int total_lines)
{
	t_list	*iterator;
	char	*tmp_str;
	char	**map_arr;
	int		i;
	int		j;

	iterator = *map;
	map_arr = ft_calloc(total_lines, sizeof(char *));
	i = 0;
	while (iterator != NULL)
	{
		tmp_str = (char *)iterator->content;
		map_arr[i] = ft_calloc(ft_strlen(tmp_str), sizeof(char));
		j = 0;
		while (tmp_str[j] != '\n' && tmp_str[j] != '\0')
		{
			map_arr[i][j] = tmp_str[j];
			j++;
		}
		iterator = iterator->next;
		i++;
	}
	return (map_arr);
}

int	is_zero_enclosed(char **map_arr, int i, int j)
{
	if (is_inner_game_char(map_arr[i][j + 1]) == 0)
		return (0);
	else if (is_inner_game_char(map_arr[i][j - 1]) == 0)
		return (0);
	else if (is_inner_game_char(map_arr[i + 1][j]) == 0)
		return (0);
	else if (is_inner_game_char(map_arr[i - 1][j]) == 0)
		return (0);
	else
		return (1);
}

int	closed_map_check(t_list **map, int total_lines, char **map_arr)
{
	int		i;
	int		j;
	int		line_len;

	i = 0;
	line_len = 0;
	while (i < total_lines)
	{
		j = 0;
		line_len = ft_strlen(map_arr[i]);
		while (map_arr[i][j])
		{
			if (map_arr[i][j] == '0')
			{
				if (i == 0 || j == 0 || i == total_lines || j == (line_len - 1))
					return (0);
				if (is_zero_enclosed(map_arr, i, j) == 0)
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
