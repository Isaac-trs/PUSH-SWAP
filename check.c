/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istripol <istripol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 09:56:42 by rocket            #+#    #+#             */
/*   Updated: 2025/01/27 18:13:43 by istripol         ###   ########.fr       */
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

static int ft_is_number(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	while(*str)
	{
		if (!ft_isdigit(*str))
			//write(2, "ERROR\n", 6);
			return (0);
		str++;
	}
	return (1);
}

int 	check_args(char **tab)
{
	// Args are all numbers
	size_t index;

	index = 0;
	while (tab[index])
	{
		if (!ft_is_number(tab[index]))
			//write(2, "ERROR\n", 6);
			return (0);
		index++;
	}
	return (1);
}