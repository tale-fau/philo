/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tale-fau <tale-fau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 16:33:05 by tale-fau          #+#    #+#             */
/*   Updated: 2021/11/07 15:37:53 by tale-fau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ftstrlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

long int	ft_atoi(const char *str)
{
	int		i;
	long	result;

	i = 0;
	result = 0;
	if (str[0] == '\0')
		return (ERROR);
	str = skip_zero((char *)str);
	if (ftstrlen(str) > 10)
		return (ERROR);
	else if (ftstrlen(str) == 10)
		if (ft_strncmp(str, "2147483647", 10) > 0)
			return (ERROR);
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + ((int)str[i++] - '0');
	return (result);
}
