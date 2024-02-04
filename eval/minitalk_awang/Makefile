# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aawgku-o <aawgku-o@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/03 19:27:33 by aawgku-o          #+#    #+#              #
#    Updated: 2023/12/11 20:46:12 by aawgku-o         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER 			= server
CLIENT			= client

BSERVER 		= bonus_server
BCLIENT			= bonus_client

SERVERSRC 		= ./srcs/server.c
CLIENTSRC 		= ./srcs/client.c

BSERVERSRC 		= ./srcs/bonus_server.c
BCLIENTSRC 		= ./srcs/bonus_client.c

OBJCLIENT		= $(CLIENTSRC:.c=.o)
OBJSERVER		= $(SERVERSRC:.c=.o)

OBJBSERVER		= $(BSERVERSRC:.c=.o)
OBJBCLIENT		= $(BCLIENTSRC:.c=.o)


CC 				= gcc
CFLAGS 			= -Wall -Werror -Wextra
LIBPRTF 		= ./ft_printf/libftprintf.a
PRTFSRC			= ./ft_printf/

RM				= rm -f

all: 		  	$(SERVER) $(CLIENT) $(BSERVER) $(BCLIENT)

$(SERVER): 	  	$(OBJSERVER) 
			  	@make -s -C $(PRTFSRC)
			  	@$(CC) -o $(SERVER) $(SERVERSRC) $(LIBPRTF)

$(CLIENT): 	  	$(OBJCLIENT) 
			  	@make -s -C $(PRTFSRC)
			  	@$(CC) -o $(CLIENT) $(CLIENTSRC) $(LIBPRTF)

$(BSERVER):		$(OBJBSERVER)
				@make -s -C $(PRTFSRC)
			  	@$(CC) -o $(BSERVER) $(BSERVERSRC) $(LIBPRTF)

$(BCLIENT):		$(OBJBCLIENT)
				@make -s -C $(PRTFSRC)
			  	@$(CC) -o $(BCLIENT) $(BCLIENTSRC) $(LIBPRTF)

clean:		  
			  	@$(RM) $(OBJSERVER) $(OBJCLIENT) $(OBJBSERVER) $(OBJBCLIENT)
			  	@cd $(PRTFSRC) && make clean
	
fclean: 	  	clean
			  	@$(RM) $(SERVER) $(CLIENT) $(BSERVER) $(BCLIENT)
			  	@cd $(PRTFSRC) && make fclean
	
re: 		  	fclean all

.PHONY: 		all fclean re bonus
