#include "push_swap.h"

void make_ra(t_stack **a, int iterator)
{
    while(iterator)
    {
        ra(a);
        iterator--;
    }
}

void make_rb(t_stack **b, int iterator)
{
    while(iterator)
    {
        rb(b);
        iterator--;
    }
}

void rb_pb(t_stack **a, t_stack **b, t_stack *cheapest)
{
    make_rb(b, cheapest->b_rotations);
    pb(a, b);
}

void ra_pb(t_stack **a, t_stack **b, t_stack *cheapest)
{
    make_ra(a, cheapest->a_rotations);
    pb(a, b);
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
        make_ra(a, cheapest->a_rotations);
    else if (a_rot == 0 && b_rot)
        make_rb(b, b_rot);
    pb(a, b);
}
