/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tale-fau <tale-fau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 11:38:24 by tale-fau          #+#    #+#             */
/*   Updated: 2021/10/28 15:00:48 by tale-fau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

# define FALSE 1
# define TRUE 0
# define MAX_PHILOSOPHERS 200
# define NO_MAX_MEAL -1
# define WAITING_TIME 1500
# define LONG_WAITING_TIME 15000

typedef struct s_philo
{
	pthread_t		thrd;
	int				id;
	int				right;
	int				left;
	int				meal_eaten;
	long long		first_meal;
	long long		last_meal;
	struct s_info	*info;
}	t_philo;

typedef struct s_info
{
	int				full;
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_meal;
	int				is_dead;
	long long		time_start;
	pthread_mutex_t	writing;
	pthread_mutex_t	last_meal_mut;
	pthread_mutex_t	dead_mut;
	pthread_mutex_t	meal_mut;
	pthread_mutex_t	fork[200];
	t_philo			philo[200];
}	t_info;

int				error(int i);
int				is_digit(char *num);
int				parsing(int ac, char **av, t_info *info);
int				starter(t_info *info);
long int		ft_atoi(const char *str);
void			ft_putchar_fd(char c, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char *s, int fd);
long long int	find_time(void);
void			ft_usleep(long long int time);
void			display(t_info *info, int id, char *act);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			grim_reaper(t_info *info, int i, int j);

#endif
