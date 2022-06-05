/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 11:14:31 by souchen           #+#    #+#             */
/*   Updated: 2022/05/30 10:40:01 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/philo.h"

static int	create_philos(t_elements *elements)
{
	int			i;
	pthread_t	thread;

	gettimeofday(&elements->time_create, NULL);
	i = 0;
	elements->finish_code = 0;
	elements->number_final_of_eat_philo = 0;
	while (i < elements->num_of_philo)
	{
		elements->philos->number_time_eat = 0;
		elements->philos[i].last_time_eat = elements->time_create;
		if (pthread_create(&elements->philos[i].thread, NULL, \
					&philo, &elements->philos[i]) != 0)
			return (0);
		if (pthread_create(&thread, NULL, die, &elements->philos[i]) != 0)
			return (0);
		++i;
	}	
	if (elements->num_time_must_eat != 0)
	{
		if (pthread_create(&thread, NULL, each_must_eat, elements) != 0)
			return (0);
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_elements	elements;

	elements.num_time_must_eat = 0;
	if (argc != 5 && argc != 6)
		return (ft_error("ERROR: wrong argc\n"));
	if (initial(&elements, argc, argv) == 0)
		return (1);
	create_philos(&elements);
	free_join_philos(&elements);
	return (0);
}
