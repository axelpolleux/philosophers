/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 07:51:54 by apolleux          #+#    #+#             */
/*   Updated: 2026/08/01 19:12:59 by apolleux         ###   ########.fr       */
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
	pthread_mutex_t	*first;
	pthread_mutex_t	*second;

	if (philo->id % 2)
	{
		first = philo->right_fork;
		second = philo->left_fork;
	}
	else
	{
		first = philo->left_fork;
		second = philo->right_fork;
	}
	pthread_mutex_lock(first);
	print_philo(philo, FORK);
	pthread_mutex_lock(second);
	print_philo(philo, FORK);
	pthread_mutex_lock(philo->mutex_stat);
	philo->last_meal = get_time_ms();
	pthread_mutex_unlock(philo->mutex_stat);
	print_philo(philo, EAT);
	ft_usleep(philo->arguments->time_to_eat, philo);
	pthread_mutex_unlock(second);
	pthread_mutex_unlock(first);
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
	while (!is_over(philo->arguments))
		content_routine(philo);
	return (NULL);
}

static void	monitor(t_data *args, t_philo *philo)
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
		ft_usleep(1000, philo);
	}
}

void	philosophers(t_data *args)
{
	t_philo	*philos;

	args->forks = malloc(sizeof(pthread_mutex_t) * args->nb_philo);
	args->meal_mutexes = malloc(sizeof(pthread_mutex_t) * args->nb_philo);
	philos = malloc(sizeof(t_philo) * args->nb_philo);
	init_mutexes(args);
	args->start_time = get_time_ms();
	init_philo(args, philos);
	create_threads(philos, args);
	monitor(args, philos);
	join_threads(philos, args);
	destroy_mutexes(args);
	free(args->meal_mutexes);
	free(args->forks);
	free(philos);
}
