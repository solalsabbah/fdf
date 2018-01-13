# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/08 11:30:47 by ssabbah           #+#    #+#              #
#    Updated: 2018/01/13 16:39:22 by ssabbah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = 	fdf.c\
		ft_events.c\
		map_dimension.c\
		fill_image.c\

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	make -C ft_printf
	mv libft/libft.a .
	mv ft_printf/libftprintf.a .
	gcc $(FLAGS) -I fdf.h -c $(SRC) 
	gcc $(FLAGS) -L. -lmlx -lft -lftprintf -framework OpenGL -framework Appkit $(OBJ) -o $(NAME)

clean:
	make -C libft clean
	make -C ft_printf clean
	rm -rf $(OBJ) libft.a libmlx.a

fclean: clean
	make -C libft fclean
	make -C ft_printf fclean
	rm -rf $(NAME)

re : fclean all
