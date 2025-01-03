/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istripol <istripol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 08:29:49 by istripol          #+#    #+#             */
/*   Updated: 2024/09/27 08:34:38 by istripol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "mov1.c"

typedef struct s_stack
{
	int		value;
	struct s_stack 	*prev;
	struct s_stack 	*next;
	
} t_stack;

int main()
{
    t_stack *a;
    t_stack *b;

    a = malloc(sizeof(t_stack));
    b = malloc(sizeof(t_stack));
    a->value = 9;
    a->prev = NULL;
    a->next = NULL;
    b->value = 19;
    b->prev = NULL;
    b->next = NULL;
    printf("a = %i\n", a->value); 
    printf("b = %i\n", b->value); 
    swap(&a, &b);
    printf("a = %i\n", a->value); 
    printf("b = %i\n", b->value); 
    free(a);
    free(b);
    return -1;
}