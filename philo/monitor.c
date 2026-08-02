/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 15:34:34 by apolleux          #+#    #+#             */
/*   Updated: 2026/08/02 20:02:05 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	finish(t_data *args, t_philo *philo, int i)
{
	if (is_finished(&philo[i]))
	{
		pthread_mutex_lock(&args->print_mutex);
		pthread_mutex_lock(&args->stop);
		args->is_dead = 1;
		pthread_mutex_unlock(&args->stop);
		printf("%ld %d %s\n",
			get_time_ms() - args->start_time, philo[i].id, DEAD);
		pthread_mutex_unlock(&args->print_mutex);
	}
}

void	monitor(t_data *args, t_philo *philo)
{
	int	i;
	int	happy_meal;

	while (!is_over(args))
	{
		i = 0;
		happy_meal = 0;
		while (i < args->nb_philo)
		{
			finish(args, philo, i);
			pthread_mutex_lock(philo[i].mutex_stat);
			if (args->nb_eat != -1 && philo[i].nb_eat >= args->nb_eat)
				happy_meal++;
			pthread_mutex_unlock(philo[i].mutex_stat);
			i++;
		}
		if (args->nb_eat != -1 && happy_meal == args->nb_philo)
		{
			pthread_mutex_lock(&args->stop);
			args->is_dead = 1;
			pthread_mutex_unlock(&args->stop);
		}
		usleep(1000);
	}
}

int	is_finished(t_philo *philo)
{
	long	last_meal;

	pthread_mutex_lock(philo->mutex_stat);
	last_meal = philo->last_meal;
	pthread_mutex_unlock(philo->mutex_stat);
	if (get_time_ms() - last_meal > philo->arguments->time_to_die)
		return (1);
	return (0);
}

int	is_over(t_data *args)
{
	int	res;

	pthread_mutex_lock(&args->stop);
	res = args->is_dead;
	pthread_mutex_unlock(&args->stop);
	return (res);
}
