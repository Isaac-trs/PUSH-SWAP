/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocket <rocket@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 04:00:48 by rocket            #+#    #+#             */
/*   Updated: 2024/07/10 04:24:23by rocket           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef struct s_stack
{
	int		value;
	struct s_stack 	*prev;
	struct s_stack 	*next;
	
} t_stack;

int		ft_is_uniq(int *tab, size_t size);
int		ft_is_sorted(int *tab, size_t size);
int		ft_check_args(char **tab);
t_list	ft_init_stack(int *tab);
void	sa(t_stack node);
void	sb(t_stack node);
void	ss(t_stack a, t_stack b);
void	pa(t_stack a, t_stack b);
void	pb(t_stack a, t_stack b);
void	ra(t_stack node);	
void	rb(t_stack node);	
void	rr(t_stack node);
void	rra(t_stack node);
void	rrb(t_stack node);
void	rrr(t_stack a, t_stack b);

