# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mobin-mu <mobin-mu@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/26 17:52:45 by mobin-mu          #+#    #+#              #
#    Updated: 2024/10/27 17:57:22 by mobin-mu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= libft.a

SRCS			= ft_printf.c ft_print_words.c ft_print_num.c ft_print_pointer.c \
				  ft_print_utils.c ft_atoi.c ft_bzero.c ft_calloc.c ft_isalpha.c ft_isalnum.c \
					ft_isdigit.c ft_isascii.c ft_isprint.c ft_memchr.c ft_memcmp.c \
					ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c \
					ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c \
					ft_strrchr.c ft_tolower.c ft_toupper.c ft_itoa.c ft_substr.c \
					ft_strjoin.c ft_strtrim.c ft_split.c ft_strmapi.c ft_striteri.c \
					ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
					
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
