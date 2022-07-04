/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espyromi <espyromi@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 02:57:22 by espyromi          #+#    #+#             */
/*   Updated: 2021/10/29 19:26:47 by espyromi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(int *stack)
{
	if (!stack[0])
		return ;
	swap(&stack[0], &stack[1]);
	write(1, "sa\n", 3);
}

void	sb(int *stack)
{
	if (!stack[0])
		return ;
	swap(&stack[0], &stack[1]);
	write(1, "sb\n", 3);
}

void	ss(int *stack_a, int *stack_b)
{
	sa(stack_a);
	sb(stack_b);
	write(1, "ss\n", 3);
}

void	ra(int *stack, int len)  //Pass the len_init
{
	int	elevator;
	int	i;

	i = 0;
	elevator = stack[0];
	while (i < len)
	{
		stack[i] = stack[i + i];
		i++; 
	}
	stack[--len] = elevator;
	write(1, "ra\n", 3);
}

void	rb(int *stack, int len)  //Check!
{
	int	elevator;
	int	i;

	i = 0;
	elevator = stack[0];
	while (i < len)
	{
		stack[i] = stack[i + 1];
		i++; 
	}
	stack[--len] = elevator;
	write(1, "rb\n", 3);
}
