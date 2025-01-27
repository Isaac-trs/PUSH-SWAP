/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istripol <istripol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 18:30:27 by istripol          #+#    #+#             */
/*   Updated: 2025/01/27 18:20:06 by istripol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libft/libft.h"
# include <stdio.h>

# ifndef MALLOC_ERROR
# define MALLOC_ERROR NULL
# endif

typedef struct s_stack
{
	int		value;
	int		cost;
	int		index;
	int		daron_index;
	struct s_stack *daron;
	struct s_stack 	*next;
	
} t_stack;

// stack.c
t_stack	*lstlast(t_stack *lst);
t_stack	*lstnew(int value);
void	lstadd_back(t_stack **lst, t_stack *new);
void    lstclear(t_stack **lst);
int		lstsize(t_stack *lst);

// stack2.c
t_stack	*ft_init_stack(int *tab, int size);
void	free_stack(t_stack **stack);
void	print_stack(const t_stack *stack);

// daron.c
t_stack	*find_daron(t_stack **node_b, t_stack *stack_a);
void	set_and_reset(t_stack **stack_a, t_stack **stack_b);
int		cost_to_daron(t_stack **node_b, int size_a, int size_b);
int		apply_daron(t_stack **node_b, t_stack **stack_a, int *size_a, int *size_b);
int		apply_daron(t_stack **node_b, t_stack **stack_a, int *size_a, int *size_b);


// tab.c
int		*init_int_tab(char **char_tab, int ac, int *sz);
void	ft_swap(int *a, int *b);
void	sort_int_tab(int *tab, int size);
int		get_mediane(t_stack *lst);
void	print_tab(const int *tab, size_t size);

// check.c
int		ft_is_uniq(int *tab, size_t size);
int		ft_is_sorted(int *tab, size_t size);
int		check_args(char **tab);

// sort.c
void	sort_2(t_stack **node_a);
void	sort(t_stack **node_a, t_stack **node_b);
void	sort_3(t_stack **node_a);

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

#endif