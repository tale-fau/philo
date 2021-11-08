/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tale-fau <tale-fau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 14:38:08 by tale-fau          #+#    #+#             */
/*   Updated: 2021/11/07 15:07:51 by tale-fau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	*routine(void *param)
{
	t_philo	*philo;
	t_info	*info;

	philo = (t_philo *)param;
	info = philo->info;
	if (philo->id % 2)
		usleep(MID_WAITING_TIME);
	while (1)
	{
		pthread_mutex_lock(&info->is_dead_mut);
		if (info->is_dead == TRUE)
			break ;
		pthread_mutex_unlock(&info->is_dead_mut);
		pthread_mutex_lock(&info->full_mut);
		if (info->full == TRUE)
		{
			pthread_mutex_unlock(&info->full_mut);
			break ;
		}
		pthread_mutex_unlock(&info->full_mut);
		loop(info, philo);
	}
	return (TRUE);
}

int	thrd_maker(t_info *info)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = info->philo;
	while (i < info->nb_philo)
	{
		 if (pthread_create(&(philo[i].thrd), NULL, routine, &(philo[i])) != 0)
			return (FALSE);
		philo[i].first_meal = find_time();
		i++;
	}
	return (TRUE);
}

int	mutex_destroyer(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->nb_philo)
	{
		pthread_mutex_destroy(&info->fork[i]);
		pthread_mutex_destroy(&info->philo[i].meal_eaten_mut);
		i++;
	}
	pthread_mutex_destroy(&info->writing);
	pthread_mutex_destroy(&info->is_dead_mut);
	pthread_mutex_destroy(&info->last_meal_mut);
	return (TRUE);
}

void	loop(t_info *info, t_philo *philo)
{
	cantina(philo);
	display(info, philo->id, "is sleeping.\n", 13);
	ft_usleep(info->time_to_sleep);
	display(info, philo->id, "is thinking.\n", 13);
}
