/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istripol <istripol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 16:44:38 by istripol          #+#    #+#             */
/*   Updated: 2025/01/25 16:45:05by istripol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack *buf;
	t_stack *tmp;

	tmp = *stack;
	while (tmp)
	{
		buf = tmp;
		tmp = tmp->next;
		free(buf);
	}
}

t_stack	*ft_init_stack(int *tab, int size)
{
	t_stack *ret = NULL;
	t_stack *buf;
	int i;

	i = 0;
	while (i < size)
	{
		buf = lstnew(tab[i]);
        if (!buf)
        {
            free_stack(&ret);
            return (MALLOC_ERROR);
        }
		lstadd_back(&ret, buf);
		i++;
	}
	return (ret);
}

void	print_stack(const t_stack *stack)
{
	while (stack)
	{
		printf("%d -> ", stack->value);
		stack = stack->next;
		if (!stack)
			printf("null\n");
	}
}


