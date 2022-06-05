/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espyromi <espyromi@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 12:45:39 by espyromi          #+#    #+#             */
/*   Updated: 2021/06/20 21:25:12 by espyromi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* The bzero() function writes n zeroed bytes to the string s.
* If n is zero, bzero() does nothing.
*/

void 	ft_bzero(void *s, size_t n)
{
	size_t		counter;

	if (!s)
		return ;
	counter = 0;
	while (counter < n)
	{
		*(char *)(s + counter) = 0;
		counter++;
	}
}
