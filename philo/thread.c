/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axel <axel@student.1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 17:07:32 by axel              #+#    #+#             */
/*   Updated: 2026/07/28 15:03:34 by axel             ###   ########.fr       */
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
