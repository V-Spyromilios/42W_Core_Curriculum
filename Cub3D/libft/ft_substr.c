/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espyromi <espyromi@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 12:45:39 by espyromi          #+#    #+#             */
/*   Updated: 2021/06/28 12:00:46 by espyromi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* 	Allocates (with malloc) and returns a substring
*	from the string ’s’. The substring begins at index ’start’
*	and is of maximum size ’len’.
*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	x;
	size_t	y;	
	char	*dest;

	dest = (char *)malloc(sizeof(*s) * (len + 1));
	if (!dest)
		return (NULL);
	x = 0;
	y = 0;
	while (s[x])
	{
		if (x >= start && y < len)
		{
			dest[y] = s[x];
			y++;
		}
		x++;
	}
	dest[y] = 0;
	return (dest);
}
