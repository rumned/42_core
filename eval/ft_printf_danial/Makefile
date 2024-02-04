# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mumohd-z <mumohd-z@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/03 01:50:54 by mumohd-z          #+#    #+#              #
#    Updated: 2024/01/03 22:07:46 by mumohd-z         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -O3
MAKE_LIB = ar -rcs

INCS = .


SRCS = ft_printf.c \
	   ft_printc.c \
	   ft_prints.c \
	   ft_printd.c \
	   ft_printu.c \
	   ft_printx.c \
	   ft_printp.c \
	   ft_percent.c \

OBJS = $(SRCS:.c=.o)

bonus : all

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT) 
	$(MAKE_LIB) $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -I$(INCS) 
	
$(LIBFT) :
	cd $(LIBFT_PATH) && make 
	cp $(LIBFT) $(NAME) 

clean :
	rm -rf $(OBJS) $(NAME)

fclean : clean
	cd $(LIBFT_PATH) && make fclean

re: fclean all

.PHONY: all bonus clean fclean re