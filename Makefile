# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pvandamm <pvandamm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/24 10:54:03 by pvandamm          #+#    #+#              #
#    Updated: 2019/01/22 20:12:45 by pvandamm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = gcc

CFLAGS = -Wall -Wextra -Werror -O3

MLX_FLAGS = -framework OpenGL -framework AppKit

LIB = ./libft/libft.a

MLX = ./minilibx/libmlx.a

LIB_PATH = ./libft

MLX_PATH = ./minilibx

INCLUDES = libft/includes ./includes ./minilibx

SRC_PATH = ./srcs

OBJ_PATH = ./objs

SRC_NAME = 	main.c 					\
			utils.c					\
			mandelbrot.c			\
			julia.c					\
			input.c					\
			burningship.c			\

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ) $(LIB) $(MLX)
	@$(CC) $(CFLAGS) $(MLX_FLAGS) -o $@ $^
	@echo "\x1b[36m[FRACTOL COMPILED]\x1b[0m"

sale: $(OBJ) $(LIB) $(MLX)
	@$(CC) $(MLX_FLAGS) -o $@ $^
	@echo "\x1b[36m[FRACTOL COMPILED]\x1b[0m"

$(LIB):
	@echo "\x1b[36m[LIBFT COMPILED]\x1b[0m"
	@make -C $(LIB_PATH)

$(MLX):
	@echo "\x1b[36m[MLX COMPILED]\x1b[0m"
	@make -C $(MLX_PATH)

$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c $(INCLUDES)
	@mkdir -p $(OBJ_PATH)
	@$(CC) -o $@ -c $< $(addprefix -I , $(INCLUDES))

clean:
	@make clean -C $(LIB_PATH)
	@make clean -C $(MLX_PATH)
	@rm -rf $(OBJ)
	@echo "\033[33mall $(NAME) .o files are removed\033[0m"

fclean: clean
	@make fclean -C $(LIB_PATH)
	@rm -f $(NAME)
	@echo "\033[31m$(NAME) is deleted\033[0m"

re: fclean all

.PHONY: all, clean, fclean, re
