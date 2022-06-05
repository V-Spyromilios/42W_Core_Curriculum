/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espyromi <espyromi@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 12:45:39 by espyromi          #+#    #+#             */
/*   Updated: 2021/06/20 22:22:43 by espyromi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
*	Allocates (with malloc) and returns a new
*	string, which is the result of the concatenation
*	of ’s1’ and ’s2’.
*/

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
