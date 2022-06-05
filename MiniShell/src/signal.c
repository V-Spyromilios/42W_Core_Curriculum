/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espyromi <espyromi@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 22:12:47 by espyromi          #+#    #+#             */
/*   Updated: 2022/02/10 22:12:48 by espyromi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	signal_handler(int signum, siginfo_t *info, void *unused)
{
	(void)unused;
	(void)info;
	if (signum == SIGINT)
	{
		printf("\b\b  \n");
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
	else if (signum == SIGQUIT)
		printf("\b\b  \b\b");
}

void	signal_init(void)
{
	struct sigaction	s;

	s.sa_flags = SA_SIGINFO;
	s.sa_sigaction = signal_handler;
	sigemptyset(&s.sa_mask);
	if (sigaction(SIGINT, &s, NULL) == -1)
		perror("Can't handle ctrl -C");
	if (sigaction(SIGQUIT, &s, NULL) == -1)
		perror("Can't handle ctrl -D");
}
