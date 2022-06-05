/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_and_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 19:13:47 by souchen           #+#    #+#             */
/*   Updated: 2022/05/30 10:39:15 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header/philo.h"

void	next(t_elements *elements)
{
	int	i;

	i = 0;
	while (elements->finish_code == 0)
	{
		usleep(100);
	}
	pthread_mutex_destroy(&elements->philos[i++].mutex1);
	pthread_mutex_destroy(&elements->mutex2);
}

int	free_join_philos(t_elements *elements)
{
	int	i;

	i = 0;
	if (elements->num_of_philo == 1)
	{
		next(elements);
	}
	else
	{
		while (i < elements->num_of_philo && elements->finish_code == 0)
		{
			if (pthread_join(elements->philos[i].thread, NULL) != 0)
				return (0);
			pthread_mutex_destroy(&elements->philos[i++].mutex1);
			pthread_mutex_destroy(&elements->mutex2);
		}
	}
	free(elements->philos);
	i = 0;
	while (i < elements->num_of_philo)
		pthread_mutex_destroy(&elements->forks[i++]);
	free(elements->forks);
	return (1);
}
