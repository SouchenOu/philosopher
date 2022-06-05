/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_name.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 13:06:46 by souchen           #+#    #+#             */
/*   Updated: 2022/05/30 13:55:06 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/philo_bonus.h"

char	*next(int num, int *i, char *name)
{
	char	*result;

	if (num == 0)
		*i = *i + 1;
	else
	{
		while (num != 0)
		{
			num = num / 10;
			*i = *i + 1;
		}
	}
	result = malloc(sizeof(char) * 3);
	if (result == NULL)
		return (NULL);
	num = -1;
	while ((++num) < *i)
		result[num] = name[num];
	return (result);
}

char	*name_philo(char *name, int n)
{
	char	*result;
	int		num;
	int		i;

	i = 0;
	num = n;
	result = next(num, &i, name);
	if (n == 0)
		result[i++] = n % 10 + '0';
	else
	{
		while (n)
		{
			result[i++] = n % 10 + '0';
			n /= 10;
		}
	}
	result[i] = 0;
	return (result);
}
