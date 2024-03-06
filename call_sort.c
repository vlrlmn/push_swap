/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:03:20 by vlomakin          #+#    #+#             */
/*   Updated: 2024/03/05 18:50:48 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (!stack)
		return ;
	tmp = *stack;
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
			*min_pos_idx = iterator;
		cpy_a = cpy_a->next;
		iterator++;
	}
	if (insert_pos == -1 && *min_pos_idx == -1)
        insert_pos = iterator;
	printf("target position b in a: %d\n", insert_pos);
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
		t_stack *tmp = *a;
		while(tmp)
		{
			printf("num a: %d\n", tmp->num);
			printf("cur position a: %d\n", tmp->cur_position);
			tmp = tmp->next;
		}
		get_position(b);
		tmp = *b;
		while(tmp)
		{
			printf("num b: %d\n", tmp->num);
			printf("cur position b: %d\n", tmp->cur_position);
			tmp = tmp->next;
		}
		find_b_position_in_a(a, b);
		get_cost(a, b);
		tmp = *a;
		// while(tmp)
		// {
		// 	printf("cost a: %d\n", tmp->cost_top_b);
		// 	tmp = tmp->next;
		// }
		// tmp = *b;
		// while(tmp)
		// {
		// 	printf("cost b: %d\n", tmp->cost_insert_a);
		// 	tmp = tmp->next;
		// }
		do_cheapest_move(a, b);
	// 	tmp = *a;
	// 	while(tmp)
	// 	{
	// 		printf("cheapest move a: %d\n", tmp->num);
	// 		tmp = tmp->next;
	// 	}
	// 	tmp = *b;
	// 	while(tmp)
	// 	{
	// 		printf("cheapest move b: %d\n", tmp->num);
	// 		tmp = tmp->next;
	// 	}
	}
}
