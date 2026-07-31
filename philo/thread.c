/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axel <axel@student.1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 17:07:32 by axel              #+#    #+#             */
/*   Updated: 2026/07/31 11:12:36 by apolleux         ###   ########.fr       */
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

	timestamp = get_time_ms() - philo->arguments->start_time;
	pthread_mutex_lock(&philo->arguments->print_mutex);
	pthread_mutex_lock(&philo->arguments->stop);
	if (!philo->arguments->is_dead)
		printf("%ld %d %s\n", timestamp, philo->id, status);
	pthread_mutex_unlock(&philo->arguments->stop);
	pthread_mutex_unlock(&philo->arguments->print_mutex);
}
