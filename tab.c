/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istripol <istripol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 12:19:18 by istripol          #+#    #+#             */
/*   Updated: 2025/01/16 04:22:51istripol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_swap(int *a, int *b)
{
	int tmp;

	tmp = *b;
	*b = *a;
	*a = tmp;
}

int	*init_int_tab(char **char_tab, int ac, int *sz)
{
	int	i;
	int	size;
	int	*int_tab;

	i = 0;	
	size = 0;
	while (char_tab[size])
		size++;
	if ((int_tab = malloc(sizeof(int) * size)) == NULL)
		return (MALLOC_ERROR);
	while (char_tab[i])
	{
		int_tab[i] = ft_atoi(char_tab[i]);
		i++;
	}
	if (ac == 2)
	{
		//free_split(char_tab, i);
		while (i >= 0)
			free(char_tab[i--]);
		free(char_tab);
	}
	*sz = size;
	return (int_tab);
}

void	sort_int_tab(int *tab, int size)
{
	int i;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			ft_swap(&tab[i], &tab[i + 1]);
			i = 0;
		}
		i++;
		if (tab[0] > tab[1])
			i = 0;
	}
}

int	get_mediane(t_stack *lst)
{
	t_stack	*tmp;
	size_t	size;
	size_t	i;
	int		test;
	int		*tab;
	int		mediane;

	i = 0;
	tmp = lst;
	size = lstsize(lst);
	tab = malloc(sizeof(int) * size);
	while (tmp)
	{
		tab[i++] = tmp->value;
		tmp = tmp->next;
	}
	sort_int_tab(tab, size);
	mediane = tab[(size / 4) *2];
	if (size == 4)
		mediane = tab[1];
	free(tab);
	return (mediane);
}

void	print_tab(const int *tab, size_t size)
{
	int i = 0;

	printf("[");
	while ( i < size)
	{
		printf(" %i,", tab[i]);
		i++;
	}
	printf("]\n");
}