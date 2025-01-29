# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: istripol <istripol@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/20 19:47:13 by istripol          #+#    #+#              #
#    Updated: 2025/01/29 17:44:51 by istripol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = mov1.c mov2.c mov3.c mov4.c \
		check.c sort.c main.c \
		stack.c stack2.c daron.c tab.c \

NAME = push_swap

OBJECT_DIR = obj
OBJS = $(SRCS:%.c=$(OBJECT_DIR)/%.o)

# HEADERS = ./

.PHONY:	all, re, clean, fclean

all: $(OBJECT_DIR) $(OBJS)
	make -C ./libft
	gcc -g3 $(OBJS) libft/libft.a -o $(NAME)

re: fclean all

clean:
	rm -rf ${OBJECT_DIR}
	make clean -C libft/

fclean: clean
	make fclean -C libft/

$(OBJECT_DIR) :
	mkdir -p $(OBJECT_DIR) 
	

$(OBJS): $(OBJECT_DIR)/%.o : %.c
	gcc -g3 -c $< -o $@ 

# gcc -c $(SRCS:%.c) -o $(OBJS:%.o) 

# gcc -c $(SRCS) -o $(OBJS) 