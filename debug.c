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
	printf("---------------------------------\n");
	printf("node %i\n", (*node)->index);
	printf("node->value = %i\n", (*node)->value);
	printf("node->cost = %i\n", (*node)->cost);
	printf("node->daron = %p\n", (*node)->daron);
	printf("node->daron->value = %i\n", (*node)->daron->value);
	printf("node->daron->index = %i\n", (*node)->daron->index);
	printf("-------------------\n");
}

void	print_stack(t_stack *stack)
{
	t_stack	*ptr;

	ptr = stack;
	while (ptr)
	{
		printf("%d -> ", ptr->value);
		ptr = ptr->next;
		if (!ptr)
			printf("null\n");
	}
}

void	print_tab(const int *tab, size_t size)
{
	size_t	i;

	i = 0;
	printf("[");
	while (i < size)
	{
		printf(" %i,", tab[i]);
		i++;
	}
	printf("]\n");
}
