/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 17:07:32 by axel              #+#    #+#             */
/*   Updated: 2026/08/02 18:58:56 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_threads(t_philo *philos, t_data *args)
{
	int	i;

	i = 0;
	while (i < args->nb_philo)
	{
		pthread_create(&philos[i].thread, NULL, philo_routine, &philos[i]);
		i++;
	}
}

void	join_threads(t_philo *philos, t_data *args)
{
	int	i;

	i = 0;
	while (i < args->nb_philo)
	{
		pthread_join(philos[i].thread, NULL);
		i++;
	}
}

void	print_philo(t_philo *philo, char *status)
{
	long	timestamp;

	pthread_mutex_lock(&philo->arguments->print_mutex);
	if (!is_over(philo->arguments))
	{
		timestamp = get_time_ms() - philo->arguments->start_time;
		printf("%ld %d %s\n", timestamp, philo->id, status);
	}
	pthread_mutex_unlock(&philo->arguments->print_mutex);
}

void	philo_alone(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	print_philo(philo, FORK);
	while (!is_over(philo->arguments))
		usleep(500);
	pthread_mutex_unlock(philo->right_fork);
}
