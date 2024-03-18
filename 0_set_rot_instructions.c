#include "push_swap.h"

void rot_rot_instruction(t_stack *a, int rot_rot_count)
{
	a->a_rev_rotations = 0;
	a->b_rev_rotations = 0;
	a->double_rev_rotations = 0;
	a->cost_to_push_a = rot_rot_count;
}

void rot_rev_instruction(t_stack *a, int rot_rev_count)
{
	a->a_rev_rotations = 0;
	a->b_rotations = 0;
	a->double_rev_rotations = 0;
	a->double_rotations = 0;
	a->cost_to_push_a = rot_rev_count;
}

void rev_rot_instruction(t_stack *a, int rev_rot_count)
{
	a->a_rotations = 0;
	a->b_rev_rotations = 0;
	a->double_rev_rotations = 0;
	a->double_rotations = 0;
	a->cost_to_push_a = rev_rot_count;
}

void rev_rev_instruction(t_stack *a, int rev_rev_count)
{
	a->a_rotations = 0;
	a->b_rotations = 0;
	a->double_rotations = 0;
	a->cost_to_push_a = rev_rev_count;
}
