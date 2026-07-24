/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 07:51:54 by apolleux          #+#    #+#             */
/*   Updated: 2026/07/24 17:25:23 by axel             ###   ########.fr       */
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
		philos[i].left_fork = NULL;
		philos[i].right_fork = NULL;
		philos[i].mutex_stat = NULL;
		i++;
	}
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo  = (t_philo *)arg;
	printf("Philo actif: %d\n", philo->id);
	return (NULL);
}

void	philosophers(t_data *args)
{
	int		i;
	t_philo	*philos;

	i = 0;
	philos = malloc(sizeof(t_philo) * args->nb_philo);
	init_philo(args, philos);
	while (i < args->nb_philo)
	{
		philo_thread(args, philos[i]);
		i++;
	}
}
