/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tale-fau <tale-fau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 12:08:25 by tale-fau          #+#    #+#             */
/*   Updated: 2021/10/15 13:50:44 by tale-fau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	init(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->nb_philo)
	{
		if (pthread_mutex_init(&(info->fork[i]), NULL) != 0)
			return (error(4));
		info->philo[i].id = i;
		info->philo[i].left = i;
		info->philo[i].right = (info->philo[i].id + 1) % info->nb_philo;
		info->philo[i].meal = 0;
		info->philo[i].last_meal = 0;
		info->philo[i].info = info;
		i++;
	}
	info->is_dead = 0;
	if (pthread_mutex_init(&(info->writing), NULL) != 0)
		return (error(4));
	return (0);
}

int	main(int ac, char **av)
{
	t_info	info;

	if (ac == 5 || ac == 6)
	{
		if (!parsing(ac, av, &info))
			return (1);
	}
	else
		return (error(2));
	if (init(&info) == 1)
		return (1);
	if (starter(&info))
		return (1);
	return (0);
}
