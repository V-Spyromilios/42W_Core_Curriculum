#include "philosopher.h"

int 	main(int argc, char *argv[])
{
	game 		settings;
	pthread_t	*th;
	philosopher	*philo;
	int			i;

	i = 0;
	if (!norminal(argc, argv))
		return (-1);
	if (!init_settings(&settings, argc, argv))
		return (-2);
	th = malloc(sizeof(pthread_t *) * settings.number_of_philos);
	if (!th)
		return (-3);
	while (i < settings.number_of_philos)
	{
		philo = settings.to_phils[i];
		pthread_create(&th[i], NULL, &dinner, philo);
		i++;
	}
	dine(&settings);
	goodnight(&settings, th);
	usleep(42);
	return (0);
}
