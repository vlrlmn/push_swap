NAME = push_swap

CC = cc -Wall -Wextra -Werror -fsanitize=address --debug

SRC = 	main.c \
		start_sort_algorithm.c \
		call_sort.c \
		finish_sort.c \
		calculate_cost.c \
		do_cheapest_move.c \
		err_free.c \
		operations_utils.c \
		push.c \
		rev_rotate.c \
		rotate.c \
		stack_utils.c \
		swap.c \
		validate_agrs.c \
		cheapest_move_operations.c \
		ft_atol.c \
		0_big_sort_utils.c \
		0_sort_three.c \
		0_calc_cost.c \
		0_init_sort.c \

OBJ = $(SRC:.c=.o)

HDRS = push_swap.h

RM = rm -f

LIBFT = Libft/libft.a

PRINTF = printf/libftprintf.a

.c.o:
	${CC} -I ${HDRS} -c $< -o ${<:.c=.o}

$(NAME):		$(OBJ)
				$(MAKE) -C printf
				$(MAKE) -C libft
				${CC} -o $(NAME) $(OBJ) $(LIBFT) $(PRINTF)

all:			$(NAME)

clean:
			${RM} $(OBJ)
			$(MAKE) -C printf clean
			$(MAKE) -C libft clean


fclean:		clean
		${RM} $(NAME)
		$(MAKE) -C printf fclean
		$(MAKE) -C libft fclean

re:			fclean all

.PHONY:		all clean fclean re
