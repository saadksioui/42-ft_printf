# Flags
CFLAGS = -Wall -Wextra -Werror

# Project Files & Name
NAME = libftprintf.a
SRCS = ft_printf.c ft_print_char.c ft_print_hex.c ft_print_nbr.c ft_print_ptr.c ft_print_str.c ft_print_unsigned.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c ft_printf.h
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re