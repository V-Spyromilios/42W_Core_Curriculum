/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espyromi <espyromi@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 14:11:48 by espyromi          #+#    #+#             */
/*   Updated: 2022/06/27 13:11:28 by espyromi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# ifndef MAX_FD
#  define MAX_FD 1024
# endif

/*
* PART 1
*/
int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *b, int c, size_t len);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *restrict dst, const char *restrict src,
			size_t dstsize);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t n);
char	*ft_strrchr(const char *s, int c);
int		ft_tolower(int c);
int		ft_toupper(int c);

/*
* PART 2
*/
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

/*
* BONUS PART
*/
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

void	ft_lstdelone(t_list *lst, void (*del)(void*));
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *),
			void (*del)(void *));

/*
	get_next_line
*/
char	*get_next_line(int fd);
char	*gnl_strchr(const char *s, int c);
char	*ft_gnl_strjoin(char const *s1, char const *s2);
size_t	slen(const char *s);
char	*gnl_substr(char const *s, unsigned int start, size_t len);
void	*ft_gnl_memcpy(void *dst, const void *src, size_t n);
void	*ft_gnl_memmove(void *dst, const void *src, size_t len);
void	*ft_gnl_malloc(size_t count, size_t size);
char	*ft_gnl_prepare_string(int fd, int bytes_read, \
char *rtn_str, char **tmpstr);

//Printf
/*
** Main Functions
*/
int		ft_printf(const char *, ...);
int		pc_found(char c, va_list args);
int		ft_char(va_list args);
int		ft_string(va_list args);
int		ft_pointer(va_list args);
int		ft_decimal(va_list args);
int		ft_integer(va_list args);
int		ft_un_decimal(va_list args);
int		ft_hexa_low(va_list args);
int		ft_hexa_caps(va_list args);
int		ft_percent(void);
/*
** Auxiliary Functions
*/
int		ft_putnum_fd(int n, int fd);

int		find_int_len_16(unsigned long long n);
int		find_int_len(int n);
void	put_nbr(long int num, int base, char *base_char);
int		get_len(unsigned long int n);
void	write_buf(char *buffer, int length, unsigned long long int poi);
void	write_Hexa(char *buffer, int len, unsigned int num);
void	write_hexa(char *buffer, int len, unsigned int num);
char	*ft_strappend(char const *s1, char const c);

#endif
