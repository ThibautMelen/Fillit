# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/12 13:25:33 by jroussel          #+#    #+#              #
#    Updated: 2018/04/28 19:06:39 by jroussel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fillit
INC		= includes
SRC_DIR = src

SRCS	= $(SRC_DIR)/main.c\
		  $(SRC_DIR)/file.c\
		  $(SRC_DIR)/util.c\
		  $(SRC_DIR)/check.c\
		  $(SRC_DIR)/parse.c\
		  $(SRC_DIR)/print.c\
		  $(SRC_DIR)/reduce.c\
		  $(SRC_DIR)/map.c\
		  $(SRC_DIR)/solve.c

CC		= gcc
FLAGS	= -Wall -Werror -Wextra
LIB_DIR	= libft
LIB		= libft.a

$(NAME): lib
	$(CC) $(FLAGS) $(SRCS) $(LIB_DIR)/$(LIB) -o $(NAME)

# Essentials
all: $(NAME)
clean:
	$(MAKE) -C $(LIB_DIR) clean
fclean: clean
	rm -f $(LIB_DIR)/$(LIB)
	rm -f $(NAME)
re: fclean all

# Libft
lib:
	$(MAKE) -C $(LIB_DIR)
