/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espyromi <espyromi@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 12:45:39 by espyromi          #+#    #+#             */
/*   Updated: 2021/06/18 12:45:39 by espyromi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* take the full size of the destination buffer and guarantee NUL-termination
* if there is room.  Note that room for the NUL should be included in dstsize.
* strlcpy copies up to dstsize - 1 characters from the string src to dst,
* NUL-terminating the result if dstsize is not 0.
* Returns the total length of the string it tried to create.
* For strlcpy() that means the length of src.
*/

size_t	ft_strlcpy(char *restrict dst, const char *restrict src,
			size_t dstsize)
{
	size_t	counter;
	size_t	length;

	counter = 0;
	length = 0;
	if (!dst)
		return (0);
	while (src[length] != '\0')
		length++;
	if (!dstsize)
		return (length);
	while (src[counter] != '\0' && counter < dstsize - 1)
	{
		dst[counter] = src[counter];
		counter++;
	}
	dst[counter] = '\0';
	return (length);
}
