/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tale-fau <tale-fau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 12:48:58 by tale-fau          #+#    #+#             */
/*   Updated: 2021/10/16 17:10:46 by tale-fau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

char	*skip_zero(char *str)
{
	while (*str == '0')
		str++;
	return (str);
}

void	get_meal_number(int ac, char **av, t_info *info)
{
	if (ac == 6)
		info->nb_meal = ft_atoi(av[5]);
	else
		info->nb_meal = NO_MAX_MEAL;
}

int	get_arguments(int ac, char **av, t_info *info)
{
	info->nb_philo = ft_atoi(av[1]);
	if (info->nb_philo > MAX_PHILOSOPHERS)
		return (error(5));
	info->time_to_die = ft_atoi(av[2]);
	info->time_to_eat = ft_atoi(av[3]);
	info->time_to_sleep = ft_atoi(av[4]);
	get_meal_number(ac, av, info);
	return (TRUE);
}

int	parsing(int ac, char **av, t_info *info)
{
	int		i;

	i = 0;
	while (++i < ac)
	{
		skip_zero(av[i]);
		if (!is_digit(av[i]))
			return (error(0));
	}
	if (get_arguments(ac, av, info) == FALSE)
		return (FALSE);
	return (TRUE);
}
