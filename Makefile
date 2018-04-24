# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/12 13:25:33 by jroussel          #+#    #+#              #
#    Updated: 2018/04/24 19:28:54 by jroussel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fillit
INC		= includes
SRC_DIR = src

SRCS	= main.c\
		  file.c\
		  util.c\
		  check.c\
		  parse.c\
		  print.c\
		  reduce.c\
		  map.c\
		  solve.c

OBJ_DIR = obj
OBJS	= $(SRCS:.c=.o)
CC		= gcc
CFLAGS	= #-Wall -Werror -Wextra
OFLAGS	= -pipe -flto
LIB_DIR	= libft
LIB		= libft.a

%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I $(INC) -c $<

$(NAME): lib $(OBJS)
	$(CC) $(CFLAGS) $(OFLAGS) $(OBJS) $(LIB_DIR)/$(LIB) -o $(NAME)
	@mkdir -p $(OBJ_DIR) 2> /dev/null
	@mv $(OBJS) $(OBJ_DIR)/

# Essentials
all: $(NAME)
clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIB_DIR) clean
fclean:
	rm -rf $(OBJ_DIR)
	rm -f $(NAME)
	$(MAKE) -C $(LIB_DIR) fclean
re: fclean all

# Libft
lib:
	$(MAKE) -C $(LIB_DIR)
