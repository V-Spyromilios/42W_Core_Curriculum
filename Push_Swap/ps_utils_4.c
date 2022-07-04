/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espyromi <espyromi@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 12:56:16 by espyromi          #+#    #+#             */
/*   Updated: 2021/11/05 21:23:13 by espyromi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		*copy(int *arr, int len)
{
	int	*storage;
	int	i;

	i = 0;
	storage = (int *)malloc((len) * sizeof(int));
	if (!storage)
		exit(-1);
	while(i < len)
	{
		storage[i] = arr[i];
		i++;
	}
	return (storage);
}

int *get_sorted_indexes(int *before, int *after, int len)
{
    int    *indexes;
    int    i;
    int    j;
    int    k;

	indexes = (int *)malloc((len + 1)* sizeof(int));
	i = 0;
	j = 0;
	k = 0;
	while(i < len)
	{
		j = 0;
		while (j < len)
		{
			if (before[i] == after[j])
				indexes[k] = j;
			j++;
		}
		i++;
		k++;
	}
	return (indexes);
}

void	sort_them(int *before, int *after, int *len)
{
	int	*indexes;
	int	*stack_b;
	int	i;

	i = 0;
	indexes = get_sorted_indexes(before, after, *len);
	stack_b = (int *)malloc(*len + 1 * sizeof(int));
	free (before);
	free (after);
	int k =0;
	while (k < *len)
	{
		printf(" %d ", indexes[k]);
		k++;
	}
			
	if (*len == 2)
		check_two(indexes);
	if (*len == 3)
		hardcode_3(indexes, *len);
	if (*len == 4)
		hardcode_4(indexes, stack_b, len);
	else if (*len == 5)
		hardcode_5(indexes, stack_b, len);
	else
		sort(indexes, len, stack_b);
}

int	check_if_sorted(int *arr, int length)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (length - 1 > 0)
	{
		if (arr[i] < arr[i + 1])
			i++;
		else
			k++;
		length--;
	}
	if (k == 0)
		return(1);
	else
		return(0);
}

void	send_sec_min_up(int pos, int *arr, int len)
{
	if (pos == 0)
		return;
	else if (pos == 4)
		rra(arr, len);
	else if (pos == 3)
	{
		rra(arr, len);
		rra(arr, len);
	}
	else if (pos == 2)
	{
		ra(arr, len);
		ra(arr, len);
	}
	else
		sa(arr);
}
