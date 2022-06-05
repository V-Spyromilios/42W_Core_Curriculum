/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espyromi <espyromi@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 12:45:39 by espyromi          #+#    #+#             */
/*   Updated: 2021/06/18 12:45:39 by espyromi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
*	Allocates (with malloc(3)) and returns a copy of
*	’s1’ with the characters specified in ’set’ removed
*	from the beginning and the end of the string.
*/

static int	equal(char s, char const *set)
{
	while (*set)
	{
		if (*set == s)
			return (1);
		else
			set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*start;
	char	*end;
	int		length;
	char	*storage;

	start = (char *)s1;
	end = start + ft_strlen(s1) - 1;
	while (*start && equal(*start, set))
		start++;
	while (end > start && equal(*end, set))
		end--;
	length = end - start;
	storage = malloc(length + 1 * sizeof(char));
	if (!storage)
		return (NULL);
	ft_strlcpy(storage, start, length + 2);
	return (storage);
}
