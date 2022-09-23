NAME = libftprintf.a

SRCS =	ft_check_flags.c	ft_print_argument.c	ft_print_char.c\
		ft_print_dec.c	ft_print_hex.c	ft_print_per.c\
		ft_print_ptr.c	ft_print_str.c	ft_printf.c\
		utilities/ft_abs_ll.c	utilities/ft_atoi.c	utilities/ft_dec_to_hex.c\
		utilities/ft_declen.c	utilities/ft_isalpha.c	utilities/ft_len_of_hex.c\
		utilities/ft_max.c	utilities/ft_putchar_len.c	utilities/ft_putchar.c\
		utilities/ft_putnbr_ll.c	utilities/ft_putstr.c	utilities/ft_strlen.c\

OBJS = $(SRCS:%.c=%.o)

FLAGS = -Wall -Wextra -Werror

HEADER = ft_printf.h

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	ar rc $(NAME) $?

%.o: %.c $(HEADER)
	cc $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(NAME)