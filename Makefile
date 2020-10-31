#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: swquinc <swquinc@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/23 19:48:56 by hovalygta         #+#    #+#              #
#    Updated: 2020/10/31 20:15:53 by hovalygta        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	miniRT

SRC_NAME		=	main.c \
					errors_handler.c \
					parse_main.c \
					parse_utils.c \
					parse_utils2.c \
					parse_obj.c \
					camera.c \
					vec.c \
					vec2.c \
					o_sphere.c \
					o_plane.c \
					o_square.c \
					o_cylinder.c \
					o_triangle.c \
					o_circle.c \
					raytrace.c \
					light.c \
					utils.c \
					bmp.c \
					free.c \

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

OBJ 			= 	$(addprefix $(OBJ_DIR)/, $(SRC_NAME:.c=.o))

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c ./includes/minirt.h
		$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJ)
	make -C $(LIBFT_DIR)
	make -C $(LIBMLX_DIR)
	$(CC) $(FLAGS) $(OBJ) $(INCLUDES) $(LIBFT_A) $(LIBMLX_A) $(OPENGL) -o $(NAME)

clean:
	/bin/rm -f $(OBJ_DIR)/*
	/bin/rm -rf $(OBJ_DIR)
	make clean -C $(LIBFT_DIR)
	make clean -C $(LIBMLX_DIR)

fclean: clean
	/bin/rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

# leaks:
#     valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s \
#     ./miniRT ./scenes/plane.rt --save

.PHONY: all clean fclean re leaks
