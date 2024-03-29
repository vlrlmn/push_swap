/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_push_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlomakin <vlomakin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 12:28:33 by vlomakin          #+#    #+#             */
/*   Updated: 2024/03/22 12:28:34 by vlomakin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_ra(t_stack **a, int iterator)
{
	while (iterator)
	{
		ra(a);
		iterator--;
	}
}

void	do_rb(t_stack **b, int iterator)
{
	while (iterator)
	{
		rb(b);
		iterator--;
	}
}

void	ra_rb_pb(t_stack **a, t_stack **b, t_stack *cheapest)
{
	int	a_rot;
	int	b_rot;
	int	double_r;

	double_r = cheapest->double_rotations;
	a_rot = cheapest->a_rotations - double_r;
	b_rot = cheapest->b_rotations - double_r;
	if (double_r)
	{
		while (double_r)
		{
			rr(a, b);
			double_r--;
		}
	}
	if (a_rot > 0 && b_rot == 0)
		do_ra(a, a_rot);
	else if (a_rot == 0 && b_rot)
		do_rb(b, b_rot);
	pb(a, b);
}
