#include "push_swap.h"

int stack_len(t_stack *stack)
{
    int size;

    size = 0;
    if(!stack)
        return(0);
    while(stack)
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

int create_node(t_stack **stack, int n)
{
	t_stack *node;
	t_stack *last_node;
	if(!stack)
		return (0);
	node = malloc(sizeof(t_stack));
	if(!node)
		return (0);
	node->next = NULL;
	node->num = n;
	if(!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
	return(1);
}

void fill_stack_a(t_stack **a, t_stack **b, char **argv)
{
    long int	n;
    int	i;
	int node_created;

	i = 0;
	while(argv[i])
	{
		n = ft_atoi(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_err(a, b);
		node_created = create_node(a, (int)n);
		if (!node_created)
			free_err(a, b);
		i++;
	}
}
