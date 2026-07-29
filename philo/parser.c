/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axel <axel@student.1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 10:10:32 by axel              #+#    #+#             */
/*   Updated: 2026/07/29 11:29:00 by axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_nb(char *str)
{
	int	i;

	i = 0;
	if (!str[0])
		return (0);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

static void	define_data(char **args, int len, t_data *data)
{
	data->start_time = get_time_ms();
	ft_atol(args[1], &data->nb_philo);
	ft_atol(args[2], &data->time_to_die);
	ft_atol(args[3], &data->time_to_eat);
	ft_atol(args[4], &data->time_to_sleep);
	if (len == 5)
		ft_atol(args[5], &data->nb_eat);
	else
		data->nb_eat = -1;
}

t_data	*parser(char **args, int len)
{
	int		i;
	int		tmp;
	t_data	*res;

	i = 1;
	tmp = 0;
	res = malloc(sizeof(t_data));
	if (!res)
		return (0);
	while (args[i])
	{
		if (!is_nb(args[i]) || !ft_atol(args[i], &tmp) || tmp < 0)
		{
			free(res);
			return (0);
		}
		i++;
	}
	define_data(args, len, res);
	return (res);
}
