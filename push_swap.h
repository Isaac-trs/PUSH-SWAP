/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istripol <istripol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 18:30:27 by istripol          #+#    #+#             */
/*   Updated: 2025/01/03 07:06:22 by istripol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "./libft/libft.h"
#include <stdio.h>
typedef struct s_stack
{
	int		value;
	//struct s_stack 	*prev;
	struct s_stack 	*next;
	
} t_stack;

void    lstclear(t_stack **lst);
int		lstsize(t_stack *lst);
t_stack *lstlast(t_stack *lst);

int		ft_is_uniq(int *tab, size_t size);
int		ft_is_sorted(int *tab, size_t size);
int		ft_check_args(char **tab);
t_stack *ft_init_stack(int *tab);

void	sa(t_stack **node);
void	sb(t_stack **node);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack a, t_stack b);
void	pb(t_stack a, t_stack b);
void	ra(t_stack **node_a);	
void	rb(t_stack **node_b);	
void	rr(t_stack **node_a, t_stack **node_b);
void	rra(t_stack node);
void	rrb(t_stack node);
void	rrr(t_stack a, t_stack b);

