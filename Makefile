# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: swquinc <swquinc@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/23 19:48:56 by hovalygta         #+#    #+#              #
#    Updated: 2020/10/22 22:37:39 by swquinc          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	miniRT

SRC_NAME		=	main.c errors_handler.c parse_main.c parse_utils.c parse_utils2.c parse_obj.c camera.c vec.c vec2.c \
o_sphere.c o_plane.c o_square.c o_cylinder.c o_triangle.c raytrace.c light.c

OBJ				=	main.o errors_handler.o parse_main.o parse_utils.o parse_utils2.o parse_obj.o camera.o vec.o vec2.o \
o_sphere.o o_plane.o o_square.o o_cylinder.o o_triangle.o raytrace.o light.o

SRC_DIR			=	src
OBJ_DIR			=	obj
LIBFT_DIR		=	libft
LIBMLX_DIR		=	minilibx

LIBFT_A			=	$(LIBFT_DIR)/libft.a
LIBMLX_A		=	$(LIBMLX_DIR)/libmlx.a

CC				=	gcc
FLAGS			=	-Wall -Wextra -Werror
OPENGL			=	-framework OpenGL -framework AppKit
INCLUDES		= 	-I includes -I $(LIBFT_DIR) -I $(LIBMLX_DIR)
SRC				=	$(addprefix $(SRC_DIR)/, $(SRC_NAME))

all: $(NAME)

$(NAME):
	make -C $(LIBFT_DIR)
	make -C $(LIBMLX_DIR)
	$(CC) $(SRC) $(LIBFT_A) $(LIBMLX_A) $(INCLUDES) $(OPENGL)

clean:
	make clean -C $(LIBFT_DIR)
	make clean -C $(LIBMLX_DIR)

fclean: 
	make fclean -C $(LIBFT_DIR)
	make clean -C $(LIBMLX_DIR)

re: fclean all


