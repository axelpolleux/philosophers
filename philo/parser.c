/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axel <axel@student.1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 10:10:32 by axel              #+#    #+#             */
/*   Updated: 2026/07/21 17:22:45 by axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_nb(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	*parser(char **args, int len)
{
	int	i;
	int	*res;

	i = 1;
	res = malloc(sizeof(int) * len);
	while (args[i])
	{
		if (!ft_atol(args[i], &res[i - 1]) || !is_nb(args[i]) || res < 0)
			return (0);
		i++;
	}
	return (res);
}
