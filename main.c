/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istripol <istripol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 07:54:58 by istripol          #+#    #+#             */
/*   Updated: 2025/01/29 21:51:21 by istripol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
    t_push_swap	*push_swap = malloc(sizeof(t_push_swap));
    t_stack		*ptr = NULL;
	int			i;
	char **args;  
//	tests	
	if (ac > 2 && check_args(&av[1]))
	{
		push_swap->int_tab = init_int_tab(&(av[1]), ac, &push_swap->size_a);
		push_swap->size_tab = ac - 1;
	}
	else if (ac == 2)
	{
		if (check_args(args))
			push_swap->int_tab = init_int_tab(ft_split(av[1], ' '), ac, &push_swap->size_a);
		else
			write (1, "Error !", 7);
	}		
	if (!ft_is_uniq(push_swap->int_tab, push_swap->size_a) || ft_is_sorted(push_swap->int_tab, push_swap->size_a))
	{
		write(1, "Error !", 7);
		free(push_swap->int_tab);
	}
	
//	else
//		return 0;






    push_swap->stack_a = ft_init_stack(push_swap->int_tab, push_swap->size_a);
    push_and_sort(&push_swap, &push_swap->stack_a, &push_swap->stack_b);
    
    //push_swap->size_a = lstsize(push_swap->stack_a);
    //push_swap->size_b = lstsize(push_swap->stack_b);
    
	// algo
    while (push_swap->size_b > 0)
        cost_and_apply(&push_swap->stack_b, &push_swap->stack_a, &push_swap->size_a, &push_swap->size_b);
	i = 0;
	ptr = push_swap->stack_a;
    while (ptr->value < ptr->next->value)
	{
		i++;
		ptr = ptr->next;
	}
	if (i > push_swap->size_a / 2)
	{
		while (ptr->next && ptr->next->value != push_swap->stack_a->value)
			rra(&push_swap->stack_a);
	}
	else
	{
		while (i-- >= 0)
			ra(&push_swap->stack_a);
	}
	
    // ONLY TESTS
    print_stack(push_swap->stack_a);
    printf("Size A stack: %i\n", push_swap->size_a);
    write(1, "\n", 1);
    printf("Size B stack: %i\n", push_swap->size_b);
    print_stack(push_swap->stack_b);

	//free
	free(push_swap->int_tab);
	free_stack(&push_swap->stack_a);
	free_stack(&push_swap->stack_b);
	free(push_swap);
}

