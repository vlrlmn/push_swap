#include "push_swap.h"

t_stack *get_stack_before_bottom(t_stack *stack)
{
    while(stack && stack->next && stack->next->next == NULL)
        stack = stack->next;
    return(stack);
}

t_stack *get_stack_bottom(t_stack *stack)
{
    while(stack && stack->next)
    {
        stack = stack->next;
    }
    return(stack);
}

int stack_len(t_stack *stack)
{
    int size;

    size = 0;
    if(!stack)
        return(0);
    while(stack->next)
    {
        size++;
        stack = stack->next;
    }
    return(size);
}

bool stack_sorted(t_stack *stack)
{
	if(!stack)
		return(1);
	while(stack->next)
	{
		if(stack->num > stack->next->num)
			return(false);
		stack = stack->next;
	}
	return(true);
}
