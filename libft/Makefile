# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mobin-mu <mobin-mu@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/05 03:53:58 by mobin-mu          #+#    #+#              #
#    Updated: 2023/11/29 16:30:14 by mobin-mu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= libft.a

SRCS			= 	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalpha.c ft_isalnum.c \
					ft_isdigit.c ft_isascii.c ft_isprint.c ft_memchr.c ft_memcmp.c \
					ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c \
					ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c \
					ft_strrchr.c ft_tolower.c ft_toupper.c ft_itoa.c ft_substr.c \
					ft_strjoin.c ft_strtrim.c ft_split.c ft_strmapi.c ft_striteri.c \
					ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
					
OBJS			= $(SRCS:.c=.o)

CC 				= cc
CFLAGS			= -Wall -Wextra -Werror -I.
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
