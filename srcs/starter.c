/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tale-fau <tale-fau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:08:31 by tale-fau          #+#    #+#             */
/*   Updated: 2021/10/28 14:03:32 by tale-fau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	cantina(t_philo *philo)
{
	t_info	*info;

	info = philo->info;
	pthread_mutex_lock(&(info->fork[philo->left]));
	display(info, philo->id, "has taken a fork. 1️⃣\n");
	pthread_mutex_lock(&(info->fork[philo->right]));
	display(info, philo->id, "has taken a fork. 2️⃣\n");
	philo->last_meal = find_time();
	display(info, philo->id, "is eating. 🍝\n");
	ft_usleep(info->time_to_eat);
	pthread_mutex_unlock(&(info->fork[philo->left]));
	pthread_mutex_unlock(&(info->fork[philo->right]));
	philo->meal_eaten++;
}

static void	*routine(void *param)
{
	t_philo	*philo;
	t_info	*info;
	int		death;

	philo = (t_philo *)param;
	info = philo->info;
	if (philo->id % 2)
		usleep(LONG_WAITING_TIME);
	death = info->is_dead;
	while (death == FALSE || philo->meal_eaten <= info->nb_meal)
	{
		cantina(philo);
		display(info, philo->id, "is sleeping. 😴\n");
		ft_usleep(info->time_to_sleep);
		display(info, philo->id, "is thinking. 🤔\n");
	}
	return (TRUE);
}

int	starter(t_info *info)
{
	t_philo	*philo;
	int		i;

	philo = info->philo;
	i = 0;
	info->time_start = find_time();
	while (i < info->nb_philo)
	{
		 if (pthread_create(&(philo[i].thrd), NULL, routine, &(philo[i])) != 0)
			return (error(3));
		philo[i].first_meal = find_time();
		i++;
	}
	grim_reaper(info, 0, 0);
	usleep(WAITING_TIME);
	i = 0;
	while (i < info->nb_philo)
	{
		pthread_detach(info->philo[i].thrd);
		i++;
	}
	return (TRUE);
}
