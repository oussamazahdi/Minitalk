# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/29 11:43:23 by ozahdi            #+#    #+#              #
#    Updated: 2024/03/09 21:41:33 by ozahdi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC						=	cc
CFlags					=	-Wall -Wextra -Werror
CLIENT					=	client
SERVER					=	server
CLIENT_BONUS			=	client_bonus
SERVER_BONUS			=	server_bonus
CLIENT_SRC				=	client.c utils.c
SERVER_SRC				=	server.c utils.c
CLIENT_BONUS_SRC		=	client_bonus.c utils_bonus.c
SERVER_BONUS_SRC		=	server_bonus.c utils_bonus.c

OBJC					=	$(CLIENT_SRC:.c=.o)
OBJS					=	$(SERVER_SRC:.c=.o)
OBJCB					=	$(CLIENT_BONUS_SRC:.c=.o)
OBJSB					=	$(SERVER_BONUS_SRC:.c=.o)

all						:	$(CLIENT) $(SERVER)

bonus					:	$(CLIENT_BONUS) $(SERVER_BONUS)

$(CLIENT)				:	$(OBJC) minitalk.h
							$(CC) $(CFlags) $(OBJC) -o $(CLIENT)

$(SERVER)				:	$(OBJS) minitalk.h
							$(CC) $(CFlags) $(OBJS) -o $(SERVER)

$(CLIENT_BONUS)			:	$(OBJCB) minitalk_bonus.h
							$(CC) $(CFlags) $(OBJCB) -o $(CLIENT_BONUS)

$(SERVER_BONUS)			:	$(OBJSB) minitalk_bonus.h
							$(CC) $(CFlags) $(OBJSB) -o $(SERVER_BONUS)

%.o						:	%.c minitalk.h
							$(CC) $(CFLAGS) -c $< -o $@

clean					:
							@rm -f $(OBJC) $(OBJS) $(OBJCB) $(OBJSB)

fclean					:	clean
							@rm -f $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)

re						:	fclean all

.PHONY					:	clean