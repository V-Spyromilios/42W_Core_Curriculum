/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espyromi <espyromi@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 20:56:02 by espyromi          #+#    #+#             */
/*   Updated: 2022/06/27 13:09:04 by espyromi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// int	ft_strlen(const char *s)
// {
// 	int		counter;
// 	char	*p;

// 	counter = 0;
// 	p = (char *)s;
// 	while (*p != '\0')
// 	{
// 		counter++;
// 		p++;
// 	}
// 	return (counter);
// }

int	find_int_len(int n)
{
	int			length;
	long int	nbr;

	length = 1;
	if (n < 0)
	{
		nbr = n * -1;
		length++;
	}
	else
		nbr = n;
	while (nbr > 9)
	{
		nbr = nbr / 10;
		length++;
	}
	return (length);
}

int	find_int_len_16(unsigned long long n)
{
	int	length;

	length = 1;
	while (n > 15)
	{
		n = n / 16;
		length++;
	}
	return (length);
}
