NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I include
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
SRCS = src/main.c src/args.c src/args_helpers.c src/args_utils.c \
       src/stack_utils.c src/stack_management.c src/operations_push.c \
       src/operations_swap.c src/operations_rotate.c src/operations_reverse.c \
       src/sort_small.c src/sort_dispatch.c src/array_utils.c \
       src/sort_large.c src/sort_large_utils.c src/sort_large_helpers.c \
       src/final_assembly.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
