/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istripol <istripol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 18:30:27 by istripol          #+#    #+#             */
/*   Updated: 2025/01/31 01:33:27 by istripol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./PRINTF/ft_printf.h"
# include <limits.h>

# ifndef MALLOC_ERROR
#  define MALLOC_ERROR 0
# endif

typedef struct s_stack
{
	struct s_stack	*daron;
	struct s_stack	*next;
	int				value;
	int				cost;
	int				cost_a;
	int				cost_b;
	int				index;
	int				daron_index;
}	t_stack;

typedef struct s_push_swap
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*int_tab;
	int		size_a;
	int		size_b;
}	t_push_swap;

// stack.c
t_stack	*lstlast(t_stack *lst);
t_stack	*lstnew(int value);
void	lstadd_back(t_stack **lst, t_stack *new);
void	lstclear(t_stack **lst);
int		lstsize(t_stack *lst);

// stack2.c
t_stack	*ft_init_stack(int *tab, int size);
void	free_stack(t_stack **stack);
void	cost_and_apply(t_push_swap **push_swap, t_stack **sb, t_stack **sa);

// daron.c
void	find_daron(t_stack **node_b, t_stack *stack_a);
void	set_and_reset(t_stack **stack);
void	cost_to_daron(t_stack **node_b, int size_a, int size_b);
void	apply_daron(t_stack **node_b, t_stack **stack_b, \
					t_stack **stack_a, t_push_swap *push_swap);

// tab.c
int		*init_int_tab(char **char_tab, int ac, int *sz);
void	ft_swap(int *a, int *b);
void	sort_int_tab(int *tab, int size);
int		get_mediane(t_stack *lst);

// check.c
int		ft_is_uniq(int *tab, size_t size);
int		ft_is_sorted(int *tab, size_t size);
int		check_args(char **tab);
int		ft_is_number(const char *str);

// sort.c
void	sort_2(t_stack **node_a);
void	push_and_sort(t_push_swap **t_push_swap, \
						t_stack **stack_a, t_stack **stack_b);
void	sort_3(t_stack **stack_a);

// mov1.c
void	sa(t_stack **node);
void	sb(t_stack **node);
void	ss(t_stack **node_a, t_stack **node_b);
// mov2.c
void	ra(t_stack **node_a);	
void	rb(t_stack **node_b);
void	rr(t_stack **node_a, t_stack **node_b);
// mov3.c	
void	rra(t_stack **node_a);
void	rrb(t_stack **node);
void	rrr(t_stack **node_a, t_stack **node_b);
// mov4.c
void	pa(t_stack **node_a, t_stack **node_b);
void	pb(t_stack **node_a, t_stack **node_b);

// debug.c
void	print_tab(const int *tab, size_t size);
void	print_node(t_stack **node);
void	print_stack(t_stack *stack);
#endif