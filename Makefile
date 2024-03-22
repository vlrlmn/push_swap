NAME = push_swap

CC = cc -Wall -Wextra -Werror 

SRC = 	main.c \
		ret_error.c \
		free_memory.c \
		operations_utils.c \
		push.c \
		rev_rotate.c \
		rotate.c \
		stack_utils.c \
		swap.c \
		validate_agrs.c \
		ft_atol.c \
		big_sort_utils.c \
		sort_three.c \
		calc_cost.c \
		init_sort.c \
		push_operations.c \
		set_cheapest_instructions.c \
		push_rev_operations.c \

OBJ = $(SRC:.c=.o)

HDRS = ../push_swap.h

RM = rm -f

LIBFT = Libft/libft.a

PRINTF = printf/libftprintf.a

.c.o:
	${CC} -I ${HDRS} -c $< -o ${<:.c=.o}

$(NAME):		$(OBJ)
				$(MAKE) -C printf
				$(MAKE) -C Libft
				${CC} -o $(NAME) $(OBJ) $(LIBFT) $(PRINTF)

all:			$(NAME)

clean:
			${RM} $(OBJ)
			$(MAKE) -C printf clean
			$(MAKE) -C Libft clean


fclean:		clean
		${RM} $(NAME)
		$(MAKE) -C printf fclean
		$(MAKE) -C Libft fclean

re:			fclean all

.PHONY:		all clean fclean re
