/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espyromi <espyromi@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 12:45:39 by espyromi          #+#    #+#             */
/*   Updated: 2021/06/20 22:49:11 by espyromi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
*	Allocates (with malloc) and returns an array
*	of strings obtained by splitting ’s’ using the
*	character ’c’ as a delimiter.  The array must be
*	ended by a NULL pointer.
*/

static size_t	ft_count_words(const char *str, char delim)
{
	size_t	counter;

	counter = 0;
	if (!str)
		return (0);
	while (*str)
	{
		while (*str && *str == delim)
			str++;
		if (*str)
			counter++;
		while (*str && *str != delim)
			str++;
	}
	return (counter);
}

static size_t	ft_strslen(const char *s, char c)
{
	int	pos;

	if (*s == '\0')
		return (0);
	pos = 0;
	while (*s && *s != c)
	{
		pos++;
		s++;
	}
	return (pos);
}

static char	**ft_check_malloc(size_t total_words)
{
	char	**arr;

	arr = malloc((total_words + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	else
		return (arr);
}

const char	*ft_check_null(char const *s)
{
	if (!s)
		return (NULL);
	else
		return (s);
}

char 	**ft_split(char const *s, char c)
{
	size_t		total_words;
	size_t		limit;
	char		**arr_of_strs;
	int			position;

	ft_check_null(s);
	total_words = ft_count_words(s, c);
	arr_of_strs = ft_check_malloc(total_words);
	if (!arr_of_strs)
		return (NULL);
	limit = 0;
	position = 0;
	arr_of_strs[total_words] = NULL;
	while (total_words-- > 0)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			limit = ft_strslen(s, c);
			arr_of_strs[position++] = ft_substr(s, 0, limit);
			s += limit;
		}
	}
	return (arr_of_strs);
}
