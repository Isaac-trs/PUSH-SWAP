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
		check.c sort.c main.c debug.c\
		stack.c stack2.c daron.c tab.c \

NAME = push_swap

LIBFT = printf/
LIBFTDIR = $(LIBFT)/libftprintf.a
OBJECT_DIR = objs
OBJS = $(SRCS:%.c=$(OBJECT_DIR)/%.o)
FLAGS = -Wall -Werror -Wextra

# HEADERS = ./

.PHONY:	all, re, clean, fclean, debug

all: $(NAME)
$(NAME): $(OBJECT_DIR) $(OBJS)
	make -C ./$(LIBFT)
	cc $(OBJS) $(LIBFTDIR) -o $(NAME) $(FLAGS)
	
debug:$(OBJECT_DIR) $(OBJS) 
	make -C ./$(LIBFT)
	cc -g3 $(OBJS) $(LIBFTDIR) -o $(NAME) $(FLAGS) 

re: fclean all

clean:
	rm -rf ${OBJECT_DIR}
	make clean -C ./$(LIBFT)

fclean: clean
	make fclean -C ./$(LIBFT)
	rm -rf $(NAME)


$(OBJECT_DIR) :
	mkdir -p $(OBJECT_DIR) 
	
$(OBJS): $(OBJECT_DIR)/%.o : %.c
	cc -c $< -o $@ $(FLAGS) 
