/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tale-fau <tale-fau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 11:58:11 by tale-fau          #+#    #+#             */
/*   Updated: 2021/10/15 14:38:26 by tale-fau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	display(t_info *info, int id, char *act)
{
	pthread_mutex_lock(&(info->writing));
	ft_putchar_fd('[', 1);
	ft_putnbr_fd((long long)(find_time() - info->time_start), 1);
	ft_putchar_fd(']', 1);
	ft_putstr_fd(" Philo[", 1);
	ft_putnbr_fd(id, 1);
	ft_putchar_fd(']', 1);
	ft_putchar_fd(' ', 1);
	ft_putstr_fd(act, 1);
	ft_putchar_fd('\n', 1);
	if (ft_strncmp("is dead.\n", act, 9) != 0)
		pthread_mutex_unlock(&(info->writing));
}
