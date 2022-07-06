#include "libft.h"

size_t	slen(const char *s)
{
	size_t	c;

	c = 0;
	if (!s)
		return (0);
	while (s[c] != '\0')
	{
		c++;
	}
	return (c);
}

char	*gnl_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)(&s[i]));
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(&s[i]));
	return (NULL);
}

void	*ft_gnl_malloc(size_t count, size_t size)
{
	void			*rtn_str;
	unsigned char	*tmp_str;

	rtn_str = malloc(count * size);
	if (!rtn_str)
		return (NULL);
	tmp_str = rtn_str;
	*tmp_str = '\0';
	return (rtn_str);
}

char	*ft_gnl_prepare_string(int fd, int bytes_read, \
char *rtn_str, char **str)
{
	static char	buf[MAX_FD][BUFFER_SIZE + 1];

	while (!gnl_strchr(buf[fd], '\n'))
	{
		if (*buf[fd])
			rtn_str = ft_gnl_strjoin(rtn_str, buf[fd]);
		bytes_read = read(fd, buf[fd], BUFFER_SIZE);
		buf[fd][bytes_read] = '\0';
		if (bytes_read <= 0 && !(*rtn_str))
		{
			free(rtn_str);
			return (NULL);
		}
		if (bytes_read < BUFFER_SIZE && !gnl_strchr(buf[fd], '\n'))
		{
			rtn_str = ft_gnl_strjoin(rtn_str, buf[fd]);
			ft_bzero(buf[fd], 1);
			return (rtn_str);
		}
	}
	*str = ft_gnl_strjoin(rtn_str, buf[fd]);
	rtn_str = gnl_substr(*str, 0, ((gnl_strchr(*str, '\n') - *str + 1)));
	ft_memmove(buf[fd], *str + slen(rtn_str), slen(*str) - slen(rtn_str));
	ft_bzero(&buf[fd][slen(*str) - slen(rtn_str)], 1);
	return (rtn_str);
}