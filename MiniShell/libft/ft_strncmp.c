/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espyromi <espyromi@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 12:45:39 by espyromi          #+#    #+#             */
/*   Updated: 2021/06/18 12:45:39 by espyromi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* Lexicographically compare the null-terminated strings s1 and s2.
* This function compares not more than n characters. Returns an integer
* greater than, equal to, or less than 0, according as the string s1 is
* greater than, equal to, or less than the string s2.
* The comparison is done using unsigned characters...
*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	counter;

	counter = 1;
	if (n == 0)
		return (0);
	while (counter < n && *s1 != '\0' && *s2 != '\0' && (*s1 == *s2))
	{
		s1++;
		s2++;
		counter++;
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
