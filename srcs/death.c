/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tale-fau <tale-fau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 15:46:31 by tale-fau          #+#    #+#             */
/*   Updated: 2021/11/07 15:01:37 by tale-fau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long long	assign_tmplatestmeal(t_info *info, int i)
{
	long long	ret;

	pthread_mutex_lock(&info->last_meal_mut);
	if (info->philo[i].last_meal == 0)
		ret = info->philo[i].first_meal;
	else
		ret = info->philo[i].last_meal;
	pthread_mutex_unlock(&info->last_meal_mut);
	return (ret);
}

void	dis_death(t_info *info, int i)
{
	display(info, i, "died.\n", 6);
	pthread_mutex_lock(&info->is_dead_mut);
	info->is_dead = TRUE;
	pthread_mutex_unlock(&info->is_dead_mut);
	return ;
}

void	grim_reaper(t_info *info, int i, int j, long long tmp_latestmeal)
{
	while (info->is_dead == FALSE || info->full == FALSE)
	{
		i = -1;
		j = -1;
		while (++i < info->nb_philo)
		{
			tmp_latestmeal = assign_tmplatestmeal(info, i);
			if ((find_time() - tmp_latestmeal >= info->time_to_die))
				return (dis_death(info, i));
			pthread_mutex_lock(&info->philo[i].meal_eaten_mut);
			if (info->philo[i].meal_eaten >= info->nb_meal
				&& info->nb_meal != NO_MAX_MEAL)
			{
				pthread_mutex_unlock(&info->philo[i].meal_eaten_mut);
				if (++j == info->nb_philo - 1)
				{
					pthread_mutex_lock(&info->full_mut);
					info->full = TRUE;
					pthread_mutex_unlock(&info->full_mut);
					return ;
				}
			}
			pthread_mutex_unlock(&info->philo[i].meal_eaten_mut);
		}
	}
}
