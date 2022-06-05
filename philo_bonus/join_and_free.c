/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_and_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 19:13:47 by souchen           #+#    #+#             */
/*   Updated: 2022/05/23 13:53:08 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header/philo_bonus.h"

void	free_join_philos(t_elements *elements)
{
	int	i;
	int	status;

	i = 0;
	while (i < elements->num_of_philo)
	{
		waitpid(elements->philos[i].pid, &status, 0);
		sem_close(elements->philos[i].sema1);
		i++;
	}
	free(elements->philos);
	sem_close(elements->finish_code);
	sem_close(elements->sema2);
	sem_close(elements->forks);
	sem_close(elements->number_final_of_eat_philo);
}
