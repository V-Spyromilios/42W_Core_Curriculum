#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define BUFFER_SIZE 42

int			get_next_line(int fd, char **line);
char		*ft_strjoinn(char *s1, char *s2);
long long	ft_strlenn(char *str);

#endif