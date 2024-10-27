NAME = libftprintf.a

LIBFT = libft.a

CC = gcc

REMOVE = rm -f

CFLAGS = -Wall -Wextra -Werror

LIBC = ar -rcs

MAKE = make -C

SRCS = ft_printf.c\
	ft_print_cs.c\
	ft_print_diu.c\
	ft_print_xXp.c\
	ft_print_util.c\

LIBFT_DIR = libft

SRC_DIR = ./

OBJS = ${SRCS:.c=.o}

LIBR = $(LIBFT_DIR)/libft.a

all: ${NAME}

bonus: ${NAME}

${LIBR}:
	${MAKE} ${LIBFT_DIR}
	cp ${LIBR} . 
	mv ${LIBFT} ${NAME}

$(NAME): ${OBJS} ${LIBR}
	${LIBC} ${NAME} ${OBJS}

clean:
	${REMOVE} ${OBJS}
	${MAKE} $(LIBFT_DIR) clean

fclean: clean
	${REMOVE} ${NAME}
	${MAKE} $(LIBFT_DIR) fclean

re: fclean all	

.PHONY: all clean fclean re bonus
