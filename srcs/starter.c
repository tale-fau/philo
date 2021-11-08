/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tale-fau <tale-fau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:08:31 by tale-fau          #+#    #+#             */
/*   Updated: 2021/11/08 15:51:58 by tale-fau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	cantina(t_philo *philo)
{
	t_info	*info;

	info = philo->info;
	pthread_mutex_lock(&(info->fork[philo->left]));
	display(info, philo->id, "has taken a fork.\n", 18);
	pthread_mutex_lock(&(info->fork[philo->right]));
	display(info, philo->id, "has taken a fork.\n", 18);
	pthread_mutex_lock(&info->last_meal_mut);
	philo->last_meal = find_time();
	pthread_mutex_unlock(&info->last_meal_mut);
	display(info, philo->id, "is eating.\n", 11);
	ft_usleep(info->time_to_eat);
	pthread_mutex_unlock(&(info->fork[philo->left]));
	pthread_mutex_unlock(&(info->fork[philo->right]));
	pthread_mutex_lock(&philo->meal_eaten_mut);
	philo->meal_eaten++;
	pthread_mutex_unlock(&philo->meal_eaten_mut);
}

int	starter(t_info *info)
{
//	t_philo	*philo;
	int		i;

//	philo = info->philo;
	i = 0;
	info->time_start = find_time();
	if (thrd_maker(info) == FALSE)
		return (error(3));
	grim_reaper(info, 0, 0, 0);
	usleep(LONG_WAITING_TIME);
	while (i < info->nb_philo)
	{
		if (pthread_detach(info->philo[i].thrd) != 0)
			break ;
		i++;
	}
	return (TRUE);
}
