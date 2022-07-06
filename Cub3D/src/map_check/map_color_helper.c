/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_color_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espyromi <espyromi@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 11:20:35 by espyromi          #+#    #+#             */
/*   Updated: 2022/06/29 11:52:05 by espyromi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	map_color_check(t_data *data, char *line, int color_code)
{
	if (!line)
		return (0);
	if (color_code == 0)
	{
		if (get_floor_rgb_values(data, line) != 3)
			return (0);
		data->is_color++;
	}
	else if (color_code == 1)
	{
		if (get_ceil_rgb_values(data, line) != 3)
			return (0);
		data->is_color++;
	}
	return (1);
}

int	get_floor_rgb_values(t_data *data, char *line)
{
	int		i;
	char	*digit_str;
	int		index;

	i = 0;
	index = 0;
	digit_str = ft_calloc(ft_strlen(line), sizeof(char));
	while (line[i] != '\0')
	{
		if ((i == 0 && line[i] == 'F') || line[i] == ' ')
			;
		else if (ft_isdigit(line[i]))
			digit_str = ft_strappend(digit_str, line[i]);
		else if (line[i] == ',' || line[i] == '\n')
		{
			if (store_floor_rgb_values(data, digit_str, index) == 0)
				return (free_str(digit_str, 0));
			digit_str[0] = '\0';
			index++;
		}
		else
			return (free_str(digit_str, 0));
		i++;
	}
	return (free_str(digit_str, index));
}

int	store_floor_rgb_values(t_data *data, char *digit_str, int index)
{
	int	nbr;

	nbr = 0;
	if (!digit_str || ft_strlen(digit_str) == 0)
		return (0);
	nbr = ft_atoi(digit_str);
	if (nbr < 0 || nbr > 255)
		return (0);
	data->c_floor[index] = nbr;
	return (1);
}

int	get_ceil_rgb_values(t_data *data, char *line)
{
	int		i;
	char	*digit_str;
	int		index;

	i = 0;
	index = 0;
	digit_str = ft_calloc(ft_strlen(line), sizeof(char));
	while (line[i] != '\0')
	{
		if ((i == 0 && line[i] == 'C') || line[i] == ' ')
			;
		else if (ft_isdigit(line[i]))
			digit_str = ft_strappend(digit_str, line[i]);
		else if (line[i] == ',' || line[i] == '\n')
		{
			if (store_ceil_rgb_values(data, digit_str, index) == 0)
				return (free_str(digit_str, 0));
			digit_str[0] = '\0';
			index++;
		}
		else
			return (free_str(digit_str, 0));
		i++;
	}
	return (free_str(digit_str, index));
}

int	store_ceil_rgb_values(t_data *data, char *digit_str, int index)
{
	int	nbr;

	nbr = 0;
	if (!digit_str || ft_strlen(digit_str) == 0)
		return (0);
	nbr = ft_atoi(digit_str);
	if (nbr < 0 || nbr > 255)
		return (0);
	data->c_ceil[index] = nbr;
	return (1);
}
