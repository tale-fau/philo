/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tale-fau <tale-fau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:08:31 by tale-fau          #+#    #+#             */
/*   Updated: 2021/10/15 14:41:09 by tale-fau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	cantina(t_philo *philo)
{
	t_info	*info;

	info = philo->info;
	pthread_mutex_lock(&(info->fork[philo->left]));
	display(info, philo->id, "has taken a fork.\n");
	pthread_mutex_lock(&(info->fork[philo->right]));
	display(info, philo->id, "has taken a fork.\n");
	philo->last_meal = find_time();
	display(info, philo->id, "is eating.\n");
	ft_usleep(info->time_to_eat);
	pthread_mutex_unlock(&(info->fork[philo->left]));
	pthread_mutex_unlock(&(info->fork[philo->right]));
}

/* void	debug(t_info *info, t_philo *philo)
{
	pthread_mutex_lock(&(info->writing));
	printf("id = %d, right = %d, left = %d, last meal = %lld\n", philo->id, philo->right, philo->left, philo->last_meal);
	pthread_mutex_unlock(&(info->writing));
} */

void	grim_reaper(t_info *info)
{
	int	i;

	while (info->is_dead == 0)
	{
		i = 0;
		while (i < info->nb_philo)
		{
			if ((find_time() - info->philo[i].last_meal >= info->time_to_die))
			{
				display(info, i, "is dead.\n");
				info->is_dead = 1;
			}
			i++;
		}
	}
	i = 0;
	while (i < info->nb_philo)
	{
		pthread_detach(info->philo[i].thrd);
		i++;
	}
}

static void	*routine(void *param)
{
	t_philo	*philo;
	t_info	*info;

	philo = (t_philo *)param;
	info = philo->info;
//	debug(info, philo);
	if (philo->id % 2)
		usleep(15000);
	while (info->is_dead == 0)
	{
		cantina(philo);
		display(info, philo->id, "is sleeping.\n");
		ft_usleep(info->time_to_sleep);
		display(info, philo->id, "is thinking.\n");
	}
	return (0);
}

int	starter(t_info *info)
{
	t_philo	*philo;
	int		ret;
	int		i;

	philo = info->philo;
	i = 0;
	ret = 0;
	info->time_start = find_time();
	while (i < info->nb_philo)
	{
		 if (pthread_create(&(philo[i].thrd), NULL, routine, &(philo[i])) != 0)
			return (error(3));
		philo[i].last_meal = find_time();
		i++;
	}
	grim_reaper(info);
	return (1);
}
