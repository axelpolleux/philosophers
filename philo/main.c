/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 07:51:47 by apolleux          #+#    #+#             */
/*   Updated: 2026/07/23 15:46:13 by axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	t_data	*args;

	if (ac < 5 || ac > 6)
		return (0);
	args = parser(av, ac - 1);
	if (!args)
		return (1);
	printf("%d\n", args->nb_philo);
	printf("%d\n", args->time_to_die);
	printf("%d\n", args->time_to_eat);
	printf("%d\n", args->time_to_sleep);
	printf("%d\n", args->nb_eat);
	philosophers(args);
	return (0);
}
