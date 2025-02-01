/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istripol <istripol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 00:22:52 by istripol          #+#    #+#             */
/*   Updated: 2025/02/01 00:22:55 by istripol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_node(t_stack **node)
{
	ft_printf("---------------------------------\n");
	ft_printf("node %i\n", (*node)->index);
	ft_printf("node->value = %i\n", (*node)->value);
	ft_printf("node->cost = %i\n", (*node)->cost);
	ft_printf("node->daron = %p\n", (*node)->daron);
	ft_printf("node->daron->value = %i\n", (*node)->daron->value);
	ft_printf("node->daron->index = %i\n", (*node)->daron->index);
	ft_printf("-------------------\n");
}

void	print_stack(t_stack *stack)
{
	t_stack	*ptr;

	ptr = stack;
	while (ptr)
	{
		ft_printf("%d -> ", ptr->value);
		ptr = ptr->next;
		if (!ptr)
			ft_printf("null\n");
	}
}

void	print_tab(const int *tab, size_t size)
{
	size_t	i;

	i = 0;
	ft_printf("[");
	while (i < size)
	{
		ft_printf(" %i,", tab[i]);
		i++;
	}
	ft_printf("]\n");
}
