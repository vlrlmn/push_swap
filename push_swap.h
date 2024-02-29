#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "Libft/libft.h"
# include "printf/libftprintf.h"
# include <stdbool.h>

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

void fill_stack_a(t_stack **a, t_stack **b, char **argv);
bool valid_nums(char **argv);
bool is_num(char *argv);
bool	is_double(char **num_arr, char *num, int index);
bool is_zero(char *num);
bool stack_sorted(t_stack *stack);
int nums_cmp(char *s1, char *s2);
int stack_len(t_stack *stack);
t_stack *get_stack_bottom(t_stack *stack);
t_stack *get_stack_before_bottom(t_stack *stack);
void sort_three(t_stack **a);
void free_err(t_stack **a, t_stack **b);

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

#endif