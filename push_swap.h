/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:03:37 by vlomakin          #+#    #+#             */
/*   Updated: 2024/03/12 19:30:46 by lomakinaval      ###   ########.fr       */
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
	int				index;
	int				insert_position;
	int				cur_position;
	bool			cheapest;
	int				cost_insert_a;
	int				cost_top_b;
	int				max_num;
	int				min_num;
	int				index_of_max;
	int				index_of_min;
	struct s_stack	*next;
	struct s_stack	*prev;
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
void				get_index(t_stack *a);
int					ft_atol(char *str);
/*Sort_algorithm*/
void				sort_stacks(t_stack **a, t_stack **b);
void				sort_b(t_stack **a, t_stack **b);
void				move_a(t_stack **a);
int					find_max(t_stack *stack);
void				get_position(t_stack **stack);
/*Cost and cheapest move*/
void				do_cheapest_move(t_stack **a, t_stack **b);
void				get_cost(t_stack **a, t_stack **b);
void				do_rb(t_stack **b, int *cost);
void				do_ra(t_stack **a, int *cost);
void				do_rrr(t_stack **a, t_stack **b, int *cost_a, int *cost_b);
void				do_rr(t_stack **a, t_stack **b, int *cost_a, int *cost_b);
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
void				set_cost_in_a(t_stack *cur_a_node, int node_a_index, t_stack **b);
/*Init_sort*/
void	big_sort(t_stack **a, t_stack **b);

#endif