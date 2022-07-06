/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_texture_helper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espyromi <espyromi@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 11:22:54 by espyromi          #+#    #+#             */
/*   Updated: 2022/06/27 11:26:18 by espyromi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	read_textures(t_window *mlx, t_data *data)
{
	data->texture_h = 300;
	data->texture_w = 300;
	data->tex_no.img = mlx_xpm_file_to_image(mlx->mlx, \
	data->texture_path[0], &(data->texture_w), &(data->texture_h));
	data->tex_so.img = mlx_xpm_file_to_image(mlx->mlx, \
	data->texture_path[1], &(data->texture_w), &(data->texture_h));
	data->tex_we.img = mlx_xpm_file_to_image(mlx->mlx, \
	data->texture_path[2], &(data->texture_w), &(data->texture_h));
	data->tex_ea.img = mlx_xpm_file_to_image(mlx->mlx, \
	data->texture_path[3], &(data->texture_w), &(data->texture_h));
	if (!data->tex_no.img || !data->tex_so.img || \
	!data->tex_we.img || !data->tex_ea.img)
		return (0);
	else
	{
		data->tex_no.data = (int *)mlx_get_data_addr(data->tex_no.img, \
		&data->tex_no.bpp, &data->tex_no.size_l, &data->tex_no.endian);
		data->tex_so.data = (int *)mlx_get_data_addr(data->tex_so.img, \
		&data->tex_so.bpp, &data->tex_so.size_l, &data->tex_so.endian);
		data->tex_we.data = (int *)mlx_get_data_addr(data->tex_we.img, \
		&data->tex_we.bpp, &data->tex_we.size_l, &data->tex_we.endian);
		data->tex_ea.data = (int *)mlx_get_data_addr(data->tex_ea.img, \
		&data->tex_ea.bpp, &data->tex_ea.size_l, &data->tex_ea.endian);
		return (1);
	}
}

int	map_tex_check(t_data *data, t_window *mlx, char *line, int tex_code)
{
	if (get_tex_values(data, line, tex_code) == 0)
		return (0);
	data->is_texture++;
	return (1);
}

int	get_tex_values(t_data *data, char *line, int tex_code)
{
	int		i;
	char	*tex_str;

	i = 0;
	tex_str = ft_calloc(ft_strlen(line), sizeof(char));
	if ((line[i] == 'N' && line[i + 1] == 'O') || (line[i] == 'S' \
	&& line[i + 1] == 'O') || (line[i] == 'E' && line[i + 1] == 'A') \
	|| (line[i] == 'W' && line[i + 1] == 'E'))
		i += 2;
	else
		return (0);
	while (line[i] != '\0')
	{
		if (line[i] == ' ')
			;
		else if (ft_isalnum(line[i]) || line[i] == '/' || line[i] == '.')
			tex_str = ft_strappend(tex_str, line[i]);
		i++;
	}
	data->texture_path[tex_code] = tex_str;
	return (1);
}
