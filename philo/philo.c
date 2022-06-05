/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 11:14:42 by souchen           #+#    #+#             */
/*   Updated: 2022/05/30 10:40:12 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/philo.h"

static void	pickup_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	msg_philo(philo, "has taken fork");
	pthread_mutex_lock(philo->left_fork);
	msg_philo(philo, "has taken fork");
}

static void	eating(t_philo *philo)
{
	long long	ms;

	gettimeofday(&philo->last_time_eat, NULL);
	ms = time_to_ms(philo->last_time_eat) - \
		time_to_ms(philo->elements->time_create);
	if (!philo->elements->finish_code)
		printf("%lld\t%d\t %s\n", ms, philo->num + 1, "is eating");
	philo->number_time_eat += 1;
	if (philo->number_time_eat == philo->elements->num_time_must_eat)
		philo->elements->number_final_of_eat_philo += 1;
	usleep(philo->elements->time_to_eat * 1000);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

static void	sleeping(t_philo *philo)
{
	msg_philo(philo, "is sleeping");
	usleep(philo->elements->time_to_sleep * 1000);
}

static void	thinking(t_philo *philo)
{
	msg_philo(philo, "is thinking");
}

void	*philo(void *argv)
{
	t_philo	*philo;

	philo = argv;
	if (philo->num % 2 == 0)
	{
		usleep(philo->elements->time_to_eat * 1000);
	}
	while (!philo->elements->finish_code)
	{
		pickup_fork(philo);
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}
