#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;

	a = NULL;
	b = NULL;
    if (argc == 1 || (argc == 2 && !argv[1][0]))
        exit(1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
    if (!valid_nums(argv + 1))
        exit (1);
	fill_stack_a(&a, argv + 1);
	if(!stack_sorted(a))
	{
		if(stack_len(a) == 2)
			sa(&a);
		else if(stack_len(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b, stack_len(a));
	}
	free_stack(&a);
	free_stack(&b);
    return(0);
}
