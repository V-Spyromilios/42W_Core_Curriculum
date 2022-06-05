#ifndef PHILOSOPHER_H
#define PHILOSOPHER_H

#include <pthread.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]

struct s_philosopher;

typedef struct s_game {

	struct s_philosopher	**to_phils;
	pthread_mutex_t 	m_print;
	pthread_mutex_t 	*m_forks;
	struct timeval		start;
	int					number_of_philos;
	int 				time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					meals;
	int					end;
}						game;

typedef struct s_philosopher
{
	pthread_mutex_t		m_eat;
	game			*to_settings;
	int				last_meal;
	int				meals;
	int				id;
} 					philosopher;

//	dine.c
void	*dinner(void	*philo);
void	dining(game *settings, philosopher *ph, int right, int left);
void	dine(game *settings);

//	end.c
void	destroy_mutexes(game *settings);
void	join_threads(game *settings, pthread_t *th);
void	free_phils(game *settings);
void	goodnight(game *settings, pthread_t *th);

//	help.c
int		ft_atoi(const char *str);
int		ft_sum(int *arr, int len);
void	print(philosopher *ph, int msec,char *str);
int		ft_strncmp(char *s1, char *s2, size_t n);

//	init.c
int		norminal(int argc, char **argv);
void	forks_init(game *settings);
void	phil_init(game *settings);
int		init_settings(game *settings, int argc, char *argv[]);

//	time.c
void	check_dead(game *settings, philosopher *ph);
void	wake_up(game *settings, int sec);
int		get_clock(game *settings);

#endif