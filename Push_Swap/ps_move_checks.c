/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_move_checks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espyromi <espyromi@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 12:54:06 by espyromi          #+#    #+#             */
/*   Updated: 2021/11/09 18:03:49 by espyromi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(int *poi)
{
	free (poi);
	write(1, "Error\n", 6);
	exit(-1);
}

void	move_all_up(int *arr, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		arr[i] = arr[i + 1];
		i++;
	}
	arr[len] = 0;
}

void	move_all_down(int *stack, int len) //Works OK
{
	int	i;
	i = len;
	if (!stack[0])  //return if stack_b empty
		return;
	while (i >= 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
}

int		check_duplicate(int *arr)
{
	int	i;
	int	j;
	
	i = 0;
	j = 1;
	while(arr[i] != '\0')
	{
		j = i + 1;
		while (arr[j] != '\0')
		{
			if (arr[i] == arr[j])
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

void	check_input(int *arr, int len)
{
	int		i;

	i = 0;
	if (check_duplicate(arr) == -1)
		error_exit(arr);
	while (len > 0)
	{
		if (arr[i] > 2147483647 || arr[i] < -2147483648)
			error_exit(arr);
		len --;
		i++;
	}
}
