# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hetan <hetan@student.42kl.edu.my>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/29 20:28:13 by hetan             #+#    #+#              #
#    Updated: 2024/01/03 00:40:48 by hetan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
HEADER = ../header
CFLAGS = -Wall -Wextra -Werror -I $(HEADER)
RM = rm -rf
PRINTF_DIRS = ft_printf/src/
PRINTF_DIRU = ft_printf/utils/
GNL_DIRU = get_next_line/
SOURCE = ft_isascii.c ft_putchar_fd.c ft_strdup.c ft_strmapi.c ft_tolower.c		\
			ft_atoi.c ft_isdigit.c ft_memchr.c ft_putendl_fd.c ft_striteri.c	\
			ft_strncmp.c ft_toupper.c ft_bzero.c ft_isprint.c ft_memcmp.c		\
			ft_putnbr_fd.c ft_strjoin.c ft_strnstr.c ft_calloc.c ft_itoa.c		\
			ft_memcpy.c ft_putstr_fd.c ft_strlcat.c ft_strrchr.c ft_isalnum.c	\
			ft_memmove.c ft_split.c ft_strlcpy.c ft_strtrim.c ft_isalpha.c		\
			ft_memset.c ft_strchr.c ft_strlen.c	ft_substr.c						\
			ft_lstadd_back.c ft_lstadd_front.c ft_lstdelone.c ft_lstiter.c		\
			ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c ft_lstclear.c		\
			$(PRINTF_DIRS)ft_printf.c $(PRINTF_DIRS)ft_printf_util.c			\
			$(PRINTF_DIRS)specifier_util.c $(PRINTF_DIRS)specifier_flags.c		\
			$(PRINTF_DIRS)convert_flags.c $(PRINTF_DIRS)convert_length.c		\
			$(PRINTF_DIRS)convert_precision.c									\
			$(PRINTF_DIRU)ft_print_i.c $(PRINTF_DIRU)ft_print_s.c				\
			$(PRINTF_DIRU)ft_print_u.c $(PRINTF_DIRU)ft_print_x.c				\
			$(PRINTF_DIRU)ft_print_p.c $(PRINTF_DIRU)ft_print_c.c				\
			$(PRINTF_DIRU)libft_extend.c $(PRINTF_DIRU)ft_print_o.c				\
			$(GNL_DIRU)get_next_line.c $(GNL_DIRU)get_next_line_utils.c			
OBJF = $(SOURCE:.c=.o)

all: $(NAME)

$(NAME): $(OBJF)
	@echo "Compiling..."
	@ar rcs $(NAME) $(OBJF)
	@echo "Libft compiled!\n"

%.o : %.c
	@$(CC) $(CFLAGS) -I $(HEADER) -c $< -o $@

clean:
	@echo "Cleaning o.o files please wait..."
	@$(RM) $(OBJF)
	@echo "Done clean!\n"

fclean: clean
	@echo "fclean starts"
	@$(RM) $(NAME)
	@echo "DONE FCLEAN!\n"

re: fclean all
	@echo "\ndone re-make"

.PHONY : all clean fclean re
