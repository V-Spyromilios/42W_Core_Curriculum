/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espyromi <espyromi@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 22:18:18 by espyromi          #+#    #+#             */
/*   Updated: 2021/11/04 03:12:24 by espyromi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char *argv[])
{
	int *arr;
	int	*unsorted;
	int	*sorted;
	int	len;

	len = argc - 1;
	if (argc == 1)
		return (0);
	else
		arr = take_arg(argc - 1, argv);
	unsorted = copy(arr, argc -1);
	sorted = bbsort(arr, argc - 1);
	sort_them(unsorted, sorted, &len);
	return (0);
}
