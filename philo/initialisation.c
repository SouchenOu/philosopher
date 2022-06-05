/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 11:39:26 by souchen           #+#    #+#             */
/*   Updated: 2022/05/30 10:40:35 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/philo.h"

static int	initial_philos(t_elements *elements)
{
	int		i;

	pthread_mutex_init(&elements->mutex2, NULL);
	elements->philos = malloc(sizeof(t_philo) * elements->num_of_philo);
	elements->forks = malloc(sizeof(pthread_mutex_t) * elements->num_of_philo);
	if (elements->philos == NULL || elements->forks == NULL)
		return (ft_error("ERROR: malloc failed\n"));
	i = 0;
	while (i < elements->num_of_philo)
	{
		elements->philos[i].num = i;
		pthread_mutex_init(&elements->forks[i], NULL);
		pthread_mutex_init(&elements->philos[i].mutex1, NULL);
		if (i == 0)
			elements->philos[i].left_fork = \
				&elements->forks[elements->num_of_philo - 1];
		else
			elements->philos[i].left_fork = &elements->forks[i - 1];
		elements->philos[i].right_fork = &elements->forks[i];
		elements->philos[i].elements = elements;
		++i;
	}
	return (1);
}

int	initial(t_elements *elements, int argc, char *argv[])
{
	if (arguments(elements, argc, argv) == 0)
		return (0);
	if (initial_philos(elements) == 0)
		return (0);
	return (1);
}
