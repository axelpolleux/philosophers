/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axel <axel@student.1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 17:07:32 by axel              #+#    #+#             */
/*   Updated: 2026/07/31 15:42:46 by axel             ###   ########.fr       */
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
	if (!philo->arguments->is_dead)
	{
		timestamp = get_time_ms() - philo->arguments->start_time;
		printf("%ld %d %s\n", timestamp, philo->id, status);
	}
	pthread_mutex_unlock(&philo->arguments->print_mutex);
}
