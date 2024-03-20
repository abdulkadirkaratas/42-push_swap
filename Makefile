SRCS =  main.c	\
		instructions_1.c	\
		instructions_2.c	\
		instructions_3.c	\
		error_management.c 	\
		create_stack.c	\
		simple_sort.c	\
		radix_sort.c	\

OBJS = $(SRCS:.c=.o)

CC = gcc

RM = rm -rf

CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	cp libft/libft.a push_swap.a
	ar rcs push_swap.a $(OBJS)
	gcc push_swap.a -o $(NAME)
	$(RM) push_swap.a

clean:
	make clean -C libft
	$(RM) $(OBJS)

fclean: clean
	make fclean -C libft
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
