/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tale-fau <tale-fau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 12:08:25 by tale-fau          #+#    #+#             */
/*   Updated: 2021/10/21 18:02:22 by tale-fau         ###   ########.fr       */
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
		info->philo[i].meal_eaten = 0;
		info->philo[i].last_meal = 0;
		info->philo[i].info = info;
		i++;
	}
	info->is_dead = FALSE;
	info->full = FALSE;
	if (pthread_mutex_init(&(info->writing), NULL) != 0)
		return (error(4));
	if (pthread_mutex_init(&(info->test), NULL) != 0)
		return (error(4));
	return (TRUE);
}

int	good_number_of_argument(int ac)
{
	return (ac == 5 || ac == 6);
}

int	main(int ac, char **av)
{
	t_info	info;

	if (good_number_of_argument(ac))
	{
		if (parsing(ac, av, &info) == FALSE)
			return (FALSE);
	}
	else
		return (error(2));
	if (init(&info) == FALSE)
		return (FALSE);
	if (starter(&info) == FALSE)
		return (FALSE);
	return (TRUE);
}
