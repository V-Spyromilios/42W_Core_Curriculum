#ifndef PIPEX_H
# define PIPEX_H
#include <unistd.h> //fork(), dup, dup2, close, execve, pipe, 
#include <string.h> //, 
#include <sys/wait.h> //wait(),
#include <stdlib.h> //EXIT_FAILURE
#include <stdio.h> //perror,
#include <fcntl.h> //open

/*
* From Libft
*/
char	*ft_strchr(const char *s, int c);
char 	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
void 	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

void	check_in(int fd[], char **argv);
void	take_cmds(char **argv, char ***cmds);

void	find_paths(char **env, char **paths, char ***cmds);
char	*find_exe(char **splitted, char **cmd);
char	*try_splitted(char *cmds, char **splitted);
void	call_parent(char *path, char **cmd, int ffd[], int pipes_fd[]);
void	call_child(char *path, char **cmd, int ffd[], int pipes_fd[]);



#endif