#include "philosopher.h"

void	destroy_mutexes(game *settings)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&(settings->m_print));
	while (i < settings->number_of_philos)
	{
		pthread_mutex_destroy(settings->m_forks + i);
		pthread_mutex_destroy(&(settings->to_phils[i])->m_eat);
		i++;
	}
}

void	join_threads(game *settings, pthread_t *th)
{
	int j;

	j = 0;
	while (j < settings->number_of_philos)
	{
		pthread_join(th[j], NULL);
		j++;
	}
}

void	free_phils(game *settings)
{
	int	i;

	i = 0;
	while (i < settings->number_of_philos)
	{
		free((philosopher *) settings->to_phils[i]);
		i++;
	}
}

void	goodnight(game *settings, pthread_t *th)
{
	join_threads(settings, th);
	destroy_mutexes(settings);
	free_phils(settings);
	free(settings->to_phils);
	free(settings->m_forks);
	free(th);
}