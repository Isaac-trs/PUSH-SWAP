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

int *init_int_tab(char **char_tab, int ac, int *sz)
{
	int i;
	int size;
	int *int_tab;

	i = 0;	
	size = 0;
	while (char_tab[size])
		size++;
	int_tab = malloc(sizeof(int) * size);
	while (char_tab[i])
	{
		int_tab[i] = ft_atoi(char_tab[i]);
		i++;
	}
	if (ac == 2)
	{
		i = 0;
		while (char_tab[i])
			free(char_tab[i++]);
		free(char_tab);
	}
	*sz = size;
	return (int_tab);
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

int	get_mediane(t_stack *lst)
{
	t_stack *tmp;
	size_t	size;
	size_t	i;
	int	*tab;
	int mediane;

	i = 0;
	tmp = lst;
	size = lstsize(lst);
	tab = malloc(sizeof(int) * size);
	while (tmp)
	{
		tab[i] = tmp->value;
		i++;
		tmp = tmp->next;
	}
	sort_int_tab(tab, size);
	print_tab(tab, size);
	mediane = tab[size / 2];
	if (size == 4)
		mediane = tab[1];
	free(tab);
	return (mediane);
}

t_stack	*ft_init_stack(int *tab, int size)
{
	t_stack *ret = NULL;
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
		printf("%d -> ", stack->value);
		stack = stack->next;
		if (!stack)
			printf("\n");
	}
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

void	free_stack(t_stack **stack)
{
	t_stack *buf;
	t_stack *tmp;

	tmp = *stack;
	while (tmp)
	{
		buf = tmp;
		tmp = tmp->next;
		free(buf);
	}
}

// int	main(int ac, char **av)
// {
// 	int j = 0;
// 	t_stack *stack_a;
// 	t_stack *stack_b;
// 	int *int_tab;
// 	char **char_tab;
	
// 	int size ;
// 	//char *string[5] = {"10", "20", "-30", "-99", "0"};
// 	//while (string[j])
// 	//	printf("%s, ", string[j++]);
// //	printf("\n");
// //	stack_a = ft_init_stack((int []){1, 3, 2},3);
// 	//print_stack(stack_a);
// 	//sort_3(& stack_a);
// 	//print_stack(stack_a);
// 	int i = 0;

// 	print_tab(int_tab, size);
// 	sort_int_tab(int_tab, size);
// 	print_tab(int_tab, size);
// 	//free(int_tab);
// 	printf("\n");

// 	t_stack	*test;
// 	printf("sizeof int_tab = %i\n", sizeof(int_tab));
// 	test = ft_init_stack(int_tab, size);
// 	print_stack(test);
// 	printf("%i", size);
// 	return 0;


// 	if (ac <= 1)
// 		return (0);
// 	else
// 	{
// 		char_tab = &(av[1]);
// 		if (ac == 2)
// 			char_tab = ft_split(av[1], ' ');
// 		if (!ft_check_args(char_tab))
// 			return (0);
// 		else
// 		{
// 			init_int_tab(char_tab, ac, &size);
// 			if (ft_is_uniq(int_tab, size) && !ft_is_sorted(int_tab, size))
// 				stack_a = ft_init_stack(int_tab, size);			
// 			else
// 				return (0);
// 		}
// 		print_stack(stack_a);

// 	}
// }