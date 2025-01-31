/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istripol <istripol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 01:56:57 by istripol          #+#    #+#             */
/*   Updated: 2025/01/31 22:53:18 by istripol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **node)
{
	t_stack	*tmp;

	if (*node == NULL || (*node)->next == NULL)
		return ;
	tmp = (*node)->next;
	(*node)->next = tmp->next;
	tmp->next = *node;
	*node = tmp;
}

void	sa(t_stack **node_a)
{
	swap(node_a);
	write(1, "sa\n", 3);
}

void	sb(t_stack **node_b)
{
	swap(node_b);
	write(1, "sb\n", 3);
}

void	ss(t_stack **node_a, t_stack **node_b)
{
	swap(node_a);
	swap(node_b);
	write(1, "ss\n", 3);
}
