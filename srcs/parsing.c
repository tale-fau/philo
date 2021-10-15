/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tale-fau <tale-fau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 12:48:58 by tale-fau          #+#    #+#             */
/*   Updated: 2021/10/14 17:37:03 by tale-fau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

char	*skip_zero(char *str)
{
	while (*str == '0')
		str++;
	return (str);
}

int	parsing(int ac, char **av, t_info *info)
{
	int		i;

	i = 0;
	while (++i < ac)
	{
		skip_zero(av[i]);
		if (!is_digit(av[i]))
			return (0);
	}
	info->nb_philo = ft_atoi(av[1]);
	info->time_to_die = ft_atoi(av[2]);
	info->time_to_eat = ft_atoi(av[3]);
	info->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		info->nb_meal = ft_atoi(av[5]);
	return (1);
}
