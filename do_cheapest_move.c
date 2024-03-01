#include "push_swap.h"

void	do_rr(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		rr(a, b);
	}
}

void do_rrr(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
    while(*cost_a > 0 && *cost_b > 0)
    {
        (*cost_a)--;
        (*cost_b)--;
        rr(a, b);
    }
}

void do_ra(t_stack **a, int *cost)
{
    while(*cost)
    {
        if(*cost > 0)
        {
            ra(a);
            (*cost)--;
        }
        else if(*cost < 0)
        {
            rra(a);
            (*cost)++;
        }
    }
}

void do_rb(t_stack **b, int *cost)
{
    while(*cost)
    {
        if(*cost > 0)
        {
            rb(b);
            (*cost)--;
        }
        else if (*cost < 0)
        {
            rrb(b);
            (*cost)++;
        }
    }
}

void	do_move(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
    if(cost_a < 0 && cost_b < 0)
        do_rrr(a, b, &cost_a, &cost_b);
    else if(cost_a > 0 && cost_b > 0)
        do_rr(a, b, &cost_a, &cost_b);
    do_ra(a, &cost_a);
    do_rb(b, &cost_b);
    pa(a, b);
}

void    do_cheapest_move(t_stack **a, t_stack **b)
{
    t_stack *cpy_b;
    int cheapest;
    int cost_a;
    int cost_b;

    cpy_b = *b;
    cheapest = INT_MAX;
    while(cpy_b)
    {
        if(abs(cpy_b->cost_insert_a) + abs(cpy_b->cost_top_b) < abs(cheapest))
        {
            cheapest = abs(cpy_b->cost_insert_a) + abs(cpy_b->cost_top_b);
            cost_a = cpy_b->cost_insert_a;
            cost_b = cpy_b->cost_top_b;
        }
        cpy_b = cpy_b->next;
    }
    do_move(a, b, cost_a, cost_b);
}