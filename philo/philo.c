/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 07:51:54 by apolleux          #+#    #+#             */
/*   Updated: 2026/07/22 18:39:03 by axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*executions(void *arg)
{
	(void)arg;
	printf("Thread is executing\n");
	return (NULL);
}

void	philosophers(int *arguments)
{
	int	i;

	i = 0;
	(void)arguments;
	pthread_t	thread;

	while (i < arguments[0])
	{
		pthread_create(&thread, NULL, executions, NULL);
		pthread_join(thread, NULL);
		i++;
	}
}
