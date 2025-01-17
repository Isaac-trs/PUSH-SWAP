/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istripol <istripol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 01:27:37 by istripol          #+#    #+#             */
/*   Updated: 2025/01/16 19:26:40 by istripol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    reverse_rotate(t_stack **node)
{
    t_stack *first;
    t_stack *last;
    t_stack *tmp;

    if (*node == NULL || (*node)->next == NULL)
            return;
            
    first = *node;
    while (first->next->next)
        first = first->next;
    last = lstlast(*node);
    last->next = (*node);
    (*node) = last;
    first->next = NULL;
}

void    rra(t_stack **node_a)
{
    reverse_rotate(node_a);
    write(1, "rra\n", 4);
}

void    rrb(t_stack **node_b)
{
    reverse_rotate(node_b);
    write(1, "rrb\n", 4);
}

void   rrr(t_stack **node_a, t_stack **node_b)
{
    reverse_rotate(node_a);
    reverse_rotate(node_b);
    write(1, "rrr\n",  4);
}