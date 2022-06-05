/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espyromi <espyromi@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 22:12:43 by espyromi          #+#    #+#             */
/*   Updated: 2022/02/10 22:12:44 by espyromi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	redir_fd(t_data *data, int fd, int redir_type)
{
	if (redir_type == 1)
	{
		create_stdin(data, fd);
		close(fd);
		close(0);
		fd = open("_tmp", O_RDONLY, 0644);
	}
	else if (redir_type == 2)
	{
		close(0);
		fd = open(data->redir_from[0], O_RDONLY, 0644);
	}
	if (redir_type == 3)
	{
		close (1);
		fd = open(data->redir_append[0], O_RDWR | O_CREAT | O_APPEND, 0644);
	}
	else if (redir_type == 4)
	{
		close (1);
		fd = open(data->redir_to[0], O_RDWR | O_CREAT | O_TRUNC, 0644);
	}
	if (fd == -1)
		error(data, "Open failed", 0, 'e');
}

void	redirect_input(t_data *data)
{
	if (is_redir(data->line, "<<"))
	{
		data->redir_stdin = get_redir(data, "<<");
		if (data->redir_stdin)
			redir_fd(data, data->redir_stdin_fd, 1);
		else
			error(data, "bash: syntax error near unexpected token `newline'\n",
				0, 'p');
	}
	else if (is_redir(data->line, "<"))
	{
		data->redir_from = get_redir(data, "<");
		if (data->redir_from)
			redir_fd(data, data->redir_from_fd, 2);
		else
			error(data, "bash: syntax error near unexpected token `newline'\n",
				0, 'p');
	}
}

void	redirect_output(t_data *data)
{
	if (is_redir(data->line, ">>"))
	{
		data->redir_append = get_redir(data, ">>");
		if (data->redir_append)
			redir_fd(data, data->redir_append_fd, 3);
		else
			error(data, "bash: syntax error near unexpected token `newline'\n",
				0, 'p');
	}
	else if (is_redir(data->line, ">"))
	{
		data->redir_to = get_redir(data, ">");
		if (data->redir_to)
			redir_fd(data, data->redir_to_fd, 4);
		else
			error(data, "bash: syntax error near unexpected token `newline'\n",
				0, 'p');
	}
}

void	redirect(t_data *data)
{
	redirect_input(data);
	redirect_output(data);
}
