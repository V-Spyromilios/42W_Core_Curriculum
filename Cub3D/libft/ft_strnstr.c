/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espyromi <espyromi@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 12:45:39 by espyromi          #+#    #+#             */
/*   Updated: 2021/06/18 12:45:39 by espyromi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* Locates the first occurrence of the null-terminated string needle in the
* string haystack, where not more than len characters are searched.
* Returns haystack if needle empty, otherwise a pointer
* to the first char of the first occurance of needle is
* returned.
*/

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	h_pos;
	size_t	f;
	char	*found;

	h_pos = 0;
	if (!*needle)
		return ((char *)haystack);
	while (haystack[h_pos] != '\0' && h_pos < n)
	{
		if (haystack[h_pos] == needle[0])
		{
			f = 1;
			while (needle[f] != '\0' && haystack[h_pos + f] == needle[f]
				&& (h_pos + f) < n)
				f++;
			if (needle[f] == '\0')
			{
				found = (char *)&haystack[h_pos];
				return (found);
			}
		}
		h_pos++;
	}
	return (NULL);
}
