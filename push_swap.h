/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlomakin <vlomakin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:03:37 by vlomakin          #+#    #+#             */
/*   Updated: 2024/03/22 17:22:57 by vlomakin         ###   ########.fr       */
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
	int				a_rev_rotations;
	int				b_rev_rotations;
	int				double_rotations;
	int				double_rev_rotations;
	struct s_stack	*next;
	struct s_stack	*cheapest;
}					t_stack;

bool				valid_nums(char **argv);
bool				is_num(char *argv);
bool				is_double(char **num_arr, char *num, int index);
bool				is_zero(char *num);
int					nums_cmp(char *s1, char *s2);
void				fill_stack_a(t_stack **a, char **argv);
int					stack_len(t_stack *stack);
bool				stack_sorted(t_stack *stack);
int					ft_atol(char *str, t_stack **a);
void				get_position(t_stack **stack);
void				free_err(t_stack **a, t_stack **b);
void				free_argv(char **processed_argv);
void				free_stack(t_stack **stack);
void				exit_with_err(char *msg, char **args);
void				free_err1(t_stack **a);
void				finish_exit(int fd);
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
t_stack				*get_stack_bottom(t_stack *stack);
t_stack				*get_stack_before_bottom(t_stack *stack);
void				define_min_max(t_stack *stack);
int					is_num_exceed_limits(int number, t_stack **b);
int					get_target_index(t_stack **a, int num);
void				find_cheapest(t_stack **a);
int					target_index_in_limits(t_stack **a, int num);
void				sort_three(t_stack **a);
void				set_cost_in_a(t_stack *a, t_stack **b);
void				big_sort(t_stack **a, t_stack **b);
void				ra_rb_pb(t_stack **a, t_stack **b, t_stack *cheapest);
void				rra_rrb_pb(t_stack **a, t_stack **b, t_stack *cheapest);
void				do_rb(t_stack **b, int iterator);
void				do_ra(t_stack **a, int iterator);
void				do_rra(t_stack **a, int iterator);
void				do_rrb(t_stack **a, int iterator);
void				set_cost_in_a(t_stack *a, t_stack **b);
void				define_cheapest_instructions(t_stack *a);
void				rev_rev_instruction(t_stack *a, int rev_rev_count);
void				rev_rot_instruction(t_stack *a, int rev_rot_count);
void				rot_rev_instruction(t_stack *a, int rot_rev_count);
void				rot_rot_instruction(t_stack *a, int rot_rot_count);
void				calc_cost_for_node(t_stack **b_stack, t_stack *a, int len_a,
						int a_index);
#endif