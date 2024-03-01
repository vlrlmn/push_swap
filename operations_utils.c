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

int	find_max(t_stack *stack)
{
	int		index;

	index = stack->index;
	while (stack)
	{
		if (stack->index > index)
			index = stack->index;
		stack = stack->next;
	}
	return (index);
}