/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tale-fau <tale-fau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 15:46:31 by tale-fau          #+#    #+#             */
/*   Updated: 2021/10/28 15:02:04 by tale-fau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long long	assign_tmplatestmeal(t_info *info, int i)
{
	long long	ret;

	if (info->philo[i].last_meal == 0)
		ret = info->philo[i].first_meal;
	else
		ret = info->philo[i].last_meal;
	return (ret);
}

void	dis_death(t_info *info, int i)
{
	display(info, i, "died.\n");
	info->is_dead = TRUE;
	return ;
}

void	grim_reaper(t_info *info, int i, int j)
{
	long long	tmp_latestmeal;

	while (info->is_dead == FALSE || info->full == FALSE)
	{
		i = 0;
		j = 0;
		while (i < info->nb_philo)
		{
			tmp_latestmeal = assign_tmplatestmeal(info, i);
			if ((find_time() - tmp_latestmeal >= info->time_to_die))
				return (dis_death(info, i));
			if (info->philo[i].meal_eaten >= info->nb_meal
				&& info->nb_meal != -1)
			{
				j++;
				if (j == info->nb_philo - 1)
				{
					info->full = TRUE;
					return ;
				}
			}
			i++;
		}
	}
}
