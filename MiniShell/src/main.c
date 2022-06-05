/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espyromi <espyromi@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 22:12:34 by espyromi          #+#    #+#             */
/*   Updated: 2022/02/10 22:12:35 by espyromi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	initialize(t_data *data, char **environ)
{
	printf("\n---------------------------------------------\n");
	printf("--------------- Minishell 0.0 ---------------\n");
	printf("---------------------------------------------\n\n");
	data->line = NULL;
	data->cmd = NULL;
	data->cmd_with_path = NULL;
	data->argv = NULL;
	data->envp_len = check_envplen(environ);
	data->envp = create_envp(environ, data, NULL);
	ft_bzero(data->path, PATH_MAX);
	ft_bzero(data->prev_dir, PATH_MAX);
	data->redir_append = NULL;
	data->redir_from = NULL;
	data->redir_stdin = NULL;
	data->redir_to = NULL;
	data->not_valid = 0;
	data->pipe_nb = 0;
	data->echo_quote = 0;
	data->exit_status = 0;
	data->old_stdin = dup(STDIN_FILENO);
	data->old_stdout = dup(STDOUT_FILENO);
	signal_init();
}

void	destroy(t_data *data)
{
	if (data->cmd)
	{
		free_split(data->cmd);
		data->cmd = NULL;
	}
	if (data->line)
	{
		free(data->line);
		data->line = NULL;
	}
	destroy_redir(data);
	if (dup2(data->old_stdin, STDIN_FILENO) < 0)
		error(data, "Recover old STDIN failed\n", 1, 'e');
	if (dup2(data->old_stdout, STDOUT_FILENO) < 0)
		error(data, "Recover old STDOUT failed\n", 1, 'e');
	data->not_valid = 0;
	data->pipe_nb = 0;
}

void	read_command_line(t_data *data)
{
	char	*temp1;
	char	*temp2;

	temp1 = ft_strjoin(data->path, ":> ");
	data->line = readline(temp1);
	free(temp1);
	if (data->line && *(data->line))
		add_history(data->line);
	while (data->line && check_line(data))
	{
		temp1 = ft_strjoin(data->line, "\n");
		free(data->line);
		temp2 = readline(">");
		data->line = ft_strjoin(temp1, temp2);
		free(temp1);
		free(temp2);
	}
}

void	exit_minishell(t_data *data)
{
	destroy(data);
	free_split(data->envp);
	printf("\n");
	exit(0);
}

int	main(void)
{
	t_data		data;
	extern char	**environ;

	initialize(&data, environ);
	while (1)
	{
		getcwd(data.path, PATH_MAX);
		read_command_line(&data);
		if (data.line && *(data.line))
		{
			redirect(&data);
			data.cmd = split_input(data.line, '|', &data);
			if (*(data.cmd) && *(data.cmd + 1))
				execute_pipe(&data);
			else if (*(data.cmd))
				execute_command(data.cmd[0], &data, -1, 1);
		}
		if (data.line == NULL)
			exit_minishell(&data);
		destroy(&data);
	}
	free_split(data.envp);
	return (0);
}
