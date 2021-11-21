/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espyromi <espyromi@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 23:04:45 by espyromi          #+#    #+#             */
/*   Updated: 2021/08/03 17:17:15 by espyromi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
/*
* This file contains some of functions needed for Get_Next_Line.
*/

char	*ft_substr(char const *s, int start, int len)
{
	int		x;
	int		y;	
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

void	ft_free(char *ptr)
{
	free (ptr);
	ptr = NULL;
}

size_t	ft_strlcpy(char *dst, const char *src,
			size_t dstsize)
{
	size_t	counter;
	size_t	length;

	counter = 0;
	length = 0;
	if (!dst)
		return (0);
	while (src[length] != '\0')
		length++;
	if (!dstsize)
		return (length);
	while (src[counter] != '\0' && counter < dstsize - 1)
	{
		dst[counter] = src[counter];
		counter++;
	}
	dst[counter] = '\0';
	return (length);
}

char	*set_n_return(char *box, char **line)
{
	char	*temp;

	if (!*(*line))
	{
		ft_free (*line);
		*line = ft_substr(box, 0, ft_strlen_nl(box) + 1);
		temp = ft_substr(box, ft_strlen_nl(box) + 1, (ft_strlen(box) - \
			ft_strlen_nl(box)));
		ft_strlcpy(box, temp, ft_strlen(box));
		free (temp);
		return (*line);
	}
	else
	{
		temp = ft_strjoin(*line, box);
		ft_free (*line);
		*line = ft_substr(temp, 0, ft_strlen_nl(temp) + 1);
		ft_free (temp);
		temp = ft_substr(box, ft_strlen_nl(box) + 1, (ft_strlen(box) - \
			ft_strlen_nl(box)));
		ft_strlcpy(box, temp, ft_strlen(box));
		ft_free (temp);
		return (*line);
	}
}

char	*set_line(char *box, char **line)
{
	char	*temp;

	temp = ft_strjoin(*line, box);
	ft_free (*line);
	box[0] = '\0';
	return (temp);
}
