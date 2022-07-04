/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_moves2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espyromi <espyromi@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 12:57:27 by espyromi          #+#    #+#             */
/*   Updated: 2021/11/04 17:19:11 by espyromi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pa(int *stack_a, int *stack_b, int *len)
{
	move_all_down(stack_a, *len);
	stack_a[0] = stack_b[0];
	move_all_up(stack_b, *len);
	write(1, "pa\n", 3);
	return(*len--);
}

void	rrb(int *stack, int len)  //Check!
{
	int	elevator;
	int	i;

	i = len - 1;
	elevator = stack[--len];
	while (i > 0)
	{
		stack[i] = stack[i - 1];
		i--; 
	}
	stack[0] = elevator;
	write(1, "rrb\n", 4);
}

void	rra(int *stack, int len)  //Check!
{
	int	elevator;
	int	i;

	i = len - 1;
	elevator = stack[--len];
	while (i > 0)
	{
		stack[i] = stack[i - 1];
		i--; 
	}
	stack[0] = elevator;
	write(1, "rra\n", 4);
}

void	rrr(int *stack_a, int *stack_b, int len)
{
	rra(stack_a, len);
	rrb(stack_b, len);
	write(1, "rrr\n", 4);
}

void	rr(int *stack_a, int *stack_b, int len)
{
	ra(stack_a, len);
	rb(stack_b, len);
	write(1, "rr\n", 3);
}
