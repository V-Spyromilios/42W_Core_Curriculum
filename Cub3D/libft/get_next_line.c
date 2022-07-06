#include "libft.h"

char	*ft_gnl_strdup(const char *s1)
{
	size_t	s1_len;
	char	*arr;
	size_t	i;

	i = 0;
	if (!s1)
		return (NULL);
	s1_len = slen(s1) + 1;
	arr = malloc(sizeof(char) * s1_len);
	if (!arr)
		return (NULL);
	while (i < s1_len)
	{
		arr[i] = s1[i];
		i++;
	}
	free((void *)(s1));
	return (arr);
}

char	*ft_gnl_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	i = 0;
	j = 0;
	ptr = malloc((slen(s1) + slen(s2) + 1) + 1 * sizeof(char));
	if (!ptr)
		return (NULL);
	ptr[0] = '\0';
	while (i < slen(s1))
	{
		ptr[i] = s1[i];
		i++;
	}
	free((void *)(s1));
	while (j < slen(s2))
	{
		ptr[i] = s2[j];
		j++;
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*gnl_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*ptr;

	if (!s)
		return (NULL);
	i = 0;
	s_len = slen(s);
	if ((size_t)start > s_len)
	{
		return (ft_gnl_strdup(""));
	}
	ptr = malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	ptr[0] = '\0';
	while (i < (len))
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*get_next_line(int fd)
{
	int			bytes_read;
	char		*rtn_str;
	char		*tmpstr;

	bytes_read = 1;
	if (fd < 0 || fd > MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	rtn_str = ft_gnl_malloc(sizeof(char), 1);
	tmpstr = NULL;
	rtn_str = ft_gnl_prepare_string(fd, bytes_read, rtn_str, &tmpstr);
	if (tmpstr)
		free(tmpstr);
	if (rtn_str == NULL)
		return (NULL);
	else
		return (rtn_str);
}