/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 07:51:47 by apolleux          #+#    #+#             */
/*   Updated: 2026/07/15 10:44:44 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

void	philosophers(int *arguments)
{
	printf(": %d\n", arguments[0]);
	printf(": %d\n", arguments[1]);
	printf(": %d\n", arguments[2]);
	printf(": %d\n", arguments[3]);
	printf(": %d\n", arguments[4]);
}

int	main(int ac, char **av)
{
	int	*arguments;

	if (ac < 5 || ac > 6)
		return (0);
	philosophers(arguments);
}
