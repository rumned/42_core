# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mobin-mu <mobin-mu@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/26 17:52:45 by mobin-mu          #+#    #+#              #
#    Updated: 2024/06/30 01:43:44 by mobin-mu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= libftprintf.a

SRCS			= ft_printf.c ft_print_words.c ft_print_num.c ft_print_pointer.c \
				  ft_print_utils.c
					
OBJS			= $(SRCS:.c=.o)

CC 				= cc
CFLAGS			= -Wall -Wextra -Werror
AR				= ar -rcs
RM				= rm -f

all:			$(NAME)

$(NAME):		$(OBJS)
				$(AR) $(NAME) $(OBJS)

clean:		
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)
			
re:				fclean all

.PHONY: 		all clean fclean re
