/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espyromi <espyromi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 18:48:01 by espyromi          #+#    #+#             */
/*   Updated: 2021/12/14 15:45:03 by espyromi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

/*
* Lexicographically compare the null-terminated strings s1 and s2.
* This function compares not more than n characters. Returns an integer
* greater than, equal to, or less than 0, according as the string s1 is
* greater than, equal to, or less than the string s2.
* The comparison is done using unsigned characters...
*/

int		ft_strncmp(const char *s1, const char *s2, size_t n)
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

void 	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dst)
		return (NULL);
	while (i < n)
	{
		((unsigned char *)(dst))[i] = ((unsigned char *)(src))[i];
		i++;
	}
	return (dst);
}

size_t	ft_strlen(const char *s)
{
	size_t	counter;
	char	*p;

	counter = 0;
	p = (char *)s;
	while (*p != '\0')
	{
		counter++;
		p++;
	}
	return (counter);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	x;
	size_t	y;

	new_str = ((char *)malloc(sizeof(*s1) * (ft_strlen(s1)
					+ ft_strlen(s2) + 1)));
	if (!new_str)
		return (NULL);
	x = 0;
	y = 0;
	while (s1[x])
	{
		new_str[y++] = s1[x];
		x++;
	}
	x = 0;
	while (s2[x])
	{
		new_str[y++] = s2[x];
		x++;
	}
	new_str[y] = '\0';
	return (new_str);
}

