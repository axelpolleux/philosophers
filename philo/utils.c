/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 11:38:35 by axel              #+#    #+#             */
/*   Updated: 2026/08/02 15:35:06 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static char	*remove_signs(char *str, int *sign)
{
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	*sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			*sign = -1;
		str++;
	}
	return (str);
}

int	ft_atol(char *str, int *out)
{
	long	res;
	int		sign;

	res = 0;
	str = remove_signs(str, &sign);
	if (*str < '0' || *str > '9')
		return (0);
	while (*str >= '0' && *str <= '9')
	{
		if (res > (LONG_MAX - (*str - '0')) / 10)
			return (0);
		res = res * 10 + (*str - '0');
		str++;
	}
	res *= sign;
	if (res < INT_MIN || res > INT_MAX)
		return (0);
	*out = (int)res;
	return (1);
}

long	get_time_ms(void)
{
	struct timeval	tv;
	long			time;

	gettimeofday(&tv, NULL);
	time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (time);
}

void	ft_usleep(long ms, t_philo *philo)
{
	long	start;

	start = get_time_ms();
	while (get_time_ms() - start < ms)
	{
		if (is_over(philo->arguments))
			break ;
		usleep(500);
	}
}
