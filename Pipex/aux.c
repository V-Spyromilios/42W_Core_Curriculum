/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espyromi <espyromi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:37:57 by espyromi          #+#    #+#             */
/*   Updated: 2021/12/16 17:59:54 by espyromi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//splits the argv.
void	take_cmds(char **argv, char ***cmds)
{
	cmds[0] = ft_split(argv[2], 32);
	cmds[1] = ft_split(argv[3], 32);
}

//find PATH in env. find exec in PATH
void	find_paths(char **env, char **paths, char ***cmds)
{
	char	*s;
	char	*path;
	char	**splitted;
	
	s = "PATH";
	while (*env)
	{
		if (ft_strncmp(*env, s, 4) == 0)
		{
			path = (char *)malloc(ft_strlen(*env) * sizeof(char));
			path = ft_memcpy(path, *env, ft_strlen(*env));
			break ;
		}
		(env++);
	}
	splitted = ft_split(path + 5, 58);
	free(path);
	paths[0] = try_splitted(*cmds[0], splitted);
	paths[1] = try_splitted(*cmds[1], splitted);
}

char	*try_splitted(char *cmds, char **splitted)
{
	char	*testpath;
	char	*cmd;
	char	*c;

	c = (char *)malloc(2);
	c[0] = '/';
	c[1] = '\0';
	cmd = ft_strjoin(c, cmds);
	testpath = find_exe(splitted, &cmd);
	return (testpath);
}

char	*find_exe(char **splitted, char **cmd)
{
	char	*test;
	char	**runner;

	runner = splitted;
	while (*runner)
	{
		test = ft_strjoin(*runner, *cmd);
		if (access(test, X_OK) == -1)
			free(test);
		else
			break ;
		(runner)++;
	}
	return (test);
}

void	call_child(char *path, char **cmd, int ffd[], int pipes_fd[])
{
	dup2(ffd[1], 1);
	close(pipes_fd[1]);
	wait(NULL);
	if (execve(path, cmd, NULL) == -1)
		perror("execve failed (-1)");
	close(pipes_fd[0]);
}

void	call_parent(char *path, char **cmd, int ffd[], int pipes_fd[])
{
	printf("path: %s\n", path);
	printf("cmd: %s\n", *cmd);
	dup2(ffd[0], 0);
	close(pipes_fd[0]);
	if (execve(path, cmd, NULL) == -1)
		perror("execve failed (-1)");
	close(pipes_fd[0]);
}