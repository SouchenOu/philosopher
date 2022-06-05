/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 15:33:56 by souchen           #+#    #+#             */
/*   Updated: 2022/05/30 13:55:37 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/philo_bonus.h"

static void	pars_arguments(t_elements *elements, int argc, char *argv[])
{
	elements->num_of_philo = ft_atoi(argv[1]);
	elements->time_to_die = ft_atoi(argv[2]);
	elements->time_to_eat = ft_atoi(argv[3]);
	elements->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		elements->num_time_must_eat = ft_atoi(argv[5]);
}

static int	check_args(t_elements *elements, int argc)
{
	if (elements->num_of_philo <= 0 || elements->num_of_philo > 200)
		return (ft_error("ERROR: wrong num of philo\n"));
	if (elements->time_to_die <= 60)
		return (ft_error("ERROR: wrong time to die\n"));
	if (elements->time_to_eat < 60)
		return (ft_error("ERROR: wrong time to eat\n"));
	if (elements->time_to_sleep < 60)
		return (ft_error("ERROR: wrong time to sleep\n"));
	if (argc == 6 && elements->num_time_must_eat <= 0)
		return (ft_error("ERROR: wrong num of must eat\n"));
	return (1);
}

int	arguments(t_elements *elements, int argc, char **argv)
{
	pars_arguments(elements, argc, argv);
	if (check_args(elements, argc) == 0)
		return (0);
	return (1);
}
