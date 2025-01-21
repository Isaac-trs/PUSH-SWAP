/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istripol <istripol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 04:37:44 by istripol          #+#    #+#             */
/*   Updated: 2025/01/21 02:55:59 by istripol         ###   ########.fr       */
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
    if (a < b && a < c)
    {
        rra(node_a);
        sa(node_a);
    }
    else if (a > b && a < c)
        sa(node_a);
    else if (a < b && a > c)
        rra(node_a);
    else if (a > b && a > c && b < c)
       ra(node_a);
    else if (a > b && a > c && b > c)
    {
        ra(node_a);
        sa(node_a);
    }
}

void    sort_4(t_stack **node_a, t_stack **node_b)
{

}
void   sort(t_stack **node_a, t_stack **node_b)

{

}