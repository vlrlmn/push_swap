#include "push_swap.h"

void push(t_stack **src, t_stack **dst)
{
    t_stack *tmp;

    if(*src == NULL)
        return ;
    tmp = (*src)->next;
    (*src)->next = *dst;
    *dst = *src;
    *src = tmp;
}

void pa(t_stack **stack_a, t_stack **stack_b)
{
    push(stack_b, stack_a);
    ft_printf("pa\n");
}

void pb(t_stack **stack_a, t_stack **stack_b)
{
    push(stack_a, stack_b);
    ft_printf("pb\n");
}