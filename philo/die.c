/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 11:14:37 by souchen           #+#    #+#             */
/*   Updated: 2022/05/30 13:48:23 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/philo.h"

void	*each_must_eat(void *argv)
{
	t_elements	*elements;

	elements = argv;
	while (!elements->finish_code)
	{
		pthread_mutex_lock(&elements->mutex2);
		if (elements->number_final_of_eat_philo == elements->num_of_philo)
			elements->finish_code = 1;
		pthread_mutex_unlock(&elements->mutex2);
	}
	return (NULL);
}

void	*die(void *argv)
{
	t_philo			*philo;
	struct timeval	now;
	long long		ms;

	philo = argv;
	while (!philo->elements->finish_code)
	{
		pthread_mutex_lock(&philo->elements->mutex2);
		gettimeofday(&now, NULL);
		ms = time_to_ms(now) - time_to_ms(philo->last_time_eat);
		pthread_mutex_lock(&philo->mutex1);
		if (ms >= philo->elements->time_to_die && !philo->elements->finish_code)
		{
			printf("%lld\t%d\t %s\n", \
				time_to_ms(now) - time_to_ms(philo->elements->time_create), \
				philo->num + 1, "died");
			philo->elements->finish_code = 1;
		}
		pthread_mutex_unlock(&philo->elements->mutex2);
		pthread_mutex_unlock(&philo->mutex1);
	}
	return (NULL);
}
