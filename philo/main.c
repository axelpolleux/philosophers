/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 07:51:47 by apolleux          #+#    #+#             */
/*   Updated: 2026/07/20 12:54:51 by axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	int	*arguments;

	if (ac < 5 || ac > 6)
		return (0);
	arguments = parser(av, ac - 1);
	if (!arguments)
		return (0);
	printf("It's ok !");
	return (1);
}
