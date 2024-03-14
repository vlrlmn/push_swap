NAME = push_swap

CC = cc -Wall -Wextra -Werror -fsanitize=address --debug

SRC = 	0_main.c \
		0_err_free.c \
		0_operations_utils.c \
		0_push.c \
		0_rev_rotate.c \
		0_rotate.c \
		0_stack_utils.c \
		0_swap.c \
		0_validate_agrs.c \
		0_ft_atol.c \
		0_big_sort_utils.c \
		0_sort_three.c \
		0_calc_cost.c \
		0_init_sort.c \
		0_push_operations.c \

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
