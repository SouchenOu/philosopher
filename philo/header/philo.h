/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 11:40:29 by souchen           #+#    #+#             */
/*   Updated: 2022/05/30 09:52:39 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int					num;
	int					number_time_eat;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	pthread_t			thread;
	struct s_elements	*elements;
	struct timeval		last_time_eat;
	pthread_mutex_t		mutex1;

}					t_philo;

typedef struct s_elements
{
	t_philo			*philos;
	int				num_of_philo;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_die;
	int				num_time_must_eat;
	int				number_final_of_eat_philo;
	int				finish_code;
	pthread_mutex_t	mutex2;
	pthread_mutex_t	*forks;
	struct timeval	time_create;
}			t_elements;

int			ft_strlen(char *str);
int			ft_atoi(const char *nptr);
int			ft_malloc(void *str, size_t size);
int			ft_error(char *str);
long long	time_to_ms(struct timeval now);
void		msg_philo(t_philo *philo, char *str);
int			arguments(t_elements *elements, int argc, char **argv);
int			initial(t_elements *elements, int argc, char *argv[]);
void		*philo(void *argv);
void		*die(void *argv);
void		*each_must_eat(void *argv);
int			free_join_philos(t_elements *elements);
#endif
