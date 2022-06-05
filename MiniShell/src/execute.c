/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espyromi <espyromi@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 22:12:27 by espyromi          #+#    #+#             */
/*   Updated: 2022/02/10 22:12:28 by espyromi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	execute_fd(int cmd_nb, t_data *data, int end)
{
	if (cmd_nb > 0)
	{
		if (dup2(data->pipe_fd[(cmd_nb - 1) * 2], STDIN_FILENO) < 0)
			return (error(data, "Dup failed", 1, 'e'));
		close(data->pipe_fd[(cmd_nb - 1) * 2 + 1]);
	}
	if (!end)
	{
		if (dup2(data->pipe_fd[cmd_nb * 2 + 1], STDOUT_FILENO) < 0)
			return (error(data, "Dup failed", 1, 'e'));
		close(data->pipe_fd[cmd_nb * 2]);
	}
}

void	execute_fork(t_data *data, int cmd_nb, int end)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		return (error(data, "Fork failed", 1, 'e'));
	else if (!pid)
	{
		execute_fd(cmd_nb, data, end);
		if (execve(data->cmd_with_path, data->argv, data->envp) < 0)
			error(data, "Exec failed", 1, 'e');
	}
}

int	is_builtin(char *arg, t_data *data, int cmd_nb, int end)
{
	int	ret;

	ret = 1;
	if ((ft_strlen(arg) == 4 && !ft_strncmp(arg, "echo", ft_strlen(arg)))
		|| (ft_strlen(arg) == 3 && !ft_strncmp(arg, "pwd", ft_strlen(arg)))
		|| (ft_strlen(arg) == 3 && !ft_strncmp(arg, "env", ft_strlen(arg))))
		dispatch(data, cmd_nb, end, arg);
	else if (data->pipe_nb)
		return (0);
	else if (ft_strlen(arg) == 6 && !ft_strncmp(arg, "export", ft_strlen(arg)))
		change_env(data, 1);
	else if (ft_strlen(arg) == 5 && !ft_strncmp(arg, "unset", ft_strlen(arg)))
		change_env(data, 2);
	else if (ft_strlen(arg) == 2 && !ft_strncmp(arg, "cd", ft_strlen(arg)))
		change_directory(data);
	else if (ft_strlen(arg) == 4 && !ft_strncmp(arg, "exit", ft_strlen(arg)))
		error(data, NULL, 1, 0);
	else
		ret = 0;
	return (ret);
}

void	execute_command(char *cmd, t_data *data, int cmd_nb, int end)
{
	int	status;

	if (!data->not_valid)
		data->argv = split_input(cmd, ' ', data);
	if (!data->not_valid && data->argv[0]
		&& !is_builtin(data->argv[0], data, cmd_nb, end) && !check_path(data))
	{
		execute_fork(data, cmd_nb, end);
		if (data->cmd_with_path)
			free(data->cmd_with_path);
		if (cmd_nb >= 1)
			close_pipe(cmd_nb, data);
		waitpid(-1, &status, 0);
		data->exit_status = WEXITSTATUS(status);
	}
	free_split(data->argv);
}

void	execute_pipe(t_data *data)
{
	int	i;

	i = -1;
	data->pipe_fd = malloc(data->pipe_nb * 2 * sizeof(int));
	if (!data->pipe_fd)
		error(data, "Malloc for pipe_fd failed", 1, 'p');
	while (!data->not_valid && data->cmd[++i])
	{
		if (data->cmd[i + 1])
		{
			if (pipe(data->pipe_fd + i * 2) == -1)
			{
				free(data->pipe_fd);
				return (error(data, "Pipe failed", 1, 'e'));
			}
			else
				execute_command(data->cmd[i], data, i, 0);
		}
		else
			execute_command(data->cmd[i], data, i, 1);
	}
	free(data->pipe_fd);
}
