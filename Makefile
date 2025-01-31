# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: istripol <istripol@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/20 19:47:13 by istripol          #+#    #+#              #
#    Updated: 2025/01/31 03:28:07 by istripol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = mov1.c mov2.c mov3.c mov4.c \
		check.c sort.c main.c \
		stack.c stack2.c daron.c tab.c \

NAME = push_swap

OBJECT_DIR = obj
OBJS = $(SRCS:%.c=$(OBJECT_DIR)/%.o)
FLAGS = -Wall -Werror -Wextra
DEBUG = $(debug.c=$(OBJECT_DIR)/%.o)
# HEADERS = ./

.PHONY:	all, re, clean, fclean, debug

all: $(NAME)
$(NAME): $(OBJECT_DIR) $(OBJS)
	make -C ./libft
	cc $(OBJS) libft/libft.a -o $(NAME) $(FLAGS)
	
debug:$(OBJECT_DIR) $(OBJS) 
	make -C ./libft
	cc -g3 -c debug.c -o $(OBJECT_DIR)/debug.o $(FLAGS)
	cc -g3 $(OBJS) $(DEBUG) libft/libft.a -o $(NAME) $(FLAGS) 

re: fclean all

clean:
	rm -rf ${OBJECT_DIR}
	make clean -C libft/

fclean: clean
	make fclean -C libft/
	rm $(NAME)

$(OBJECT_DIR) :
	mkdir -p $(OBJECT_DIR) 
	
$(OBJS): $(OBJECT_DIR)/%.o : %.c
	cc -c $< -o $@ $(FLAGS) 

# gcc -c $(SRCS:%.c) -o $(OBJS:%.o) 

# gcc -c $(SRCS) -o $(OBJS) 