/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istripol <istripol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 09:56:42 by rocket            #+#    #+#             */
/*   Updated: 2025/01/29 00:18:55 by istripol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_uniq(int *tab, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < size - 2)
	{
		j = i + 1;
		while (j < size - 1)
		{
			if (tab[i] == tab[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_is_sorted(int *tab, size_t size)
{
	int	index;
	
	index = 0;
	while (index < size - 2) 
		{
			if (tab[index] > tab[index+1])
				return (0);
			index++;
		}
	return (1);
}

 int ft_is_number(const char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	while(*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

static long	ft_atol(const char *nptr)
{
	int	sign;
	long	res;

	sign = 0;
	res = 0;
	while ((*nptr >= '\t' && *nptr <= '\r') || *nptr == ' ')
		nptr++;
	while (!sign && (*nptr == '-' || *nptr == '+'))
	{
		if (*nptr == '-')
			sign = -1;
		else
			sign = 1;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		res = res * 10 + (*nptr - '0');
		if ((res > INT_MAX && !sign) || (-res < INT_MIN && sign))
			return ((long)INT_MAX + 1);
		nptr++;
	}
	if (sign < 0)
		res *= sign;
	return (res);
}

int 	check_args(char **tab)
{
	// Args are all numbers && INT_MIN < NBR < MAX_INT
	size_t index;

	index = 0;
	while (tab[index])
	{
		if (!ft_is_number(tab[index]))
			return (0);
		if ((ft_atol(tab[index]) > INT_MAX ))
			return (0);
		index++;
	}
	return (1);
}