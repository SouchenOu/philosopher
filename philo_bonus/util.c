/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 11:14:48 by souchen           #+#    #+#             */
/*   Updated: 2022/05/30 14:47:48 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/philo_bonus.h"

static int	ft_negative(const char *str, int *i)
{
	int	negative;

	negative = 1;
	if (str[*i] == '-')
	{
		negative = -1;
		*i = *i + 1;
	}
	else if (str[*i] == '+')
	{
		*i = *i + 1;
	}
	return (negative);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	negative;
	int	resultat;

	i = 0;
	resultat = 0;
	while (str[i] == ' '
		|| str[i] == '\t'
		|| str[i] == '\v'
		|| str[i] == '\r'
		|| str[i] == '\n'
		|| str[i] == '\f')
	{
		i++;
	}
	negative = ft_negative(str, &i);
	while (str[i] >= '0' && str[i] <= '9')
	{
		resultat = resultat * 10 + str[i] - '0';
		i++;
	}
	return (negative * resultat);
}

long long	time_to_ms(struct timeval now)
{
	long long		ms;

	ms = now.tv_sec * 1000;
	ms += now.tv_usec / 1000;
	return (ms);
}

void	msg_philo(t_philo *philo, char *str)
{
	long long		ms;
	struct timeval	now;

	sem_wait(philo->elements->sema2);
	gettimeofday(&now, NULL);
	ms = time_to_ms(now) - time_to_ms(philo->elements->time_create);
	printf("%lld\t%d\t %s\n", ms, philo->num + 1, str);
	sem_post(philo->elements->sema2);
}

int	ft_error(char *string)
{
	char	*str;
	int		i;

	str = string;
	i = 0;
	while (*str++)
		i++;
	write(2, string, i);
	return (0);
}
