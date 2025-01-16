/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istripol <istripol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 12:19:18 by istripol          #+#    #+#             */
/*   Updated: 2025/01/16 04:22:51 by istripol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*init_int_tab(char **char_tab, int size, int *int_tab)
{
	int i;
	int sz;

	i = 0;	
	sz = 0;
	while (char_tab[i])
		sz++;
	int_tab = malloc(sizeof(int) * sz);
	while (char_tab[i])
	{
		int_tab[i] = ft_atoi(char_tab[i]);
		i++;
	}
	if (size == 2)
	{
		while (char_tab[i])
			free(char_tab[i++]);
		free(char_tab);
	}
	return (sz);
}

t_stack	**ft_init_stack(int *tab, int size)
{
	t_stack *ret;
	t_stack *buf;
	int i;

	i = 0;
	while (i < size - 1)
	{
		buf = lstnew(tab[i]);
		lstadd_back(&ret, buf);
		i++;
	}
	return (ret);
}

int	main(int ac, char **av)
{
	t_stack **stack_a;
	t_stack **stack_b;
	int *int_tab;
	char **char_tab;
	int size;

	if (ac <= 1)
		return (0);
	else
	{
		char_tab = &(av[1]);
		if (ac == 2)
			char_tab = ft_split(av[1], ' ');
		if (!ft_check_args(char_tab))
			return (0);
		else
		{
			size = init_int_tab(char_tab, ac, int_tab);
			if (ft_is_uniq(int_tab, size) && !ft_is_sorted(int_tab, size))
				stack_a = ft_init_stack(int_tab, size);			
			else
				return (0);
		}

	}
}