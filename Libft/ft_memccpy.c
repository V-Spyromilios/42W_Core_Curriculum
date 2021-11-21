/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espyromi <espyromi@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 12:45:39 by espyromi          #+#    #+#             */
/*   Updated: 2021/06/18 12:45:39 by espyromi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
*	The memccpy() function copies bytes from string
*	src to string dst.  If the character c (as con-
*	verted to an unsigned char) occurs in the string
*	src, the copy stops and a pointer to the byte
*	after the copy of c in the string dst is returned.
*	otherwise, n bytes are copied, and a NULL pointer is returned.
*/

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	void	*located;
	int		length;

	if (!dst && !src)
		return (NULL);
	located = ft_memchr(src, c, n);
	if (located)
	{
		length = located - src + 1;
		ft_memmove(dst, src, length);
		return (dst + length);
	}
	ft_memmove(dst, src, n);
	return (NULL);
}
