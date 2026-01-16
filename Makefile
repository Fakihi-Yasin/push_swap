NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I include
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
SRCS = src/main.c src/args.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
