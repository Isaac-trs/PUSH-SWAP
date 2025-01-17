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

int	init_int_tab(char **char_tab, int ac, int **int_tab)
{
	int i;
	int size;

	i = 0;	
	size = 0;
	while (char_tab[size])
		size++;
	*int_tab = malloc(sizeof(int) * size);
	while (char_tab[i])
	{
		(*int_tab)[i] = ft_atoi(char_tab[i]);
		i++;
	}
	if (ac == 2)
	{
		i = 0;
		while (char_tab[i])
			free(char_tab[i++]);
		free(char_tab);
	}
	return (size);
}

void	sort_int_tab(int *tab, int size)
{
	int i;

	i= 0;
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

int	get_mediane(int *tab, int size)
{
	if (size % 2 == 0)
}

t_stack	*ft_init_stack(int *tab, int size)
{
	t_stack *ret;
	t_stack *buf;
	int i;

	i = 0;
	while (i < size)
	{
		buf = lstnew(tab[i]);
		lstadd_back(&ret, buf);
		i++;
	}
	return (ret);
}

void	print_stack(const t_stack *stack)
{
	while (stack)
	{
		printf("%d\n", stack->value);
		stack = stack->next;
	}
}


void print_tab(int *tab, size_t size)
{
	int i = 0;

	printf("[ ");
	while ( i < size)
	{
		printf("%i, ", tab[i]);
		i++;
	}
	printf(" ]");
}

int	main(int ac, char **av)
{
	t_stack *stack_a;
	t_stack *stack_b;
	int *int_tab;
	char **char_tab;
	int size;

	//stack_a = ft_init_stack((int []){1, 3, 2},3);
	//print_stack(stack_a);
	//sort_3(& stack_a);
	//print_stack(stack_a);
	int_tab  = malloc(sizeof(int) * 64);
	int i = 0;

	while (i < 64)
	{
		int_tab[i] = 99 - i;
		i++;
	}
	print_tab(int_tab, 64);
	sort_int_tab(int_tab, 64);
	print_tab(int_tab, 64);

	return 0;






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
			size = init_int_tab(char_tab, ac, & int_tab);
			if (ft_is_uniq(int_tab, size) && !ft_is_sorted(int_tab, size))
				stack_a = ft_init_stack(int_tab, size);			
			else
				return (0);
		}

	}
}