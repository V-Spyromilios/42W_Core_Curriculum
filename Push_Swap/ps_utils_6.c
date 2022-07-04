/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_6.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espyromi <espyromi@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 22:50:01 by espyromi          #+#    #+#             */
/*   Updated: 2021/11/04 15:23:30 by espyromi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_pos(int *stack, int length)
{
	int minn;
	int	k;
	int	pos_of_min;

	minn = stack[0];
	k = 1;
	while (k < length)
	{
		if (minn > stack[k])
		{
			minn = stack[k];
			pos_of_min = k;
		}
		k++;
	}
	return(pos_of_min);
}

void	bring_sec_min_up(int *stack, int len)
{
	int	pos_of_min;
	int	sec;
	int	i;
	int	pos_of_sec;

	pos_of_min = find_min_pos(stack, len);
	i = 0;
	sec = stack[i];
	pos_of_sec = 0;
	while (i < len)
	{
		if (sec > stack[i] && i != pos_of_min)
		{
			sec = stack[i];
			pos_of_sec = i;
		}
		i++;
	}
	send_sec_min_up(pos_of_sec, stack, len);
}

void	sort(int *indexes, int *len, int *stack_b)
{
	int	number;
	int	pos;
	int	i;

	number = 0;
	pos = 0;
	i = 0;
	while (*indexes)
	{
		while (number != indexes[pos])
			pos++;
		if (pos > *len / 2)
			call_rra(indexes, pos - *len, *len);
		else if (pos <= *len / 2)
			call_ra(indexes,pos - *len, *len);
		pb(indexes, stack_b, len);
		number++;
	}
	bring_them_back(indexes, stack_b, len);
}

void call_rra(int *indexes, int moves, int len)
{
	while (moves >= 0)
	{
		rra(indexes, len);
		moves--;
	}
}

void call_ra(int *indexes, int moves, int len)
{
	while (moves >= 0)
	{
		ra(indexes, len);
		moves--;
	}
}

void	bring_them_back(int *indexes, int *stack_b, int *length)
{
	while (*stack_b)
	{
		pa(indexes, stack_b, length);
		length--;
	}
}