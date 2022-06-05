/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espyromi <espyromi@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 22:11:58 by espyromi          #+#    #+#             */
/*   Updated: 2022/02/10 22:12:01 by espyromi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	builtin_fd(int cmd_nb, t_data *data, int end)
{
	if (!end)
		if (dup2(data->pipe_fd[cmd_nb * 2 + 1], STDOUT_FILENO) < 0)
			return (error(data, "Dup failed", 0, 'e'));
}

char	*trim_target(char *target)
{
	char	*ret;
	char	**split;

	split = ft_split(target, '=');
	ret = ft_strdup(split[0]);
	free_split(split);
	return (ret);
}

char	*get_dir_name(t_data *data)
{
	char	*dir;
	char	*temp;

	if (data->argv[1] == NULL)
		dir = ft_strdup(getenv("HOME"));
	else if (data->argv[1][0] == '~')
	{
		temp = ft_substr(data->argv[1], 1, ft_strlen(data->argv[1]) - 1);
		dir = ft_strjoin(getenv("HOME"), temp);
		free(temp);
	}
	else if (ft_strlen(data->argv[1]) == 1
		&& ft_strncmp(data->argv[1], "-", 1) == 0)
		dir = ft_strdup(data->prev_dir);
	else
		dir = ft_strdup(data->argv[1]);
	return (dir);
}

int	has_target(char **envp, char *target)
{
	int		i;
	char	**split;

	i = -1;
	while (envp[++i])
	{
		split = ft_split(envp[i], '=');
		if (!ft_strncmp(target, split[0], ft_strlen(target))
			&& ft_strlen(target) == ft_strlen(split[0]))
		{
			free_split(split);
			return (1);
		}
		free_split(split);
	}
	return (0);
}

int	change_env_helper(t_data *data, int cmd, int i, char **old)
{
	if ((!has_target(old, data->argv[i]) && cmd == 2)
		|| (!ft_strchr(data->argv[i], '=') && cmd == 1)
		|| (!ft_strncmp(data->argv[i], "=", 1)))
		return (1);
	else
		return (0);
}
