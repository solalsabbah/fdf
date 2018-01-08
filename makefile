# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/08 11:30:47 by ssabbah           #+#    #+#              #
#    Updated: 2018/01/08 16:40:14 by ssabbah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = 	fdf.c\
		get_next_line.c\
		ft_key.c\
		draw.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	mv libft/libft.a .
	gcc -Wall -g -Werror -Wextra -I fdf.h -c $(SRC) 
	gcc -Wall -g -Werror -Wextra -L. -lmlx -lft -framework OpenGL -framework Appkit $(OBJ) -o $(NAME)

clean:
	make -C libft clean
	rm -rf $(OBJ) libft.a libmlx.a

fclean: clean
	make -C libft fclean
	rm -rf $(NAME)

re : fclean all
