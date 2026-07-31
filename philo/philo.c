/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 07:51:54 by apolleux          #+#    #+#             */
/*   Updated: 2026/07/31 11:19:06 by apolleux         ###   ########.fr       */
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
		philos[i].last_meal = args->start_time;
		philos[i].arguments = args;
		philos[i].thread = 0;
		philos[i].left_fork = &args->forks[i];
		philos[i].right_fork = &args->forks[(i + 1) % args->nb_philo];
		philos[i].mutex_stat = &args->meal_mutexes[i];
		i++;
	}
}

void	content_routine(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	print_philo(philo, FORK);
	pthread_mutex_lock(philo->left_fork);
	print_philo(philo, FORK);
	pthread_mutex_lock(philo->mutex_stat);
	philo->last_meal = get_time_ms();
	pthread_mutex_unlock(philo->mutex_stat);
	print_philo(philo, EAT);
	ft_usleep(philo->arguments->time_to_eat, philo);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	print_philo(philo, SLEEP);
	ft_usleep(philo->arguments->time_to_sleep, philo);
	print_philo(philo, THINK);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2)
		ft_usleep(10, philo);
	while (!philo->arguments->is_dead)
		content_routine(philo);
	return (NULL);
}

static void	monitor(t_data *args, t_philo *philo)
{
	int	i;

	while (!args->is_dead)
	{
		i = 0;
		while (i < args->nb_philo)
		{
			if (is_finished(&philo[i]))
			{
				pthread_mutex_lock(&args->stop);
				args->is_dead = 1;
				pthread_mutex_unlock(&args->stop);
				print_philo(&philo[i], DEAD);
			}
			i++;
		}
	}
}

void	philosophers(t_data *args)
{
	t_philo	*philos;

	args->forks = malloc(sizeof(pthread_mutex_t) * args->nb_philo);
	args->meal_mutexes = malloc(sizeof(pthread_mutex_t) * args->nb_philo);
	philos = malloc(sizeof(t_philo) * args->nb_philo);
	init_mutexes(args);
	init_philo(args, philos);
	args->start_time = get_time_ms();
	create_threads(philos, args);
	monitor(args, philos);
	join_threads(philos, args);
	destroy_mutexes(args);
	free(args->meal_mutexes);
	free(args->forks);
	free(philos);
}
