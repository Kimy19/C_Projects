CC = gcc -Wall -Wextra -Werror
NAME = libftprintf.a
SRCS = ft_printf.c print_format.c print_format2.c
OBJS = $(SRCS:.c=.o)
LIBFT = ./libft

all: $(NAME)

clean:
	rm -f $(OBJS)
	make -C libft clean
fclean: clean
	rm -f $(NAME)
	make -C libft fclean
re: fclean all

$(NAME): $(OBJS)
	make -C libft 
	cp libft/libft.a $(NAME)
	ar rc $@ $^

%.o: %.c
	$(CC) -c $< -o $@

.PHONY: all clean fclean re
