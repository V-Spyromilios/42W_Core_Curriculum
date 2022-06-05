/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espyromi <espyromi@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 12:45:39 by espyromi          #+#    #+#             */
/*   Updated: 2021/06/18 12:45:39 by espyromi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* Allocates (with malloc(3)) and returns a string representing the integer
* received as an argument. Negative numbers must be handled.
* Returns the string representing the integer. NULL if the allocation fails.
*/

static int	find_int_len(long int n)
{
	int	length;

	length = 1;
	while (n > 9)
	{
		n = n / 10;
		length++;
	}
	return (length);
}

static char	*store_negatives(long int input, int length, char *storage)
{
	int	i;

	storage[0] = '-';
	storage[length] = '\0';
	while (length > 1)
	{
		length--;
		i = input % 10 + '0';
		storage[length] = i;
		input = input / 10;
	}
	return (storage);
}

static char	*store_positives(long int input, int length, char *storage)
{
	int	i;

	storage[length] = '\0';
	while (length >= 0)
	{
		length--;
		i = input % 10 + '0';
		storage[length] = i;
		input = input / 10;
	}
	return (storage);
}

char	*ft_itoa(int n)
{
	char	*allocation;
	int		length;

	if (n < -2147483648 || n > 2147483647)
		return (NULL);
	if (n < 0)
	{
		length = find_int_len((long int)n * -1);
		allocation = malloc((sizeof(char) * length + 2));
		if (!allocation)
			return (NULL);
		store_negatives((long int)n * -1, length + 1, allocation);
	}
	else
	{
		length = find_int_len((long int)n);
		allocation = malloc((sizeof(char) * length + 1));
		if (!allocation)
			return (NULL);
		store_positives((long int)n, length, allocation);
	}
	return (allocation);
}
