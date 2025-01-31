/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istripol <istripol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 04:37:44 by istripol          #+#    #+#             */
/*   Updated: 2025/01/31 23:23:41 by istripol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_stack **node_a)
{
	if (*node_a == NULL || (*node_a)->next == NULL)
		return ;
	if ((*node_a)->value > (*node_a)->next->value)
		sa(node_a);
}

void	sort_3(t_stack **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->value;
	b = (*stack_a)->next->value;
	c = (*stack_a)->next->next->value;
	if (a > b && b > c && a > c)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (a > b && b < c && a > c)
		ra(stack_a);
	else if (a > b && b < c && a < c)
		sa(stack_a);
	else if (a < b && b > c && a < c)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (a < b && b > c && a > c)
		rra(stack_a);
}

void	push_and_sort(t_push_swap **push_swap, \
					t_stack **stack_a, t_stack **stack_b)
{
	int	mediane;

	mediane = get_mediane(*stack_a);
	while ((*push_swap)->size_a > 3)
	{
		if ((*stack_a)->value < mediane)
		{
			pb(stack_a, stack_b);
			mediane = get_mediane(*stack_a);
			(*push_swap)->size_a--;
			(*push_swap)->size_b++;
		}
		else
			ra(stack_a);
	}
	sort_3(stack_a);
}
