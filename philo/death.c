/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 15:34:34 by apolleux          #+#    #+#             */
/*   Updated: 2026/08/02 15:35:06 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
