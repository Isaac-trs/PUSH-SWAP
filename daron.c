/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   daron.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istripol <istripol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:18:39 by istripol          #+#    #+#             */
/*   Updated: 2025/01/31 23:18:33 by istripol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_daron(t_stack **node_b, t_stack *stack_a)
{
	t_stack	*daron1;

	daron1 = NULL;
	while (stack_a != NULL)
	{
		if ((*node_b)->value < stack_a->value && !daron1)
			daron1 = stack_a;
		else if ((*node_b)->value < stack_a->value \
				&& stack_a->value < daron1->value)
			daron1 = stack_a;
		stack_a = stack_a->next;
	}
	if (!daron1)
		(*node_b)->daron_index = -1;
	else
	{
		(*node_b)->daron = daron1;
		(*node_b)->daron_index = (*node_b)->daron->index;
	}
}

void	cost_to_daron(t_stack **node_b, int size_a, int size_b)
{
	int	a_cost;
	int	b_cost;
	int	total;
	int	pos;

	pos = 1;
	if ((*node_b)->daron->index > size_a / 2)
		a_cost = size_a - (*node_b)->daron->index;
	else
		a_cost = (*node_b)->daron->index;
	if ((*node_b)->index == 0)
		b_cost = 0;
	else if (((*node_b)->index > size_b / 2))
		b_cost = size_b - (*node_b)->index;
	else
		b_cost = (*node_b)->index;
	total = a_cost + b_cost + 1;
	if (total < 0)
		pos *= -1;
	total *= pos;
	(*node_b)->cost = total;
	(*node_b)->cost_a = a_cost;
	(*node_b)->cost_b = b_cost;
}

void	apply_daron(t_stack **node_b, t_stack **stack_b, \
					t_stack **stack_a, t_push_swap *push_swap)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i++ < (*node_b)->cost_a)
	{
		if ((*node_b)->daron->index > push_swap->size_a / 2)
			rra(stack_a);
		else
			ra(stack_a);
	}
	while (j++ < (*node_b)->cost_b)
	{
		if ((*node_b)->index > push_swap->size_b / 2)
			rrb(stack_b);
		else
			rb(stack_b);
	}
	pa(stack_a, stack_b);
	push_swap->size_b--;
	push_swap->size_a++;
}

void	set_and_reset(t_stack **stack)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = *stack;
	while (tmp != NULL)
	{
		tmp->index = i++;
		tmp->cost = 0;
		tmp->daron_index = 0;
		tmp->daron = NULL;
		tmp->cost_a = 0;
		tmp->cost_b = 0;
		tmp = tmp->next;
	}
}
