#include "philosopher.h"

void	*dinner(void	*philo)
{
	philosopher		*ph;
	game			*sett;
	int				left;
	int				right;

	ph = (philosopher *)philo;
	sett = ph->to_settings;
	left = ph->id - 1;
	right =ph->id; 
	if(right == sett->number_of_philos)
		right = 0;
	if (sett->number_of_philos == 1)
	{
		pthread_mutex_lock(sett->m_forks);
		print(ph, get_clock(sett), "has taken a fork");
		return (NULL);
	}
	if (ph->id % 2 == 0)
		usleep(sett->time_to_eat * 500);
	dining(sett, ph, right, left);
	return (NULL);
}

void	dining(game *settings, philosopher *ph, int right, int left)
{
	while (settings->end == -1 && (settings->number_of_philos == -1
		|| settings->meals != ph->meals))
	{
		pthread_mutex_lock(settings->m_forks + left);
		print(ph, get_clock(settings), "has taken a fork");
		pthread_mutex_lock(settings->m_forks + right);
		print(ph, get_clock(settings), "has taken a fork");
		pthread_mutex_lock(&(ph->m_eat));
		ph->last_meal = get_clock(settings);
		ph->meals += 1;
		print(ph, ph->last_meal, "is eating");
		pthread_mutex_unlock(&(ph->m_eat));
		wake_up(settings, settings->time_to_eat);
		pthread_mutex_unlock(settings->m_forks + left);
		pthread_mutex_unlock(settings->m_forks + right);
		if (settings->meals != -1 \
			&& settings->meals == ph->meals)
				return ;
		print(ph, get_clock(settings), "is sleeping");
		wake_up(settings, settings->time_to_sleep);
		print(ph, get_clock(settings), "is thinking");
	}
}

void	dine(game *data)
{
	int			i;
	int			nbr_of_philos;
	int			*arr;
	philosopher	*philos;

	nbr_of_philos = data->number_of_philos;
	arr = (int *)malloc(nbr_of_philos * sizeof(int));
	i = 0;
	while (i < nbr_of_philos)
	{
		arr[i] = 0;
		i++;
	}
	while (data->end == -1 && ft_sum(arr, data->number_of_philos) < data->number_of_philos)
	{
		i = 0;
		while (i < data->number_of_philos && data->end == -1 && ft_sum(arr, data->number_of_philos) < nbr_of_philos)
		{
			philos = data->to_phils[i];
			check_dead(data, philos);
			if (philos->meals == data->meals)
				arr[i] = 1;
			i++;
		}
	}
	free(arr);
}