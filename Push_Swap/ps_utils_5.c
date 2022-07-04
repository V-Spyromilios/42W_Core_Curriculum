/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espyromi <espyromi@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 18:54:18 by espyromi          #+#    #+#             */
/*   Updated: 2021/11/09 20:51:48 by espyromi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pb(int *stack_a, int *stack_b, int *len)
{
	int *arr; 
	arr = copy(stack_a, (*len));
	free(stack_a);
	move_all_down(stack_b, *len);
	stack_b[0] = arr[0];
	move_all_up(arr, *len);
	write(1, "pb\n", 3);
	return (--(*len));
}

void	hardcode_3(int *arr, int len)
{
	if (arr[0] < arr[1] && arr[1] > arr[2] && arr[0] < arr[2]) // 1 3 2 
	{
		rra(arr, len);
		sa(arr);
	}
	else if (arr[0] < arr[1] && arr[1] > arr[2] && arr[0] > arr[2]) // 2 3 1
		rra(arr, len);
	else if (arr[0] > arr[1] && arr[1] < arr[2] && arr[2] > arr[0]) // 2 1 3
		sa(arr);
	else if (arr[0] > arr[1] && arr[1] > arr[2] && arr[2] < arr[0]) // 3 2 1
	{
		ra(arr, len);
		sa(arr);
	}
	else if (arr[0] > arr[1] && arr[1] < arr[2] && arr[0] > arr[2]) // 3 1 2
		ra(arr, len);
}

int		hardcode_4(int *stack_a, int *stack_b, int *length)
{
	bring_min_up(stack_a, *length);
	pb(stack_a, stack_b, length);
	hardcode_3(&stack_a[1], *length); //check if len = 3!
	*length = pa(stack_a, stack_b, length); //doesnt work!
	return (*length);
}

void	bring_min_up(int *arr, int len)
{
	int	the_min;
	int	p;
	int	pos;

	p = 0;
	pos = 0;
	the_min = arr[p];
	while (p < len)
	{
		if (the_min > arr[p])
		{
			the_min = arr[p];
			pos = p;
		}
		p++;
	}
	if (pos == 0)
		return;
	else if (pos == len - 1)
		rra(arr, len);
	else if(pos >= len / 2)
		call_rra(arr, len - pos, len);
	else if (pos < len / 2)
		call_ra(arr, len - pos - 1, len);
	printf("After Bring min up:\n");
	int k = 0;
	while (k < len)
	{
		printf("%d ", arr[k]);
		k++;
	}
}

void	hardcode_5(int *stack_a, int *stack_b, int *length)
{
	bring_min_up(stack_a, *length); //douleuei
	*length = pb(stack_a, stack_b, length); //douleuei
	*length = hardcode_4(stack_a, stack_b, length);
	*length = pa(stack_a, stack_b, length);
}
