/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istripol <istripol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 04:37:44 by istripol          #+#    #+#             */
/*   Updated: 2025/01/27 20:59:35 by istripol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_2(t_stack **node_a)
{
    if (*node_a == NULL || (*node_a)->next == NULL)
        return;

    if ((*node_a)->value > (*node_a)->next->value)
        sa(node_a);
}

void   sort_3(t_stack **node_a)
{
    int a;
    int b;
    int c;

    a = (*node_a)->value;
    b = (*node_a)->next->value;
    c = (*node_a)->next->next->value;
    
   //acb 
    // if (a < b && a < c)
    // {
    //     rra(node_a);
    //     sa(node_a);
    // }
    // else if (a > b && a < c)
    //     sa(node_a);
    // else if (a < b && a > c)
    //     rra(node_a);
    // else if (a > b && a > c && b < c)
    //    ra(node_a);
    // else if (a > b && a > c && b > c)
    // {
    //     ra(node_a);
    //     sa(node_a);
    // }
    if (a > b && b > c && a > c) // Case: 3 2 1
    {
        sa(node_a);
        rra(node_a);
    }
    else if (a > b && b < c && a > c) // Case: 3 1 2
        ra(node_a);
    else if (a > b && b < c && a < c) // Case: 2 1 3
        sa(node_a);
    else if (a < b && b > c && a < c) // Case: 1 3 2
    {
        sa(node_a);
        ra(node_a);
    }
    else if (a < b && b > c && a > c) // Case: 2 3 1
        rra(node_a);
}

void    sort(t_stack **node_a, t_stack **node_b)
{
    int size_a;
    int size_b;
    //t_stack *ptr;
    int mediane;

//    ptr = *node_a;
    mediane = get_mediane(*node_a);
    size_a = lstsize(*node_a);
    size_b = 0;
    while (size_a > 3)
    {
        if ((*node_a)->value < mediane)
        {
            pb(node_a, node_b);
            mediane = get_mediane(*node_a);
            size_a--;
            size_b++;
        }
        else
            ra(node_a);
    }
    sort_3(node_a);
}
