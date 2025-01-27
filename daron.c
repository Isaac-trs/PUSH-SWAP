/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   daron.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istripol <istripol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:18:39 by istripol          #+#    #+#             */
/*   Updated: 2025/01/27 17:49:22by istripol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_daron(t_stack **node_b, t_stack *stack_a)
{
    t_stack *daron1;
    t_stack *daron2;
	int	i = 0;
	int daron_index = -1;
	
    // Loop through stack A and compare to node B
    daron1 = NULL;
    while (stack_a != NULL)
    { 
        if ((*node_b)->value < stack_a->value\
			&& stack_a->value > daron1->value)
			daron1 = stack_a;
		stack_a = stack_a->next;
    }
	if (!daron1)
		(*node_b)->daron_index = -1;
	else
		(*node_b)->daron = daron1;
		(*node_b)->daron_index = (*node_b)->daron->index;
	// SHOULD RETURN -1 IF NO DARON FOUND
	// PA + RA
	return (daron1);
}

int	cost_to_daron(t_stack **node_b, int size_a, int size_b)
{
	int a_cost;
	int	b_cost;
	int	total;

	if ((*node_b)->daron->index > size_a / 2)
		a_cost = size_a - (*node_b)->daron->index;
	else
		a_cost = (*node_b)->daron->index;
	if (((*node_b)->index > size_b / 2))
		b_cost = size_b - (*node_b)->index;
	else
		b_cost = (*node_b)->index;
	total = a_cost + b_cost;
	(*node_b)->cost = total + 1;
	// +1 cause we ALWAYS have to perform a PB;
	return (a_cost + b_cost + 1);
}

int	apply_daron(t_stack **node_b, t_stack **stack_a, int *size_a, int *size_b)
{
	int	i;
	
	if ((*node_b)->daron_index == -1)
	{
		pa(stack_a, node_b);
		ra(stack_a);	
	}
	else if ((*node_b)->daron_index == size_a - 1)
	{
		rra(stack_a);
		pa(stack_a, node_b);
		//ra(stack_a);
		//ra(stack_a);
	}
	else
	{
		i = 0;
		while ((*node_b)->daron->index > i++)
			ra(stack_a);
		pa(stack_a, node_b);
	}
	*size_a++;
	*size_b--;
	set_and_reset(node_b, stack_a);
}

void	set_and_reset(t_stack **stack_a, t_stack **stack_b)
{
	// HAS TO BE CALLED AT EACH PUSH
	t_stack	*tmp;
	int	i;

	i = 0;
	tmp = *stack_a;
	while (tmp)
	{
		tmp->index = i++;
		tmp->cost = 0;
		tmp->daron_index = 0;
		tmp->daron = NULL;
		tmp = tmp->next;
	}
	i = 0;
	tmp = *stack_b;
	while (tmp)
	{
		tmp->index = i++;
		tmp->cost = 0;
		tmp->daron_index = 0;
		tmp->daron = NULL;
		tmp = tmp->next;
	}
}

