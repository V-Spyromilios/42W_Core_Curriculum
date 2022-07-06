/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espyromi <espyromi@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 12:45:39 by espyromi          #+#    #+#             */
/*   Updated: 2021/06/20 22:51:40 by espyromi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
* The memmove() function copies len bytes from string src to string dst.
* The two strings may overlap; the copy is always done in a non-destruc-
* tive manner. The memmove function returns the original value of dst.
*/

static void	copy_mem(char *source, char *dest, size_t len)
{
	source = source + len - 1;
	dest = dest + len - 1;
	while (len > 0)
	{
		*dest = *source;
		len--;
		dest--;
		source--;
	}
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dest;
	char	*source;

	if (!dst || !src)
		return (NULL);
	dest = (char *)dst;
	source = (char *)src;
	if (source < dest)
		copy_mem(source, dest, len);
	else
	{
		while (len > 0)
		{
			*dest = *source;
			dest++;
			source++;
			len--;
		}
	}
	return (dst);
}
