/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espyromi <espyromi@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 12:45:39 by espyromi          #+#    #+#             */
/*   Updated: 2021/06/19 21:30:26 by espyromi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
* Takes the full size of the destination buffer and guarantee NUL-termination
* if there is room. Note that room for the NUL should be included in dstsize.
* appends string src to the end of dst. It will append at most
* dstsize - strlen(dst) - 1 characters.  It will then NUL-terminate, unless
* dstsize is 0 or the original dst string was longer than dstsize
* (in practice this should not happen as it means that either dstsize is
* incorrect or that dst is not a proper string).
* Returns the initial length of dst plus the length of src.
*/

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_dst;
	size_t	len_src;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (dstsize < len_dst)
		return (dstsize + len_src);
	dst += len_dst;
	ft_strlcpy(dst, src, dstsize - len_dst);
	return (len_dst + len_src);
}
