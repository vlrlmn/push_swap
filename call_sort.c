/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:03:20 by vlomakin          #+#    #+#             */
/*   Updated: 2024/03/05 10:48:14 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	sort_three(t_stack **stack)
// {
// 	int	highest;

// 	if (stack_sorted(*stack))
// 		return ;
// 	highest = find_max(*stack);
// 	if ((*stack)->index == highest)
// 		ra(stack);
// 	else if ((*stack)->next->index == highest)
// 		rra(stack);
// 	if ((*stack)->index > (*stack)->next->index)
// 		sa(stack);
// }

void sort_three(t_stack **stack)
{
    int top;
    int middle;
    int bottom;

	top = (*stack)->num;
	middle  = (*stack)->next->num;
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

void	get_position(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = *stack;
	if (!stack)
		return ;
	while (tmp)
	{
		tmp->cur_position = i;
		tmp = tmp->next;
		i++;
	}
}

int	find_insert_pos(t_stack **a, int b_idx, int *min_pos_idx, int *min_idx)
{
	t_stack	*cpy_a;
	int		insert_pos;
	int		iterator;

	cpy_a = *a;
	insert_pos = -1;
	iterator = 0;
	while (cpy_a)
	{
		if (cpy_a->index > b_idx && cpy_a->index < *min_idx)
		{
			*min_idx = cpy_a->index;
			insert_pos = iterator;
		}
		else if (cpy_a->index > b_idx && insert_pos == -1)
		{
			*min_pos_idx = iterator;
		}
		cpy_a = cpy_a->next;
		iterator++;
	}
	return (insert_pos);
}

void	find_b_position_in_a(t_stack **a, t_stack **b)
{
	t_stack	*cpy_b;
	int		result;
	int		min_pos_idx;
	int		min_idx;

	cpy_b = *b;
	if (!a || !b)
		return ;
	while (cpy_b)
	{
		min_pos_idx = -1;
		min_idx = INT_MAX;
		result = find_insert_pos(a, cpy_b->index, &min_pos_idx, &min_idx);
		if (result == -1)
			result = min_pos_idx;
		cpy_b->insert_position = result;
		cpy_b = cpy_b->next;
	}
}

void	sort_b(t_stack **a, t_stack **b)
{
	while (*b)
	{
		get_position(a);
		get_position(b);
		find_b_position_in_a(a, b);
		get_cost(a, b);
		do_cheapest_move(a, b);
	}
	// if (!stack_sorted(*a))
	// 	move_a(a);
}
