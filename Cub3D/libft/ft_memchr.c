/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espyromi <espyromi@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 12:45:39 by espyromi          #+#    #+#             */
/*   Updated: 2021/06/18 12:45:39 by espyromi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
*	The memchr function locates the first occurrence of c (converted to
*	an unsigned char) in string s. Returns a pointer to the
*	byte located, or NULL if no such byte exists within n bytes.
*/

void 	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	runner;
	size_t	limit;

	runner = 0;
	limit = 0;
	while (limit < n)
	{
		if (((unsigned char *)s)[runner] == (unsigned char)c)
			return ((void *)(s + runner));
		runner++;
		limit++;
	}
	return (NULL);
}
