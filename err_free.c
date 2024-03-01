#include "push_swap.h"

void free_argv(char **processed_argv)
{
    int i;

    i = 0;
    while(processed_argv[i])
    {
        free(processed_argv[i]);
        i++;
    }
    free(processed_argv);
}

void free_stack(t_stack **stack)
{
    t_stack *cur;
    t_stack *next;

    cur = *stack;
    while(cur != NULL)
    {
        next = cur->next;
        free(cur);
        cur = next;
    }
    *stack = NULL;
}

void free_err(t_stack **a, t_stack **b)
{
     if (a != NULL)
        free_stack(a);
    if (b != NULL && *b != NULL)
        free_stack(b);
    ft_putstr_fd("Error\n", STDERR_FILENO);
    exit(1);
}