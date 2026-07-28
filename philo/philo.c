/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 07:51:54 by apolleux          #+#    #+#             */
/*   Updated: 2026/07/28 10:15:04 by axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_philo(t_data *args, t_philo *philos)
{
	int			i;

	i = 0;
	while (i < args->nb_philo)
	{
		philos[i].nb_eat = 0;
		philos[i].id = i + 1;
		philos[i].last_meal = 0;
		philos[i].arguments = args;
		philos[i].thread = NULL;
		philos[i].left_fork = &args->forks[i];
		philos[i].right_fork = &args->forks[(i + 1) % args->nb_philo];
		philos[i].mutex_stat = NULL;
		i++;
	}
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo  = (t_philo *)arg;
	
	return (NULL);
}

void	philosophers(t_data *args)
{
	t_philo	*philos;

	args->forks = malloc(sizeof(pthread_mutex_t) * args->nb_philo);
	philos = malloc(sizeof(t_philo) * args->nb_philo);
	init_mutexes(args);
	init_philo(args, philos);
	create_threads(philos, args);
	join_threads(philos, args);
	destroy_mutexes(args);
	free(args->forks);
	free(philos);
}
