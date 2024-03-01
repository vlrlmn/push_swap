#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "Libft/libft.h"
# include "printf/libftprintf.h"
# include <stdbool.h>
# include <math.h>

typedef struct s_stack
{
    int			num; // value
    int			index;
	int			push_cost;
    int			insert_position; //target_pos
	int			cur_position; // pos
	bool		above_median;
	bool		cheapest;
    int         cost_insert_a;
    int         cost_top_b;
    struct		s_stack *next;
    struct		s_stack *prev;
	struct		s_stack *target_node;
}	t_stack;

/*Validation*/
bool	valid_nums(char **argv);
bool	is_num(char *argv);
bool	is_double(char **num_arr, char *num, int index);
bool	is_zero(char *num);
int	nums_cmp(char *s1, char *s2);
/*Utils*/
void	fill_stack_a(t_stack **a, t_stack **b, char **argv);
int	stack_len(t_stack *stack);
bool	stack_sorted(t_stack *stack);
/*Sort_algorithm*/
void	sort_stacks(t_stack **a, t_stack **b, int stack_len);
void	sort_three(t_stack **a);
void	sort_b (t_stack **a, t_stack **b);
/*Cost and cheapest move*/
void    do_cheapest_move(t_stack **a, t_stack **b);
void get_cost(t_stack **a, t_stack **b);
/*Free or return error*/
void free_err(t_stack **a, t_stack **b);
void free_argv(char **processed_argv);
void free_stack(t_stack **stack);
/*Operations*/
void pb(t_stack **stack_a, t_stack **stack_b);
void pa(t_stack **stack_a, t_stack **stack_b);
void rrr(t_stack **stack_a, t_stack **stack_b);
void rrb(t_stack **stack_b);
void rra(t_stack **stack_a);
void ss(t_stack **stack_a, t_stack **stack_b);
void sb(t_stack **stack_b);
void sa(t_stack **stack_a);
void rr(t_stack **stack_a, t_stack **stack_b);
void rb(t_stack **stack_b);
void ra(t_stack **stack_b);
/*Operation utils*/
t_stack *get_stack_bottom(t_stack *stack);
t_stack *get_stack_before_bottom(t_stack *stack);

#endif