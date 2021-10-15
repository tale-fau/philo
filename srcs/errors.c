/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tale-fau <tale-fau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 12:18:49 by tale-fau          #+#    #+#             */
/*   Updated: 2021/10/15 11:46:17 by tale-fau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	putstr_err(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		write(2, &str[i], 1);
	return (1);
}

int	error(int i)
{
	static char	*str[5] = {"Error: 5 arg parser\n"
		, "Error: 6 arg pars\n"
		, "Error: number of args\n"
		, "Error: creating thread failure\n"
		, "Error: mutex initialization failure\n"};

	return (putstr_err(str[i]));
}
