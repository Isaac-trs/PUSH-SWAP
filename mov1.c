/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istripol <istripol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 01:56:57 by istripol          #+#    #+#             */
/*   Updated: 2024/10/03 18:41:48y istripol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **node)
{
	t_stack *tmp;
	if (*node == NULL || (*node)->next == NULL)
		return;

	tmp = (*node)->next;
	(*node)->next = tmp->next;
	tmp->next = *node;
	*node = tmp;
}

void	sa(t_stack **node_a)
{
	swap(node_a);
	printf("sa\n");
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