/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istripol <istripol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 07:54:58 by istripol          #+#    #+#             */
/*   Updated: 2025/02/02 19:04:25 by istripol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(t_push_swap **push_swap);
void	start_push_swap(t_push_swap **ps);

int	first_checks(t_push_swap *push_swap, int ac, char **av)
{
	int		i;
	char	**args;

	if (ac > 2)
	{
		if (!check_args(&av[1]))
			return (0);
		push_swap->int_tab = init_int_tab(&av[1], ac, &push_swap->size_a);
	}
	else if (ac == 2)
	{
		args = ft_split(av[1], ' ');
		if (!check_args(args))
		{
			i = 0;
			while (args[i++])
				;
			free_split(args, i);
			return (0);
		}
		push_swap->int_tab = init_int_tab(args, ac, &push_swap->size_a);
	}
	return (1);
}

int	second_checks(t_push_swap *push_swap)
{
	if (push_swap->size_a == 1 \
		|| ft_is_sorted(push_swap->int_tab, push_swap->size_a) \
		|| !ft_is_uniq(push_swap->int_tab, push_swap->size_a))
	{
		free(push_swap->int_tab);
		return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_push_swap	ps;
	t_push_swap	*push_swap;

	push_swap = &ps;
	ft_memset(push_swap, 0, sizeof(t_push_swap));
	if (ac < 2)
		exit(0);
	if (!first_checks(push_swap, ac, av) || !second_checks(push_swap))
	{
		write(2, "Error\n", 6);
		exit(0);
	}
	push_swap->stack_a = ft_init_stack(push_swap->int_tab, \
										push_swap->size_a);
	if (push_swap->size_a == 2)
		(sort_2(&push_swap->stack_a), free_stack(&push_swap->stack_a));
	else if (push_swap->size_a == 3)
		(sort_3(&push_swap->stack_a), free_stack(&push_swap->stack_a));
	else
		start_push_swap(&push_swap);
	free(push_swap->int_tab);
}

void	start_push_swap(t_push_swap **ps)
{
	t_stack		*ptr;
	t_push_swap	*push_swap;
	int			i;

	push_swap = *ps;
	push_and_sort(&push_swap, &push_swap->stack_a, &push_swap->stack_b);
	while (push_swap->size_b > 0)
		cost_and_apply(&push_swap, &push_swap->stack_b, &push_swap->stack_a);
	i = 0;
	ptr = push_swap->stack_a;
	while (ptr->next && ptr->value < ptr->next->value)
	{
		i++;
		ptr = ptr->next;
	}
	if (i > push_swap->size_a / 2)
		while (ptr->next && ptr->next->value != push_swap->stack_a->value)
			rra(&push_swap->stack_a);
	else
		while (i-- >= 0)
			ra(&push_swap->stack_a);
	free_stack(&push_swap->stack_a);
}

void	free_all(t_push_swap **push_swap)
{
	free((*push_swap)->int_tab);
	if ((*push_swap)->stack_a != NULL)
		free_stack(&(*push_swap)->stack_a);
	if ((*push_swap)->stack_b != NULL)
		free_stack(&(*push_swap)->stack_b);
	free(push_swap);
}
