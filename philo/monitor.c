/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 15:34:34 by apolleux          #+#    #+#             */
/*   Updated: 2026/08/02 16:59:41 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	monitor(t_data *args, t_philo *philo)
{
	int	i;

	while (!is_over(args))
	{
		i = 0;
		while (i < args->nb_philo)
		{
			if (is_finished(&philo[i]))
			{
				print_philo(&philo[i], DEAD);
				pthread_mutex_lock(&args->stop);
				args->is_dead = 1;
				pthread_mutex_unlock(&args->stop);
			}
			i++;
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
