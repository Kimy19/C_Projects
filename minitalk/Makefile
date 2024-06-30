CC = gcc -Wall -Wextra -Werror
NAME1 = client
NAME2 = server
SRCS = server.c client.c
OBJS1 = client.o
OBJS2 = server.o
LIBFT = ./libft

all: $(NAME1) $(NAME2)

clean:
	rm -f $(OBJS1)
	rm -f $(OBJS2)
	make -C libft clean
fclean: clean
	rm -f $(NAME1)
	rm -f $(NAME2)
	make -C libft fclean
re: fclean all

$(NAME1): $(OBJS1)
	make -C libft 
	$(CC) -o $@ $^ libft/libft.a
$(NAME2): $(OBJS2)
	$(CC) -o $@ $^ libft/libft.a

%.o: %.c
	$(CC) -c $< -o $@

.PHONY: all clean fclean re
