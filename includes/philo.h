/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tale-fau <tale-fau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 11:38:24 by tale-fau          #+#    #+#             */
/*   Updated: 2021/10/15 14:37:20 by tale-fau         ###   ########.fr       */
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

typedef struct s_philo
{
	pthread_t		thrd;
	int				id;
	int				right;
	int				left;
	int				meal;
	long long		last_meal;
	struct s_info	*info;
}	t_philo;

typedef struct s_info
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_meal;
	int				is_dead;
	long long		time_start;
	pthread_mutex_t	writing;
	t_philo			philo[200];
	pthread_mutex_t	fork[200];
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

#endif
