#include "push_swap.h"

void swap(t_stack *stack)
{
    int tmp;
    if(stack == NULL || stack->next == NULL)
        return ;
    tmp = stack->num;
    stack->num = stack->next->num;
    stack->next->num = tmp;
    tmp = stack->index;
    stack->index = stack->next->index;
    stack->next->index = tmp;
}

void sa(t_stack **stack_a)
{
    swap(*stack_a);
    ft_printf("sa\n");
}

void sb(t_stack **stack_b)
{
    swap(*stack_b);
    ft_printf("sb\n");
}

void ss(t_stack **stack_a, t_stack **stack_b)
{
    swap(*stack_a);
    swap(*stack_b);
    ft_printf("ss\n");
}