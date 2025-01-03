/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istripol <istripol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 07:00:21 by istripol          #+#    #+#             */
/*   Updated: 2025/01/03 07:02:26 by istripol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lstsize(t_stack *lst)
{
	t_stack	*tmp;
	int		cpt;

	tmp = lst;
	cpt = 0;
	while (tmp)
	{
		cpt++;
		tmp = tmp->next;
	}
	return (cpt);
}

void    lstclear(t_stack **lst)
{
    t_stack	*tmp;
    t_stack	*buf;

    tmp = *lst;
    while (tmp)
    {
        buf = tmp;
        tmp = tmp->next;
        free(buf);
    }
    *lst = (NULL);
}

t_stack *lstlast(t_stack *lst)
{
    t_stack *tmp;

    if (!lst)
        return (NULL);
    tmp = lst;
    while (tmp->next)
        tmp = tmp->next;
    return (tmp);
}

