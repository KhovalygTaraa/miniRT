# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: swquinc <swquinc@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/23 19:48:56 by hovalygta         #+#    #+#              #
#    Updated: 2020/10/04 20:16:28 by swquinc          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	miniRT

SRC_NAME		=	main.c errors_handler.c parse_main.c utils.c utils2.c parse_obj.c

OBJ				=	main.o errors_handler.o parse_main.o utils.o utils2.o parse_obj.o


SRC_DIR			=	src
OBJ_DIR			=	obj
LIBFT_DIR		=	libft

LIBFT_A			=	$(LIBFT_DIR)/libft.a

CC				=	gcc
FLAGS			=	-Wall -Wextra -Werror
INCLUDES		= 	-I includes -I $(LIBFT_DIR)
SRC				=	$(addprefix $(SRC_DIR)/, $(SRC_NAME))

all: $(NAME)

$(NAME):
	make -C $(LIBFT_DIR)
	$(CC) $(SRC) $(LIBFT_A) $(INCLUDES)

clean:
	make clean -C $(LIBFT_DIR)

fclean: 
	make fclean -C $(LIBFT_DIR)
	
re: fclean all


