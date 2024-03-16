/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:03:37 by vlomakin          #+#    #+#             */
/*   Updated: 2024/03/15 18:16:14 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"
# include "printf/libftprintf.h"
# include <limits.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				num;
	int				cur_position;
	int				max_num;
	int				min_num;
	int				index_of_max;
	int				index_of_min;
	int				cost_to_push_a;
	int				a_rotations;
	int				b_rotations;
	int				double_rotations;
	struct s_stack	*next;
	struct s_stack	*prev;
	struct s_stack	*cheapest;
}					t_stack;

/*Validation*/
bool				valid_nums(char **argv);
bool				is_num(char *argv);
bool				is_double(char **num_arr, char *num, int index);
bool				is_zero(char *num);
int					nums_cmp(char *s1, char *s2);
/*Utils*/
void				fill_stack_a(t_stack **a, char **argv);
int					stack_len(t_stack *stack);
bool				stack_sorted(t_stack *stack);
int					ft_atol(char *str);
/*Sort_algorithm*/
void				get_position(t_stack **stack);

/*Free or return error*/
void				free_err(t_stack **a, t_stack **b);
void				free_argv(char **processed_argv);
void				free_stack(t_stack **stack);
void				exit_with_err(char *msg);
void				free_err1(t_stack **a);
/*Operations*/
void				pb(t_stack **stack_a, t_stack **stack_b);
void				pa(t_stack **stack_a, t_stack **stack_b);
void				rrr(t_stack **stack_a, t_stack **stack_b);
void				rrb(t_stack **stack_b);
void				rra(t_stack **stack_a);
void				ss(t_stack **stack_a, t_stack **stack_b);
void				sb(t_stack **stack_b);
void				sa(t_stack **stack_a);
void				rr(t_stack **stack_a, t_stack **stack_b);
void				rb(t_stack **stack_b);
void				ra(t_stack **stack_b);
/*Operation utils*/
t_stack				*get_stack_bottom(t_stack *stack);
t_stack				*get_stack_before_bottom(t_stack *stack);

/*New algotithm*/
/*big_sort_utils*/
void				define_min_max(t_stack *stack);
int					is_num_exceed_limits(int number, t_stack **b);
/*Sort_three*/
void				sort_three(t_stack **a);
/*calc_cost*/
void				set_cost_in_a(t_stack *a, t_stack **b);
/*Init_sort*/
void	big_sort(t_stack **a, t_stack **b);
void ra_rb_pb(t_stack **a, t_stack **b, t_stack *cheapest);
void ra_pb(t_stack **a, t_stack **b, t_stack *cheapest);
void rb_pb(t_stack **a, t_stack **b, t_stack *cheapest);

void	set_cost_in_a(t_stack *a, t_stack **b);
#endif