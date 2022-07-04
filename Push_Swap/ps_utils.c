/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espyromi <espyromi@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 20:21:48 by espyromi          #+#    #+#             */
/*   Updated: 2021/11/09 19:13:38 by espyromi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*bbsort(int *arr, int len)
{
	int	step;
	int	i;
	int	temp;
	int	flag;
	int	s;

	step = 0;
	i = 0;
	s = 0;
	while (step < len - 1)
	{
		flag = 0;
		i = 0;
		while (i < len - step - 1)
		{
			if (arr[i] > arr[i + 1])
			{
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				flag = 1;
			}
			i++;
		}
		step++;
	}
	return (arr);
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	if (!str)
		return (0);
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (*str < 48 || *str > 57)
		return (0);
	while (*str >= 48 && *str <= 57)
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}

int *take_arg(int argc, char *arg[])
{
	int	i;
	int	j;
	int	*arr;

	j = 1;
	i = 0;
	arr = (int *)malloc(argc - 1 * sizeof(int));
	if (!arr)
		return (0);
	while (i < argc - 1)
	{
		arr[i] = ft_atoi(arg[j]);
		j++;
		i++;
	}
	check_input(arr, argc);
	if (check_if_sorted(arr, argc) == 1)
	{
		free (arr);
		exit(-1);
	}
	return (arr);
}

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	check_two(int *arr)
{
	if (arr[0] > arr[1])
		sa(arr);
}