/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 07:51:54 by apolleux          #+#    #+#             */
/*   Updated: 2026/07/23 17:50:53 by axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*executions(void *arg)
{
	(void)arg;
	printf("Thread is executing\n");
	return (NULL);
}

void	philosophers(t_data *args)
{
	pthread_t	thread;
	int			i;

	i = 0;

	while (i < args->nb_philo)
	{
		pthread_create(&thread, NULL, executions, NULL);
		i++;
	}
	i = 0;
	while (i < args->nb_philo)
	{
		pthread_join(thread, NULL);
		i++;
	}
}
