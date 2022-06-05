#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include "get_next_line.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <sys/wait.h>
# include <fcntl.h>

# ifdef __linux__
#  include <limits.h>
# else
# include <sys/syslimits.h>
# endif

typedef struct s_data
{
	int		not_valid;
	int		pipe_nb;
	int		*pipe_fd;
	int		envp_len;
	int		echo_quote;
	int		exit_status;
	int		redir_from_fd;
	int		redir_stdin_fd;
	int		redir_to_fd;
	int		redir_append_fd;
	int		old_stdin;
	int		old_stdout;
	char	**redir_from;
	char	**redir_stdin;
	char	**redir_to;
	char	**redir_append;
	char	*cmd_with_path;
	char	**argv;
	char	**envp;
	char	*line;
	char	**cmd;
	char	path[PATH_MAX];
	char	prev_dir[PATH_MAX];
}	t_data;

/* main.c */
char	**split_input(char *line, char c, t_data *data);
void	destroy(t_data *data);

/* create.c */
char	**create_envp(char **envp, t_data *data, char *target);
char	*create_expand(int flag, char *src, t_data *data);
char	**create_redir_string(t_data *data, char **ret, int i, int *start_len);
void	create_stdin(t_data *data, int fd);

/* signal.c */
void	signal_init(void);

/* check.c */
int		check_path(t_data *data);
int		check_line(t_data *data);
int		check_envplen(char **envp);
char	*check_in_env(char **envp, char *to_check, t_data *data, int print);

/* execute.c */
void	execute_command(char *cmd, t_data *data, int cmd_nb, int end);
void	execute_pipe(t_data *data);

/* builtin.c */
void	change_env(t_data *data, int cmd);
void	change_directory(t_data *data);
void	dispatch(t_data *data, int cmd_nb, int end, char *arg);

/* builtin_utils.c */
int		has_target(char **envp, char *target);
char	*trim_target(char *target);
char	*get_dir_name(t_data *data);
void	builtin_fd(int cmd_nb, t_data *data, int end);
int		change_env_helper(t_data *data, int cmd, int i, char **old);

/* redirect.c */
void	redirect(t_data *data);

/* redirect_utils.c */
char	**get_redir(t_data *data, char *c);
char	*is_redir(char *line, char *str);

/* error.c */
void	error(t_data *data, char *str, int end, char type);
int		free_split(char **str);
void	free_pipe(char **pipe_cmd, t_data *data);
void	close_pipe(int piped, t_data *data);
void	destroy_redir(t_data *data);

/* split_input.c */
char	*get_next_word(char **pointer_place, int *flag, t_data *data);

/* split_input_utils.c */
int		word_count_col(char *line, char c);
int		word_count(char *line, char c);
int		get_len_next_word(char *pointer, int *start, char *ch, int *flag);
int		get_word_count_helper(char *line, char c);

#endif