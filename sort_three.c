#include "push_swap.h"

void sort_three(t_stack **a)
{
    t_stack *max_value;

    max_value = find_max(*a);
    if(max_value == *a)
        ra(a);
    else if((*a)->next == max_value)
        rra(a);
    if((*a)->num > (*a)->next->num)
        sa(a);
}
