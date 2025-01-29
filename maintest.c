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

void	cost_and_apply(t_stack **sb, t_stack **sa, int *size_a, int *size_b)
{
	t_stack *to_apply;
	t_stack *tmp;
	int		cost_daron;

	// if (*sb == NULL)
	// {
	// 	return ;
	// }
	// printf("size a %d\n", *size_a);
	// printf("size b %d\n", *size_b);
	to_apply = (*sb);
	find_daron(&to_apply, *sa);

	cost_to_daron(&to_apply, *size_a, *size_b);
	//set_and_reset(sa, sb);
	tmp = (*sb);
	while (tmp)
	{
		find_daron(&tmp, *sa);
		cost_to_daron(&tmp, *size_a, *size_b);
		if (tmp->cost < to_apply->cost)
		{
			to_apply = tmp;
			cost_to_daron(&to_apply, *size_a, *size_b);
			// cost_to_daron(&to_apply, *size_a, *size_b);
		}
		tmp = tmp->next;
	}
	// print_node(&to_apply);
	apply_daron(&to_apply, sb, sa, size_a, size_b);
	set_and_reset(sa);
	set_and_reset(sb);
}

int	main(int ac, char **av)
{
	// Tests init
	int size = 0;
	int *int_tab;
	t_stack *stack_a = NULL;
	t_stack *stack_b = NULL;
	
	if (!check_args(av+1))
	{
		printf("Erro\n");
		return 1;
	}
	if (ac > 2)
		int_tab = init_int_tab(&(av[1]), ac, &size);
	else if (ac == 2)
		int_tab = init_int_tab(ft_split(av[1], ' '), ac, &size);
	else
		return 0;
	// printf(" Size of int_tab = %i\n", size);  
	// print_tab(int_tab, size);
	// printf("\n");

	stack_a = ft_init_stack(int_tab, size);
	// printf("size of stack = %i\n", size);
	// print_stack(stack_a);
	// printf("\n");

	// print_stack(stack_a);
	// print_stack(stack_b);

	sort(&stack_a, &stack_b);


	int	size_a = lstsize(stack_a);
	int	size_b = lstsize(stack_b);
	// printf("size a %d", size_a);
	// printf("size b %d", size_b);

	// printf("----------------------------\n");
	// printf("now sorted\n");
	// printf("stack A: ");
	// print_stack(stack_a);
	// printf("\n");
	// printf("stack B: ");
	// print_stack(stack_b);
	// printf("\n");

	// rrb(&stack_b);
	// pa(&stack_a, &stack_b);
	// print_stack(stack_a);
	// print_stack(stack_b);

	find_daron(&stack_b, stack_a);
	set_and_reset(&stack_a);
	// cost_to_daron(&stack_b, size_a, size_b);
	// print_node(&stack_b);
	while (size_b > 0)
	{
		// printf("stack A: ");
		// print_stack(stack_a);
		// printf("\n");
		// printf("stack B: ");
		// print_stack(stack_b);
		cost_and_apply(&stack_b, &stack_a, &size_a, &size_b);
	}

	int i = 0;
	t_stack *tmp = stack_a;
	while (tmp->value < tmp->next->value)
	{
		i++;
		tmp= tmp->next;
	}
	// printf("i %d\n", i);
	if (i > size_a / 2)
	{
		while (tmp->next && tmp->next->value != stack_a->value)
			rra(&stack_a);
		// while (i-- > (size_a - tmp->index))
		// {
		// 	rra(&stack_a);

		// }
	}
	else
	{
		while (i-- >= 0)
			ra(&stack_a);
	}
	printf("stack A  ");
print_stack(stack_a);
	 print_stack(stack_b);


	// Free stacks
	free_stack(&stack_a);
	free_stack(&stack_b);
	free(int_tab);
}



