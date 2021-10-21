/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tale-fau <tale-fau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 11:58:11 by tale-fau          #+#    #+#             */
/*   Updated: 2021/10/21 15:57:55 by tale-fau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	display(t_info *info, int id, char *act)
{
	pthread_mutex_lock(&(info->writing));
	ft_putchar_fd('[', 1);
	ft_putstr_fd("\033[1;33m", 1);
	ft_putnbr_fd((long long)(find_time() - info->time_start), 1);
	ft_putstr_fd("\033[0;37m", 1);
	ft_putchar_fd(']', 1);
	ft_putstr_fd(" Philosopher nº", 1);
	ft_putnbr_fd(id + 1, 1);
	ft_putchar_fd(' ', 1);
	ft_putstr_fd(act, 1);
	ft_putchar_fd('\n', 1);
	if (ft_strncmp("\033[0;31mdied. 💀\n\033[0;37m", act, 10) != 0)
		pthread_mutex_unlock(&(info->writing));
}
