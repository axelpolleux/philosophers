/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 07:52:15 by apolleux          #+#    #+#             */
/*   Updated: 2026/08/02 18:46:39 by apolleux         ###   ########.fr       */
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

# define FORK	"has taken a fork"
# define EAT	"is eating"
# define THINK	"is thinking"
# define SLEEP	"is sleeping"
# define DEAD	"died"

typedef struct s_data
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_eat;
	long			start_time;
	int				is_dead;
	pthread_mutex_t	stop;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*meal_mutexes;
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

// main
void	philosophers(t_data *arguments);
t_data	*parser(char **args, int len);

// mutexes
void	init_mutexes(t_data *args);
void	destroy_mutexes(t_data *args);

// threads
void	create_threads(t_philo *philos, t_data *args);
void	join_threads(t_philo *philos, t_data *args);
void	print_philo(t_philo *philo, char *status);
void	philo_alone(t_philo *philo);
void	*philo_routine(void *arg);

// utils
int		ft_atol(char *str, int *out);
long	get_time_ms(void);
void	ft_usleep(long ms, t_philo *philo);

// death
int		is_over(t_data *args);
int		is_finished(t_philo *philo);
void	monitor(t_data *args, t_philo *philo);

#endif
