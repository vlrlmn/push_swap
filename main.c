#include "push_swap.h"

void perform_sorting(t_stack **a, t_stack **b, char **argv)
{
    fill_stack_a(a, b, argv);
    if (!stack_sorted(*a))
    {
        int len = stack_len(*a);
        if (len == 2)
            sa(a);
        else if (len == 3)
            sort_three(a);
        else
            sort_stacks(a, b, len);
    }
}

char **process_args(int argc, char **argv, int *need_free)
{
    char **split_argv;
	
	split_argv = NULL;
    if (argc == 1 || (argc == 2 && !argv[1][0]))
        exit(1);
    else if (argc == 2)
    {
        split_argv = ft_split(argv[1], ' ');
        *need_free = 1;
    }
    else
        split_argv = argv + 1;
    if (!valid_nums(split_argv))
        exit(1);
    return (split_argv);
}

int main(int argc, char **argv)
{
    t_stack *a;
	t_stack *b;
    int need_free;
    char **processed_argv;
	
	need_free = 0;
	a = NULL;
	b = NULL;
	processed_argv = process_args(argc, argv, &need_free);
    perform_sorting(&a, &b, processed_argv);
    free_stack(&a);
    free_stack(&b);
    if (need_free)
		free_argv(processed_argv);
}
