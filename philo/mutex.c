/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axel <axel@student.1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 16:14:28 by axel              #+#    #+#             */
/*   Updated: 2026/07/28 15:07:47 by axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_mutexes(t_data *args)
{
	int	i;

	i = 0;
	while (i < args->nb_philo)
	{
		pthread_mutex_init(&args->forks[i], NULL);
		i++;
	}
}

void	destroy_mutexes(t_data *args)
{
	int	i;

	i = 0;
	while (i < args->nb_philo)
	{
		pthread_mutex_destroy(&args->forks[i]);
		i++;
	}
}
