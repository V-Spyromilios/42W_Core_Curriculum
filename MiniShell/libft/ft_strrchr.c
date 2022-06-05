/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espyromi <espyromi@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 12:45:39 by espyromi          #+#    #+#             */
/*   Updated: 2021/06/18 12:45:39 by espyromi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* The strchr() function locates the last occurrence of c
* (converted to a char) in the string pointed to by s.
* The terminating null character is considered to be part of
* the string; therefore if c is `\0', the functions locate
* the terminating `\0'. Returns a pointer to the located character,
* or NULL if the character does not appear in the string...
*/

char	*ft_strrchr(const char *s, int c)
{
	char	c_as_char;
	char	*occurance;

	occurance = NULL;
	c_as_char = (char)c;
	while (*s)
	{
		if (*s == c_as_char)
		{
			occurance = (char *)s;
		}
		s++;
	}
	if (occurance != NULL)
		return (occurance);
	else if (c_as_char == '\0' && *s == '\0')
	{
		occurance = (char *)s;
		return (occurance);
	}
	else
		return (NULL);
}
