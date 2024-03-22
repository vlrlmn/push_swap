/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cheapest_instructions.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlomakin <vlomakin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 12:23:42 by vlomakin          #+#    #+#             */
/*   Updated: 2024/03/22 12:27:47 by vlomakin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rot_rot_instruction(t_stack *a, int rot_rot_count)
{
	a->a_rev_rotations = 0;
	a->b_rev_rotations = 0;
	a->double_rev_rotations = 0;
	a->cost_to_push_a = rot_rot_count;
}

void	rot_rev_instruction(t_stack *a, int rot_rev_count)
{
	a->a_rev_rotations = 0;
	a->b_rotations = 0;
	a->double_rev_rotations = 0;
	a->double_rotations = 0;
	a->cost_to_push_a = rot_rev_count;
}

void	rev_rot_instruction(t_stack *a, int rev_rot_count)
{
	a->a_rotations = 0;
	a->b_rev_rotations = 0;
	a->double_rev_rotations = 0;
	a->double_rotations = 0;
	a->cost_to_push_a = rev_rot_count;
}

void	rev_rev_instruction(t_stack *a, int rev_rev_count)
{
	a->a_rotations = 0;
	a->b_rotations = 0;
	a->double_rotations = 0;
	a->cost_to_push_a = rev_rev_count;
}

void	define_cheapest_instructions(t_stack *a)
{
	int	rot_rev_count;
	int	rev_rot_count;
	int	rot_rot_count;
	int	rev_rev_count;

	rot_rot_count = 1 + a->a_rotations + a->b_rotations - a->double_rotations;
	rot_rev_count = 1 + a->a_rotations + a->b_rev_rotations;
	rev_rot_count = 1 + a->a_rev_rotations + a->b_rotations;
	rev_rev_count = 1 + a->a_rev_rotations + a->b_rev_rotations
		- a->double_rev_rotations;
	if (rot_rot_count <= rot_rev_count && rot_rot_count <= rev_rot_count
		&& rot_rot_count <= rev_rev_count)
		rot_rot_instruction(a, rot_rot_count);
	else if (rot_rev_count <= rot_rot_count && rot_rev_count <= rev_rot_count
		&& rot_rev_count <= rev_rev_count)
		rot_rev_instruction(a, rot_rev_count);
	else if (rev_rot_count <= rot_rot_count && rev_rot_count <= rot_rev_count
		&& rev_rot_count <= rev_rev_count)
		rev_rot_instruction(a, rev_rot_count);
	else
		rev_rev_instruction(a, rev_rev_count);
}
