#include "push_swap.h"
void find_insert_pos(a, tmp->index, find_position)
{
    
}

void get_position(t_stack **stack)
{
    t_stack *tmp;
    int i;

    i = 0;
    tmp = *stack;
    while(tmp)
    {
        tmp->cur_position = i;
        tmp = tmp->next;
        i++;
    }
}

void get_insert_pos(t_stack **a, t_stack **b)
{
    t_stack *tmp;
    int find_position;

    tmp = *b;
    find_position = 0;
    get_position(a);
    get_position(b);
    while(tmp)
    {
        find_position = find_insert_pos(a, tmp->index, find_position);
        tmp->insert_position = find_position;
        tmp = tmp->next;
    }
}

void sort_b (t_stack **a, t_stack **b)
{
    while(*b)
    {
        get_insert_pos(a, b);
        get_cost(a, b);
        do_cheapest_move(a, b);
    }
    if(!stack_sorted(*a))
        shift(a);
}

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
