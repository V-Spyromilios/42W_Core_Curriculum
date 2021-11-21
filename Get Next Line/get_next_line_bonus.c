/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espyromi <espyromi@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 22:52:49 by espyromi          #+#    #+#             */
/*   Updated: 2021/08/03 17:17:24 by espyromi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen_nl(const char *s)
{
	int		counter;
	char	*p;

	counter = 0;
	p = (char *)s;
	while (*p != '\0' && *p != '\n')
	{
		counter++;
		p++;
	}
	return (counter);
}

char	*ft_strjoin(char *s1, char *s2)
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

int	ft_strlen(const char *s)
{
	int		counter;
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

char	*ft_strchr(char *s, int c)
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

char	*get_next_line(int fd)
{
	int			chars_read;
	static char	box[MAX_FD][BUFFER_SIZE + 1];
	char		*return_line;

	if (fd < 0 || fd > MAX_FD || BUFFER_SIZE < 1)
		return (NULL);
	return_line = (char *)malloc(1);
	return_line[0] = 0;
	while (!ft_strchr(box[fd], '\n'))
	{
		if (*box[fd])
			return_line = set_line(box[fd], &return_line);
		chars_read = read(fd, box[fd], BUFFER_SIZE);
		box[fd][chars_read] = '\0';
		if (chars_read <= 0 && !*return_line)
		{
			ft_free (return_line);
			return (NULL);
		}
		if ((chars_read < BUFFER_SIZE && (ft_strchr(box[fd], '\n') == NULL)))
			return (set_line(box[fd], &return_line));
	}
	return ((set_n_return(box[fd], &return_line)));
}
