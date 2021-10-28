/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tale-fau <tale-fau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 11:58:11 by tale-fau          #+#    #+#             */
/*   Updated: 2021/10/28 15:01:17 by tale-fau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	display(t_info *info, int id, char *act)
{
	pthread_mutex_lock(&(info->writing));
	ft_putchar_fd('[', 1);
	ft_putnbr_fd((long long)(find_time() - info->time_start), 1);
	ft_putchar_fd(']', 1);
	write(1, " Philosopher ", 13);
	ft_putnbr_fd(id + 1, 1);
	ft_putchar_fd(' ', 1);
	write(1, act, ft_strlen(act));
	ft_putchar_fd('\n', 1);
	if (ft_strncmp("died.", act, 5) != 0)
		pthread_mutex_unlock(&(info->writing));
}
