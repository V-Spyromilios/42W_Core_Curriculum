/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espyromi <espyromi@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 12:45:39 by espyromi          #+#    #+#             */
/*   Updated: 2021/06/18 12:45:39 by espyromi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
*	 The strchr() function locates the first occurrence
*    of c (converted to a char) in the string pointed
*    to by s.  The terminating null character is con-
*    sidered to be part of the string; therefore if c
*    is `\0', the functions locate the terminating `\0'. Returns pointer
*    to the char.
*/

char	*ft_strchr(const char *s, int c)
{
	char	chr;

	chr = (char)c;
	if (*s == chr)
		return ((char *)s);
	while (*s != chr && *s != '\0')
	{
		s++;
		if (*s == chr)
			return ((char *)s);
	}
	return (NULL);
}
