/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istripol <istripol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 03:11:54 by istripol          #+#    #+#             */
/*   Updated: 2025/01/31 20:55:55 by istripol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **node_a, t_stack **node_b)
{
	t_stack	*tmp;

	if (*node_b == NULL)
		return ;
	tmp = *node_b;
	*node_b = (*node_b)->next;
	tmp->next = *node_a;
	*node_a = tmp;
	write(1, "pa\n", 3);
}

void	pb(t_stack **node_a, t_stack **node_b)
{
	t_stack	*tmp;

	if (*node_a == NULL)
		return ;
	tmp = *node_a;
	*node_a = (*node_a)->next;
	tmp->next = *node_b;
	*node_b = tmp;
	write(1, "pb\n", 3);
}
