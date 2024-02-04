# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aawgku-o <aawgku-o@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/30 15:54:04 by aawgku-o          #+#    #+#              #
#    Updated: 2023/11/12 02:15:41 by aawgku-o         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= libftprintf.a
LIBFTNAME 	= libft.a
HEADERDIR 	= ./header
CC 			= cc
CFLAGS 		= -Wall -Werror -Wextra -I $(HEADERDIR) -I $(LIBFTDIR)
LIBFTDIR 	= ./libft
SRCSDIR		= ./srcs
MAINDIR		= ./main

SRCS 		= $(addprefix $(MAINDIR)/, ft_printf.c) $(addprefix $(SRCSDIR)/, ft_print_c.c ft_print_d.c \
			  ft_print_p.c ft_print_s.c ft_print_u.c ft_print_x.c ft_putchar.c \
			  percent.c)

OBJS 		= $(SRCS:.c=.o)
RM			= rm -f *.out

all: 		  $(NAME)

makelibft:
			  @make -C $(LIBFTDIR)
			  @cp $(LIBFTDIR)/$(LIBFTNAME) .
			  @mv $(LIBFTNAME) $(NAME)

$(NAME): 	  makelibft $(OBJS)
			  @ar -rcs $(NAME) $(OBJS)

clean:		  
			  @$(RM) $(OBJS)
			  @cd $(LIBFTDIR) && make clean
	
fclean: 	  clean
			  @$(RM) $(NAME)
			  @cd $(LIBFTDIR) && make fclean
	
re: 		  fclean all
