/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 11:39:26 by souchen           #+#    #+#             */
/*   Updated: 2022/05/30 14:44:35 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/philo_bonus.h"

static sem_t	*ft_sem_init(const char *name, unsigned int value)
{
	sem_t	*sem;

	sem = sem_open(name, O_CREAT | O_EXCL, 777, value);
	if (sem != SEM_FAILED)
		return (sem);
	sem_unlink(name);
	return (sem_open(name, O_CREAT | O_EXCL, 777, value));
}

static int	initial_philos(t_elements *elements)
{	
	int	i;

	elements->finish_code = ft_sem_init("finish", 0);
	elements->test = 0;
	elements->sema2 = ft_sem_init("sema2", 1);
	elements->forks = ft_sem_init("forks", elements->num_of_philo + 1);
	elements->number_final_of_eat_philo = \
		ft_sem_init("number_final_of_eat_philo", 0);
	elements->philos = malloc(sizeof(t_philo) * elements->num_of_philo);
	if (elements->philos == NULL)
		return (ft_error("ERROR: malloc failed\n"));
	i = 0;
	while (i < elements->num_of_philo)
	{
		elements->philos[i].name = name_philo("philosopher", i);
		elements->philos[i].sema1 = ft_sem_init(elements->philos[i].name, 1);
		elements->philos[i].num = i;
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
