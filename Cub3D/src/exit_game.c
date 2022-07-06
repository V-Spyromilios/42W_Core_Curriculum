/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espyromi <espyromi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 17:44:09 by espyromi          #+#    #+#             */
/*   Updated: 2022/06/28 21:34:55 by espyromi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	throw_error(int error)
{
	if (error == 1)
		ft_printf("Error! mlx seems to suffer.\n");
	if (error == 2)
		ft_printf("Error! This map is not ok.\n");
	if (error == 3)
		ft_printf("Error! Use \".cub\" files only.\n");
	if (error == 4)
		ft_printf("Error while opening file.\n");
}

void	exit_game(t_window *mlx)
{
	if (mlx->map)
		ft_lstclear(&(mlx->map), free);
	free(mlx->screen.distance);
	free(mlx->screen.worient);
	free(mlx->screen.w_heights);
	free(mlx->screen.w_hits_xy);
	if (mlx->mlx)
	{
		if (mlx->mlx_win)
			mlx_destroy_window(mlx->mlx, mlx->mlx_win);
		mlx_loop_end(mlx->mlx);
		free(mlx->mlx);
	}
	exit(0);
}
