/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tale-fau <tale-fau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 12:18:49 by tale-fau          #+#    #+#             */
/*   Updated: 2021/11/08 15:54:45 by tale-fau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	putstr_err(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		write(2, &str[i], 1);
	return (FALSE);
}

int	error(int i)
{
	static char	*str[8] = {"Error: parsing error.\n"
		, "Error: 6 arg pars.\n"
		, "Error: number of args.\n"
		, "Error: thread creation failure.\n"
		, "Error: mutex initialization failure.\n"
		, "Error: do not test with more than 200 philosophers.\n"
		, "Error: you have to test with at least 1 philosopher.\n"
		, "Error: issue with mutex destruction.\n"};

	return (putstr_err(str[i]));
}
