/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 07:52:15 by apolleux          #+#    #+#             */
/*   Updated: 2026/07/28 09:33:46 by axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_data
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_eat;
	pthread_mutex_t	*forks;
}	t_data;

typedef struct s_philo
{
	int				nb_eat;
	int				id;
	long			last_meal;
	t_data			*arguments;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*mutex_stat;
}	t_philo;

t_data	*parser(char **args, int len);
int		ft_atol(char *str, int *out);
void	philosophers(t_data *arguments);
void	*philo_routine(void *arg);

// mutexes
void	init_mutexes(t_data *args);
void	destroy_mutexes(t_data *args);

// threads
void	create_threads(t_philo *philos, t_data *args);
void	join_threads(t_philo *philos, t_data *args);

#endif
