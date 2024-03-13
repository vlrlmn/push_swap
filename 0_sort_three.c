/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_sort_three.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlomakin <vlomakin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:52:55 by vlomakin          #+#    #+#             */
/*   Updated: 2024/03/13 12:52:56 by vlomakin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack)
{
	int	top;
	int	middle;
	int	bottom;

	top = (*stack)->num;
	middle = (*stack)->next->num;
	bottom = (*stack)->next->next->num;
	if (top > middle && middle < bottom && top < bottom)
		sa(stack);
	else if (top > middle && middle > bottom && top > bottom)
	{
		sa(stack);
		rra(stack);
	}
	else if (top > middle && middle < bottom && top > bottom)
		ra(stack);
	else if (top < middle && middle > bottom && top < bottom)
	{
		sa(stack);
		ra(stack);
	}
	else if (top < middle && middle > bottom && top > bottom)
		rra(stack);
}
