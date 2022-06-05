/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                            :+:      :+:    */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 11:40:29 by souchen           #+#    #+#             */
/*   Updated: 2022/05/30 13:41:30 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <sys/time.h>

typedef struct s_philo
{
	int					num;
	int					number_time_eat;
	sem_t				*sema1;
	char				*name;
	pid_t				pid;
	struct s_elements	*elements;
	struct timeval		last_time_eat;

}	t_philo;

typedef struct s_elements
{
	t_philo			*philos;
	int				test;
	int				num_of_philo;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_die;
	int				num_time_must_eat;
	sem_t			*number_final_of_eat_philo;
	sem_t			*finish_code;
	sem_t			*sema2;
	sem_t			*forks;
	struct timeval	time_create;
}			t_elements;

int			ft_atoi(const char *nptr);
int			ft_malloc(void *str, size_t size);
int			ft_error(char *str);
long long	time_to_ms(struct timeval now);
void		msg_philo(t_philo *philo, char *str);
int			arguments(t_elements *elements, int argc, char **argv);
int			initial(t_elements *elements, int argc, char *argv[]);
void		philo(t_philo *philo);
char		*name_philo(char *name, int n);
void		*die(void *argv);
void		*each_must_eat(void *argv);
void		free_join_philos(t_elements *elements);
void		*finish(void *arg);
#endif
