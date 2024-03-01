#include "push_swap.h"

void save_index(t_stack *a, int value, t_stack *ptr, t_stack **highest)
{
    while(ptr)
    {
        if(ptr->num == INT_MIN && ptr->index == 0)
            ptr->index = 1;
        if (ptr->num > value && ptr->index == 0)
        {
            value = ptr->num;
            *highest = ptr;
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

    if(!a)
        return ;
    while(stack_len > 0)
    {
        ptr = a;
        value = INT_MIN;
        highest  = NULL;
        save_index(a, value, ptr, &highest);
        stack_len--;
        if(highest != NULL)
            highest->index = stack_len;
    }
}

void push_to_three(t_stack **a, t_stack **b, int stack_len)
{
    int pushed;
    int middle;
    int i;

    pushed = 0;
    i = 0;
    middle = stack_len / 2;
    while(stack_len > 6 && i < stack_len && pushed < middle)
    {
        if ((*a)->index <= middle)
        {
            pb(a, b);
            pushed++;
        }
        else
            ra(a);
        i++;
    }
    while(stack_len - pushed > 3)
    {
        pb(a, b);
        pushed++;
    }
}

void sort_stacks(t_stack **a, t_stack **b, int stack_len)
{
    get_index(*a, stack_len);
    push_to_three(a, b, stack_len);
    sort_three(a);
    sort_b(a, b);
    // if(!stack_sorted(*a))
    //     rotate_nodes(a);
}
