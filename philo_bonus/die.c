/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 11:14:37 by souchen           #+#    #+#             */
/*   Updated: 2022/05/30 13:52:16 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/philo_bonus.h"

void	*finish(void *arg)
{
	int			i;
	t_elements	*elements;

	elements = arg;
	sem_wait(elements->finish_code);
	i = 0;
	while (i < elements->num_of_philo)
		kill(elements->philos[i++].pid, SIGTERM);
	return (NULL);
}

void	*each_must_eat(void *argv)
{
	t_elements	*elements;
	int			i;

	elements = argv;
	i = 0;
	while (i++ < elements->num_of_philo)
		sem_wait(elements->number_final_of_eat_philo);
	sem_post(elements->finish_code);
	return (NULL);
}

void	*die(void *argv)
{
	t_philo			*philo;
	struct timeval	now;
	long long		ms;

	philo = argv;
	while (philo->elements->test == 0)
	{
		sem_wait(philo->elements->sema2);
		gettimeofday(&now, NULL);
		ms = time_to_ms(now) - time_to_ms(philo->last_time_eat);
		sem_wait(philo->sema1);
		if (ms >= philo->elements->time_to_die)
		{
			printf("%lld\t%d\t %s\n", \
				time_to_ms(now) - time_to_ms(philo->elements->time_create), \
				philo->num + 1, "died");
			philo->elements->test = 1;
			sem_post(philo->elements->finish_code);
			return (NULL);
		}
		sem_post(philo->elements->sema2);
		sem_post(philo->sema1);
	}
	return (NULL);
}
