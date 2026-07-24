/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axel <axel@student.1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 17:07:32 by axel              #+#    #+#             */
/*   Updated: 2026/07/24 18:07:44 by axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_thread(t_data *args, t_philo philo)
{
	(void)args;
	pthread_t	thread;

	pthread_create(&thread, NULL, philo_routine, &philo);
	philo.thread = thread;
}