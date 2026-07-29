/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 07:51:54 by apolleux          #+#    #+#             */
/*   Updated: 2026/07/29 17:32:54 by axel             ###   ########.fr       */
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
		philos[i].mutex_stat = &args->meal_mutexes[i];
		i++;
	}
}

void	print_philo(t_philo *philo, char *status)
{
	long	timestamp;

	timestamp = get_time_ms() - philo->arguments->start_time;
	pthread_mutex_lock(&philo->arguments->print_mutex);
	printf("%ld %d %s\n", timestamp, philo->id, status);
	pthread_mutex_unlock(&philo->arguments->print_mutex);

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
	content_routine(philo);
	return (NULL);
}

void	philosophers(t_data *args)
{
	t_philo	*philos;

	args->forks = malloc(sizeof(pthread_mutex_t) * args->nb_philo);
	args->meal_mutexes = malloc(sizeof(pthread_mutex_t) * args->nb_philo);
	philos = malloc(sizeof(t_philo) * args->nb_philo);
	init_mutexes(args);
	init_philo(args, philos);
	create_threads(philos, args);
	join_threads(philos, args);
	destroy_mutexes(args);
	free(args->forks);
	free(philos);
}
