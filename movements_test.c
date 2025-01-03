#include "push_swap.h"

int main()
{
    t_stack *a = malloc(sizeof(t_stack));
    t_stack *b = malloc(sizeof(t_stack));
    t_stack *c = malloc(sizeof(t_stack));
    t_stack *d = malloc(sizeof(t_stack));
    t_stack *w = malloc(sizeof(t_stack));
    t_stack *x = malloc(sizeof(t_stack));
    t_stack *y = malloc(sizeof(t_stack));
    t_stack *z = malloc(sizeof(t_stack));

    a->value = 9;
    a->next = b;
    b->value = 19;
    b->next = c;
    c->value = 23;
    c->next = d;
    d->value = 999;
    d->next = NULL;

    w->value = 4;
    w->next = x;
    x->value = 3;
    x->next = y;
    y->value = 2;
    y->next = z;
    z->value = 1;
    z->next = NULL;
    
    printf("a = %i\n", a->value); 
    printf("b = %i\n", a->next->value); 
    printf("c = %i\n", a->next->next->value); 
    printf("d = %i\n", a->next->next->next->value); 
    printf("Size of stack_a = %i\nLast of stack = %i\n--------------------\n", lstsize(a), lstlast(a)->value);

    printf("w = %i\n", w->value); 
    printf("x = %i\n", w->next->value); 
    printf("y = %i\n", w->next->next->value); 
    printf("z = %i\n", w->next->next->next->value);
    printf("Size of stack_b = %i\nLast of stack_b = %i\n--------------------\n", lstsize(w), lstlast(w)->value);

    t_stack **pt = &a;
    t_stack **pt2 = &a;
    t_stack **pt3 = &w;
    t_stack **pt4 = &w;

    while((*pt))
    {
        printf("%i -> ", (*pt)->value);
        pt = &(*pt)->next;
    }
    printf("\n"); 
    sa(&a);
    while((*pt2))
    {
        printf("%i -> ", (*pt2)->value);
        pt2 = &(*pt2)->next;
    }
    printf("\n"); 

    while((*pt3))
    {
        printf("%i -> ", (*pt3)->value);
        pt3 = &(*pt3)->next;
    } 
    printf("\n"); 
    ra(&w);
    while((*pt4))
    {
        printf("%i -> ", (*pt4)->value);
        pt4 = &(*pt4)->next;
    }
    printf("\n"); 
    

    
    while((*pt4))
    {
        printf("%i -> ", (*pt4)->value);
        pt4 = &(*pt4)->next;
    }
    printf("\n"); 

    printf("\n--------\nClearing\n");
    lstclear(&a);
    lstclear(&w);
    //lstclear(&c);
    printf("Size of stack_a = %i\n", lstsize(a));
    printf("Size of stack_b = %i\n", lstsize(w));

    return 0;
}