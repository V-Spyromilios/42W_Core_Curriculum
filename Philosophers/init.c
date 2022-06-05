#include "philosopher.h"

int	norminal(int argc, char **argv)
{
	int i = 1;
	if (argc < 5 || argc > 6) {
		printf ("INVALID NUMBER OF ARGUMENTS!\n<number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> OPTIONAL: [number_of_times_each_philosopher_must_eat]");
		return (0);
	}
	while (i < argc) {
		if (ft_atoi(argv[i]) <= 0) {
			printf("Invalid Argument Format: [%d] Please Pass Positive Values\n", i);
			return (0);
		}
		i++;
	}
	return (1);
}

void	forks_init(game *settings)
{
	int j;

	j = 0;
	settings->m_forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * settings->number_of_philos);
	while (j < settings->number_of_philos)
	{
		pthread_mutex_init(settings->m_forks + j, NULL);
		j++;
	}
}

void	phil_init(game *settings)
{
	philosopher *ph;
	int			i;

	i = 0;
	while (i < settings->number_of_philos)
	{
		ph = (philosopher *)malloc(sizeof(philosopher));
		ph->to_settings = settings;
		ph->id = i + 1;
		ph->last_meal = 0;
		ph->meals = 0;
		pthread_mutex_init(&(ph->m_eat), NULL);
		settings->to_phils[i] = ph;
		i++;
	}
}

int		init_settings(game *settings, int argc, char *argv[])
{
	settings->number_of_philos = ft_atoi(argv[1]);
	settings->time_to_die = ft_atoi(argv[2]);
	settings->time_to_eat = ft_atoi(argv[3]);
	settings->time_to_sleep = ft_atoi(argv[4]);
	settings->meals = -1;
	if (argc == 6)
		settings->meals = ft_atoi(argv[5]);
	settings->end = -1;
	pthread_mutex_init(&(settings->m_print), NULL);
	forks_init(settings);
	settings->to_phils = (philosopher **)malloc(settings->number_of_philos * sizeof(philosopher *));
	gettimeofday(&(settings->start), NULL);
	phil_init(settings);
	return (1);
}