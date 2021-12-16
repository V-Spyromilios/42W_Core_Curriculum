/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espyromi <espyromi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:37:38 by espyromi          #+#    #+#             */
/*   Updated: 2021/12/16 17:59:09 by espyromi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv, char **env)
{
	int		ffd[2];
	char	***cmds;
	cmds = (char ***)malloc(2 * sizeof(char ***));
	char	**paths;
	paths = (char **)malloc(2 * sizeof(char *));
	int		pipes_fd[2];
	int		pid;

	if (argc != 5)
		exit(EXIT_FAILURE);
	check_in(ffd, argv);
	take_cmds(argv, cmds);
	find_paths(env, paths, cmds);

	if (pipe(pipes_fd) == -1)
	{
		perror("pipe got fucked (-1).\n");
		exit(EXIT_FAILURE);
	}
	pid = fork();
	if (pid == -1)
		perror("Fork-fucked.\n");
	if (pid != 0)
		call_parent(paths[0], cmds[0], ffd, pipes_fd);
	else
		call_child(paths[1], cmds[1], ffd, pipes_fd);	
		
		// // close(pipes_fd[0]);
	// }
	// {
		// dup2(ffd[1], 1);
		// wait(NULL);
		// close(pipes_fd[0]);
		// if (execve(*paths[1], cmd2,NULL) == -1)
		// 	// perror("execve failed (-1)");
		// 	printf("loustike to child");
		// close(pipes_fd[1]);
	// }
	
	// 	call_parent();
	// else
	// 	call_child();
	return (0);
}

void	check_in(int fd[], char **argv)
{
	if (access(argv[1], R_OK) == 0 && access(argv[4], W_OK) == 0)
	{
		fd[0] = open(argv[1], O_RDONLY);
		fd[1] = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (fd[0] == -1 || fd[1] == -1)
		{
			perror("open() returned -1\n");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		perror("access() failed.\n");
		exit(EXIT_FAILURE);
	}
}
