#include "push_swap.h"

void do_ra(t_stack **a, int iterator)
{
    while(iterator)
    {
        ra(a);
        iterator--;
    }
}

void do_rb(t_stack **b, int iterator)
{
    while(iterator)
    {
        rb(b);
        iterator--;
    }
}

void ra_rb_pb(t_stack **a, t_stack **b, t_stack *cheapest)
{
    int a_rot;
    int b_rot;
    int double_r;

    double_r = cheapest->double_rotations;
    a_rot = cheapest->a_rotations - double_r;
    b_rot = cheapest->b_rotations - double_r;
    if(double_r)
    {
        while(double_r)
        {
            rr(a, b);
            double_r--;
        }
    }
    if(a_rot > 0 && b_rot == 0)
        do_ra(a, cheapest->a_rotations);
    else if (a_rot == 0 && b_rot)
        do_rb(b, b_rot);
    pb(a, b);
}
