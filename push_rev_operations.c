/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_push_rev_operations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlomakin <vlomakin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 12:30:42 by vlomakin          #+#    #+#             */
/*   Updated: 2024/03/22 12:30:44 by vlomakin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rra(t_stack **a, int iterator)
{
	while (iterator)
	{
		rra(a);
		iterator--;
	}
}

void	do_rrb(t_stack **a, int iterator)
{
	while (iterator)
	{
		rrb(a);
		iterator--;
	}
}

void	rra_rrb_pb(t_stack **a, t_stack **b, t_stack *cheapest)
{
	int	a_rrot;
	int	b_rrot;
	int	double_rr;

	double_rr = cheapest->double_rev_rotations;
	a_rrot = cheapest->a_rev_rotations - double_rr;
	b_rrot = cheapest->b_rev_rotations - double_rr;
	if (double_rr)
	{
		while (double_rr)
		{
			rrr(a, b);
			double_rr--;
		}
	}
	if (a_rrot && b_rrot == 0)
		do_rra(a, a_rrot);
	else if (a_rrot == 0 && b_rrot)
		do_rrb(b, b_rrot);
	pb(a, b);
}
