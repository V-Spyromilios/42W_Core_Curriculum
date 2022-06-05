#include "philosopher.h"

void	check_dead(game *settings, philosopher *ph)
{
	int	milli;

	pthread_mutex_lock(&(ph->m_eat)); //timeout
	milli = get_clock(settings);
	if (milli > ph->last_meal + settings->time_to_die)
	{
		settings->end = 1;
		print(ph, milli, "died");
		pthread_mutex_unlock(&(ph->m_eat));
	}
	else
	{
		pthread_mutex_unlock(&(ph->m_eat));
		settings->end = -1;
	}
}

void	wake_up(game *settings, int sec)
{
	int wake;

	wake = get_clock(settings) + sec;
	while (settings->end == -1 && get_clock(settings) < wake)
		usleep(50);
}

int	get_clock(game *settings)
{
	struct timeval	current_time;
	int			milli;

	gettimeofday(&(current_time), NULL);
	if ((settings->start).tv_usec < current_time.tv_usec)
	{
		milli = (current_time.tv_usec - (settings->start).tv_usec) / 1000;
		milli += (current_time.tv_sec - (settings->start).tv_sec) * 1000;
	}
	else
	{
		milli = 1000 + (current_time.tv_usec - (settings->start).tv_usec) / 1000;
		milli += (current_time.tv_sec - (settings->start).tv_sec - 1) * 1000;
	}
	return (milli);
}