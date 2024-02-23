#include "push_swap.h"

void rotate (t_stack **stack)
{
    t_stack *tmp;
    t_stack *tail;
    
    tmp = *stack;
    *stack = (*stack)->next;
    tail = get_stack_bottom(*stack);
    tmp->next = NULL;
    tail->next = tmp;
}

void ra(t_stack **stack_a)
{
    rotate(stack_a);
    ft_printf("ra\n");
}

void rb(t_stack **stack_b)
{
    rotate(stack_b);
    ft_printf("rb\n");
}

void rr(t_stack **stack_a, t_stack **stack_b)
{
    rotate(stack_a);
    rotate(stack_b);
    ft_printf("rr\n");
}