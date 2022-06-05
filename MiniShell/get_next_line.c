/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espyromi <espyromi@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 22:13:13 by espyromi          #+#    #+#             */
/*   Updated: 2022/02/10 22:13:14 by espyromi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"

char	*store_to_line(char *s)
{
	char		*line;
	long long	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	line = malloc ((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
	{
		line[i] = s[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*save_extra(char *s, long long i, long long j)
{
	char	*temp;

	if (!s)
		return (NULL);
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	if (i == ft_strlenn(s))
	{
		free(s);
		return (NULL);
	}
	temp = malloc((ft_strlenn(s + i) + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	while (s[i + j + 1] != '\0')
	{
		temp[j] = s[i + j + 1];
		j++;
	}
	temp[j] = '\0';
	free(s);
	return (temp);
}

long long	free_buff(char *buff)
{
	free(buff);
	return (-1);
}

long long	has_new_line(char *str)
{
	long long	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	char		*buff;
	long long	ret;
	static char	*s[1024];

	if (!line || fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (-1);
	ret = 1;
	while (ret && !has_new_line(s[fd]))
	{
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret == -1)
			return (free_buff(buff));
		buff[ret] = 0;
		s[fd] = ft_strjoinn(s[fd], buff);
	}
	*line = store_to_line(s[fd]);
	s[fd] = save_extra(s[fd], 0, 0);
	free(buff);
	if (ret == 0)
		return (0);
	return (1);
}
