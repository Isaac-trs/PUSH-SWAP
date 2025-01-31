/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istripol <istripol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 07:54:58 by istripol          #+#    #+#             */
/*   Updated: 2025/01/29 22:56:42by istripol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "push_swap.h"

// int main(int ac, char **av)
// {
//     t_push_swap	*push_swap = malloc(sizeof(t_push_swap));
//     t_stack		*ptr = NULL;
// 	int			i;
// 	char **args;

// 	if (ac == 1)
// 		return (printf("Not enough ARGS\n"));
// 	if (ac > 2 && check_args(&av[1]))
// 		push_swap->int_tab = init_int_tab(&av[1], ac, &push_swap->size_a);
// 	else if (ac == 2)
// 	{
// 		args = ft_split(av[1], ' ');
// 		if (!check_args(args))
// 			return (printf("at check_args WRONG\n"));
// 		push_swap->int_tab = init_int_tab(args, ac, &push_swap->size_a);
// 	}

// 	print_tab(push_swap->int_tab, push_swap->size_a);
// 	printf("%i\n", push_swap->size_a);
// 	if (push_swap->size_a == 1)
// 		return (printf(" only one element WRONG\n"));
// 	if (ft_is_sorted(push_swap->int_tab, push_swap->size_a))
// 		return (printf("array is sorted"));
// 	if (!ft_is_uniq(push_swap->int_tab, push_swap->size_a))
// 		return (printf("array is no uniq"));
// 	print_tab(push_swap->int_tab, push_swap->size_a);

		
#include "push_swap.h"

void 	free_all(t_push_swap **push_swap);
void		start_push_swap(t_push_swap **ps);

int		first_checks(t_push_swap *push_swap,int ac, char **av)
{
	int	i;
	char **args;

    if (ac > 2)
    {
        if (!check_args(&av[1]))
			return (printf("Not passing check_args"));
		push_swap->int_tab = init_int_tab(&av[1], ac, &push_swap->size_a);
    }
    else if (ac == 2)
    {
        args = ft_split(av[1], ' ');
        if (!check_args(args))
		{
			i = 0;
			while (args[i++]);
			free_split(args, i);
            return (0);
		}
		push_swap->int_tab = init_int_tab(args, ac, &push_swap->size_a);
	}	
	return (1);
}

int		second_checks(t_push_swap *push_swap)
{
	if (push_swap->size_a == 1 || ft_is_sorted(push_swap->int_tab, push_swap->size_a) || !ft_is_uniq(push_swap->int_tab, push_swap->size_a))
		{
			free(push_swap->int_tab);
			return (0);
		}
	return (1);
}

int main(int ac, char **av)
{
	t_push_swap	ps = {0};
	
   // t_push_swap *push_swap = malloc(sizeof(t_push_swap));
    t_push_swap *push_swap = &ps;
//	push_swap->size_a, push_swap->size_b = 0;
    int i;
    char **args;

    if (ac < 2)
		return(printf("No ARGS !\n"));
	//printf("\nDoes av[1] passes checks ? %i\n", check_args(ft_split(av[1], ' ')));
	//printf("\nDoes av[1] pass args test ? %i\n", check_args(&av[1]));
	if (!first_checks(push_swap, ac, av) || !second_checks(push_swap))
	{
		printf("Error\n");
		exit(0);
	}
    push_swap->stack_a = ft_init_stack(push_swap->int_tab, push_swap->size_a);
	//set_and_reset(&push_swap->stack_a);
	// if (push_swap->stack_b == NULL)
	// {
	// 	printf("wAYO WTF??\n");
	// 	exit(0);
	// }
	
	if (push_swap->size_a == 2)
		sort_2(&push_swap->stack_a);
	else if(push_swap->size_a == 3)
		sort_3(&push_swap->stack_a);
	else
		start_push_swap(&push_swap);

	// THOSE FREE ARE FOR TEST ONLY 
	free(push_swap->int_tab);
	//write(1, "OK MEK\n", 6);
}

void	start_push_swap(t_push_swap **ps)
{
	t_stack *ptr;
	t_push_swap *push_swap = *ps;
	int		i;

    push_and_sort(&push_swap, &push_swap->stack_a, &push_swap->stack_b);
	//printf("ICI\n");
	//print_stack(push_swap->stack_a);
	//print_stack(push_swap->stack_b);

	// ACTUAL PS
    while (push_swap->size_b > 0)
        cost_and_apply(&push_swap, &push_swap->stack_b, &push_swap->stack_a);
	i = 0;
	ptr = push_swap->stack_a;
    while (ptr->next && ptr->value < ptr->next->value)
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
//    print_stack(push_swap->stack_a);
//    printf("Size A stack: %i\n", push_swap->size_a);
//    write(1, "\n", 1);
//    printf("Size B stack: %i\n", push_swap->size_b);
//    print_stack(push_swap->stack_b);

	//printf("LABA\n");
	//print_stack(push_swap->stack_a);
	//print_stack(push_swap->stack_b);

//	free(push_swap->int_tab);
	free_stack(&push_swap->stack_a);
	//free_stack(&push_swap->stack_b);
//	free(push_swap);
}

void 	free_all(t_push_swap **push_swap)
{
	t_stack *stack	= (*push_swap)->stack_a;
	int		*tab	=  (*push_swap)->int_tab;

	free((*push_swap)->int_tab);
	free((*push_swap)->stack_a);
	if ((*push_swap)->stack_b != NULL)
		free((*push_swap)->stack_b);
	free(push_swap);
}