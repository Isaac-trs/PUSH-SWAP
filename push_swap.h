/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istripol <istripol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 18:30:27 by istripol          #+#    #+#             */
/*   Updated: 2025/01/21 00:35:56 by istripol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "./libft/libft.h"
#include <stdio.h>
typedef struct s_stack
{
	int		value;
	int		cost;
	//s_stack 	*prev;
	struct s_stack 	*next;
	
} t_stack;

void	lstadd_back(t_stack **lst, t_stack *new);
void    lstclear(t_stack **lst);
int		lstsize(t_stack *lst);
t_stack	*lstlast(t_stack *lst);
t_stack	*lstnew(int value);


int	ft_is_uniq(int *tab, size_t size);
int	ft_is_sorted(int *tab, size_t size);
int	ft_check_args(char **tab);
int	get_mediane(t_stack *lst);

int		*init_int_tab(char **char_tab, int ac, int *sz);
t_stack *ft_init_stack(int *tab, int size);


void	print_tab(const int *tab, size_t size);
void	print_stack(const t_stack *stack);
void	free_stack(t_stack **stack);
void 	sort_3(t_stack **node_a);

void	sa(t_stack **node);
void	sb(t_stack **node);
void	ss(t_stack **node_a, t_stack **node_b);
void	pa(t_stack **node_a, t_stack **node_b);
void	pb(t_stack **node_a, t_stack **node_b);
void	ra(t_stack **node_a);	
void	rb(t_stack **node_b);	
void	rr(t_stack **node_a, t_stack **node_b);
void	rra(t_stack **node_a);
void	rrb(t_stack **node);
void	rrr(t_stack **node_a, t_stack **node_b);

