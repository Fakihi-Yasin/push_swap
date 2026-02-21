NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
SRCS = src/main.c \
       src/parsing/args.c src/parsing/args_helpers.c src/parsing/args_utils.c \
       src/utils/stack_utils.c src/utils/stack_management.c src/utils/array_utils.c \
       src/utils/sort_large_helpers.c \
       src/operations/operations_push.c src/operations/operations_swap.c \
       src/operations/operations_rotate.c src/operations/operations_reverse.c \
       src/sorting/sort_small.c src/sorting/sort_dispatch.c \
       src/sorting/sort_large.c src/sorting/final_assembly.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) -I include -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
