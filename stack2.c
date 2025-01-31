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
            return (NULL);
        }
		lstadd_back(&ret, buf);
		i++;
	}
	return (ret);
}

void	print_stack(t_stack *stack)
{
	t_stack *ptr = stack;
	while (ptr)
	{
		printf("%d -> ", ptr->value);
		ptr = ptr->next;
		if (!ptr)
			printf("null\n");
	}
}

void	cost_and_apply(t_push_swap **push_swap, t_stack **sb, t_stack **sa)
{
	t_stack *to_apply;
	t_stack *tmp;
	int		cost_daron;

	to_apply = (*sb);
	find_daron(&to_apply, *sa);
	cost_to_daron(&to_apply, (*push_swap)->size_a, (*push_swap)->size_b);
	tmp = (*sb);
	while (tmp)
	{
		find_daron(&tmp, *sa);
		cost_to_daron(&tmp, (*push_swap)->size_a, (*push_swap)->size_b);
		if (tmp->cost < to_apply->cost)
		{
			to_apply = tmp;
			cost_to_daron(&to_apply, (*push_swap)->size_a, (*push_swap)->size_b);
		}
		tmp = tmp->next;
	}
	apply_daron(&to_apply, sb, sa, *push_swap);
	set_and_reset(sa);
	set_and_reset(sb);
}


