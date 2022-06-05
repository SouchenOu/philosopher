/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 11:14:31 by souchen           #+#    #+#             */
/*   Updated: 2022/05/30 14:02:29 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/philo_bonus.h"

static void	create_process(t_elements *elements)
{
	int	i;

	gettimeofday(&elements->time_create, NULL);
	i = 0;
	while (i < elements->num_of_philo)
	{
		elements->philos->number_time_eat = 0;
		elements->philos[i].last_time_eat = elements->time_create;
		elements->philos[i].pid = fork();
		if (elements->philos[i].pid == 0)
		{
			philo(&elements->philos[i]);
		}
		else if (elements->philos[i].pid < 0)
		{
			ft_error("ERROR: creation process failed");
			exit(1);
		}
		++i;
	}
}

int	main(int argc, char *argv[])
{
	t_elements	elements;
	pthread_t	thread;

	elements.num_time_must_eat = 0;
	if (argc != 5 && argc != 6)
		return (ft_error("ERROR: wrong argc\n"));
	if (initial(&elements, argc, argv) == 0)
		return (1);
	create_process(&elements);
	if (elements.num_time_must_eat != 0)
		pthread_create(&thread, NULL, each_must_eat, &elements);
	pthread_create(&thread, NULL, finish, &elements);
	free_join_philos(&elements);
	return (0);
}
