#include "push_swap.h"

void save_index(t_stack *a, int value, t_stack *ptr, t_stack *highest)
{
    while(ptr)
    {
        if(ptr->num == INT_MIN && ptr->index == 0)
            ptr->index = 1;
        if (ptr->num > value && ptr->index == 0)
        {
            value = ptr->num;
            highest = ptr;
            ptr = a;
        }
        else
            ptr = ptr->next;
    }
}

void  get_index(t_stack *a, int stack_len)
{
    t_stack *highest;
    t_stack *ptr;
    int value;

    while(stack_len > 0)
    {
        ptr = a;
        value = INT_MIN;
        highest  = NULL;
        save_index(a, value, ptr, highest);
        stack_len--;
        if(!highest)
            highest->index = stack_len;
    }
}

void sort_stacks(t_stack **a, t_stack **b, int stack_len)
{
    get_index(a, stack_len);
    push_to_three(a, b);
    sort_three(a);
    sort_b(a, b);
    if(!stack_sorted(*a))
        rotate_nodes(a);
}
