/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istripol <istripol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 01:27:37 by istripol          #+#    #+#             */
/*   Updated: 2025/01/16 03:30:13 by istripol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    reverse_rotate(t_stack **node)
{
    t_stack *first;
    t_stack *last;
    if (*node == NULL || (*node)->next == NULL)
            return;

    first = *node;
    last = lstlast(*node);
    *node  = last;
    (*node)->next = first;
    last->next = NULL;
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