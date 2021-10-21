/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tale-fau <tale-fau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:08:31 by tale-fau          #+#    #+#             */
/*   Updated: 2021/10/21 19:21:20 by tale-fau         ###   ########.fr       */
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
	//ft_usleep(info->time_to_eat);
	usleep(info->time_to_eat * 1000);
	philo->meal_eaten++;
	pthread_mutex_unlock(&(info->fork[philo->left]));
	pthread_mutex_unlock(&(info->fork[philo->right]));
}

void	dis_death(t_info *info, int i, int *death)
{
	display(info, i, "\033[0;31mdied. 💀\n\033[0;37m");
	death = TRUE;
	return ;
}

void	grim_reaper(t_info *info)
{
	int	i;
	int	j;
	int	death;
	int	is_full;
	int	eaten;
	int	last;

	death = info->is_dead;
	is_full = info->full;
	while (death == FALSE || is_full == FALSE)
	{
		i = 0;
		j = 0;
		while (i < info->nb_philo)
		{
			if ((find_time() - info->philo[i].last_meal >= info->time_to_die))
				return (dis_death(info, i, &death));
			if (info->philo[i].meal_eaten >= info->nb_meal
				&& info->nb_meal != -1)
			{
				j++;
				if (j == info->nb_philo - 1)
				{
					is_full = TRUE;
					return ;
				}
			}
			i++;
		}
	}
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
		//ft_usleep(info->time_to_sleep);
		usleep(info->time_to_sleep * 1000);
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
		philo[i].last_meal = find_time();
		 if (pthread_create(&(philo[i].thrd), NULL, routine, &(philo[i])) != 0)
			return (error(3));
		i++;
	}
	grim_reaper(info);
	usleep(WAITING_TIME);
	i = 0;
	while (i < info->nb_philo)
	{
		pthread_detach(info->philo[i].thrd);
		i++;
	}
	return (TRUE);
}
