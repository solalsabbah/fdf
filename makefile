# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/08 11:30:47 by ssabbah           #+#    #+#              #
#    Updated: 2018/01/24 19:11:58 by ssabbah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = 	fdf.c\
		ft_events.c\
		map_dimension.c\
		fill_image.c\

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	mv libft/libft.a .
	gcc $(FLAGS) -I fdf.h -c $(SRC) 
	gcc $(FLAGS) -L. -lmlx -lft -framework OpenGL -framework Appkit $(OBJ) -o $(NAME)

clean:
	make -C libft clean
	rm -rf $(OBJ) libft.a libmlx.a

fclean: clean
	make -C libft fclean
	rm -rf $(NAME)

re : fclean all
