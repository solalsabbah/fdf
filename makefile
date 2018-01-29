# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/08 11:30:47 by ssabbah           #+#    #+#              #
#    Updated: 2018/01/29 13:55:16 by ssabbah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC_FILES = fdf.c\
			ft_events.c\
			map_dimension.c\
			fill_image.c\

OBJ_FILES = $(SRC_FILES:.c=.o)

SRC_PATH = src/
OBJ_PATH = obj/

SRC = $(addprefix $(SRC_PATH),$(SRC_FILES))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_FILES))
LIB = $(addprefix -I,$(LIB_PATH))

CC = gcc
FLAGS = -Wall -Wextra -Werror -g

LIBFT = -L./libft -lft
MLX = -L./minilibx -lmlx -framework OpenGL -framework Appkit

all: $(NAME)

$(NAME): $(OBJ)
	@ make -C libft/
	@ make -C minilibx/
	@ $(CC) $(FLAGS) $(LIBFT) $(MLX) $^ -o $@
	@ echo "\033[32mCompilation done : FDF is ready to be used\033[0m"

$(OBJ_PATH)%.o:$(SRC_PATH)%.c
	@ mkdir -p $(OBJ_PATH)
	@ $(CC) $(FLAGS) $(LIB) -o $@ -c $<

clean:
	@ make -C libft clean
	@ make -C minilibx clean
	@ rm -rf $(OBJ)
	@ rm -rf $(OBJ_PATH)
	@ echo "\033[32mCleaning obj\033[0m"

fclean: clean
	@ make -C libft fclean
	@ make -C minilibx fclean
	@ rm -f $(NAME)
	@ echo "\033[32mCleaning FDF\033[0m"

re : fclean all
