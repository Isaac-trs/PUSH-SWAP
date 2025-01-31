/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istripol <istripol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 05:37:08 by istripol          #+#    #+#             */
/*   Updated: 2025/01/27 19:26:40 by istripol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **node)
{
	t_stack	*first;
	t_stack	*last;

	if (*node == NULL || (*node)->next == NULL)
		return ;
	first = *node;
	last = lstlast(*node);
	(*node) = first->next;
	first->next = NULL;
	last->next = first;
}

void	ra(t_stack **node_a)
{
	rotate(node_a);
	write(1, "ra\n", 3);
}

void	rb(t_stack **node_b)
{
	rotate(node_b);
	write(1, "rb\n", 3);
}

void	rr(t_stack **node_a, t_stack **node_b)
{
	rotate(node_a);
	rotate(node_b);
	write(1, "rr\n", 3);
}
