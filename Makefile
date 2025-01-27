# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: istripol <istripol@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/20 19:47:13 by istripol          #+#    #+#              #
#    Updated: 2025/01/27 19:27:08 by istripol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = mov1.c mov2.c mov3.c mov4.c \
		check.c sort.c maintest.c \
		stack.c stack2.c daron.c tab.c \

NAME = push_swap


OBJS = ${SRCS:.c=.o}

# HEADERS = ./

all: ${OBJS}
	# mkdir 
	make -C ./libft
	gcc ${OBJS} libft/libft.a -o ${NAME} 


