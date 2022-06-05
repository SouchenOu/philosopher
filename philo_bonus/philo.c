/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 11:14:42 by souchen           #+#    #+#             */
/*   Updated: 2022/05/23 13:32:08 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/philo_bonus.h"

static void	pickup_fork(t_philo *philo)
{
	sem_wait(philo->elements->forks);
	msg_philo(philo, "has taken fork");
	sem_wait(philo->elements->forks);
	msg_philo(philo, "has taken fork");
}

static void	eating(t_philo *philo)
{
	gettimeofday(&philo->last_time_eat, NULL);
	msg_philo(philo, "is eating");
	philo->number_time_eat += 1;
	if (philo->number_time_eat == philo->elements->num_time_must_eat)
	{
		sem_post(philo->elements->number_final_of_eat_philo);
	}
	usleep(philo->elements->time_to_eat * 1000);
	sem_post(philo->elements->forks);
	sem_post(philo->elements->forks);
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

void	philo(t_philo *philo)
{
	pthread_t	thread;

	pthread_create(&thread, NULL, die, philo);
	if (philo->num % 2 == 0)
	{
		usleep(philo->elements->time_to_eat * 1000);
	}
	while (philo->elements->test == 0)
	{
		pickup_fork(philo);
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	exit (0);
}
