/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espyromi <espyromi@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 12:45:39 by espyromi          #+#    #+#             */
/*   Updated: 2021/06/21 23:43:51 by espyromi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* The memcpy() function copies n bytes from memory area src to memory
* area dst.  If dst and src overlap, behavior is undefined.  Applications
* in which dst and src might overlap should use memmove instead.
* The memcpy() function returns the original value of dst.
*/

void 	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dst)
		return (NULL);
	while (i < n)
	{
		((unsigned char *)(dst))[i] = ((unsigned char *)(src))[i];
		i++;
	}
	return (dst);
}
