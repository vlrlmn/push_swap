#include "push_swap.h"

static void create_node(t_stack **stack, int n)
{
	t_stack *node;
	t_stack *last_node;
	if(!stack)
		return ;
	node = malloc(sizeof(t_stack));
	if(!node)
		return ;
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
}

void fill_stack_a(t_stack **a, char **argv)
{
    long int	n;
    int	i;

	i = 0;
	while(argv[i])
	{
		n = ft_atoi(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_err(a);
		create_node(a, (int)n);
		i++;
	}
}
