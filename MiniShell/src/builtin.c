/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espyromi <espyromi@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 22:12:07 by espyromi          #+#    #+#             */
/*   Updated: 2022/02/10 22:12:09 by espyromi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	change_directory(t_data *data)
{
	int		i;
	char	*dir;

	i = 1;
	while (data->argv[i] != NULL)
		i++;
	dir = get_dir_name(data);
	if (i > 2 || chdir(dir) == -1)
	{
		data->exit_status = 1;
		if (i > 2)
			printf("cd: too many arguments\n");
		else
			printf("cd: no such file or directory: %s\n", dir);
	}
	else
	{
		ft_strlcpy(data->prev_dir, data->path, PATH_MAX);
		getcwd(data->path, PATH_MAX);
	}
	free(dir);
}

void	print_echo(t_data *data)
{
	int	i;
	int	flag;

	flag = 1;
	if (!data->argv[1])
	{
		printf("\n");
		return ;
	}
	if (ft_strlen(data->argv[1]) == 2
		&& !ft_strncmp(data->argv[1], "-n", ft_strlen(data->argv[1])))
	{
		flag = 0;
		i = 1;
	}
	else
		i = 0;
	while (data->argv[++i])
		printf("%s ", data->argv[i]);
	if (flag)
		printf("\n");
	data->exit_status = 0;
}

void	print_env(t_data *data)
{
	int	i;

	i = -1;
	while (data->envp[++i])
		printf("%s\n", data->envp[i]);
}

void	change_env(t_data *data, int cmd)
{
	char	**old;
	char	*dup;
	char	*target;
	int		i;

	i = 0;
	while (data->argv[++i])
	{
		old = data->envp;
		if (change_env_helper(data, cmd, i, old))
			return ;
		dup = ft_strdup(data->argv[i]);
		target = trim_target(data->argv[i]);
		if (has_target(old, target) && cmd == 2)
			data->envp_len--;
		else if (!has_target(old, target) && cmd == 1)
			data->envp_len++;
		data->envp = create_envp(old, data, target);
		if (cmd == 1)
			data->envp[data->envp_len - 1] = ft_strdup(dup);
		free(dup);
		free(target);
		free_split(old);
	}
}

void	dispatch(t_data *data, int cmd_nb, int end, char *arg)
{
	int	old_stdout;

	old_stdout = dup(STDOUT_FILENO);
	if (data->pipe_nb)
		builtin_fd(cmd_nb, data, end);
	if (ft_strlen(arg) == 4 && !ft_strncmp(arg, "echo", ft_strlen(arg)))
		print_echo(data);
	else if (ft_strlen(arg) == 3 && !ft_strncmp(arg, "pwd", ft_strlen(arg)))
		printf("%s\n", data->path);
	else if (ft_strlen(arg) == 3 && !ft_strncmp(arg, "env", ft_strlen(arg)))
		print_env(data);
	if (dup2(old_stdout, STDOUT_FILENO) < 0)
		return (error(data, "Dup failed (3)", 1, 'e'));
	if (cmd_nb >= 1)
		close_pipe(cmd_nb, data);
}
