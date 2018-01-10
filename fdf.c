/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 12:06:26 by ssabbah           #+#    #+#             */
/*   Updated: 2018/01/10 18:22:43 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "./minilibx_macos/mlx.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "./libft/libft.h"

int	ft_mouse_hook(int button, int x, int y, t_param *p)
{
	button = 0;
	p->key = p->key;
	printf("mouse event (%d:%d)\n",x, y);
	return (0);
}

int		map_dimension(char *file, t_param *p)
{
	int i;
	int nb;

	i = 0;
	p->col = 0;
	nb = 0;
	while (file[i])
	{
		while (file[i] == ' ')
			i++;
		if (file[i] >= '0' && file[i] <= '9' && p->col == 0)
			nb++;
		while (file[i] >= '0' && file[i] <= '9')
			i++;
		if (file[i] == '\n')
			p->col += 1;
		i++;
	}
	p->row = nb;
	return (0);
}

char	**file2tab(char *str, t_param *p)
{
	int		fd;
	char	*line;
	char	*file;

	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (NULL);
	file = ft_strnew(2);
	while (get_next_line(fd, &line)) 
	{
		file = ft_strjoin(file, line);
		file = ft_strjoin(file, "\n");
	}
	map_dimension(file, p);
	return (ft_split(file));
}

int read_file(char *str, t_param p)
{
	int		x;
	int		a;
	int		b;
	int		h;
	//int	hval;
	int		nval;
	int		yval;
	char	**tab;
	//	char	*image_string;

	if (!(tab = file2tab(str, &p)))
		return (-1);
	//	p.image = mlx_new_image(p.mlx, 55 * x, 11 * y); // image 
	//	image_string = mlx_get_data_addr(p.image, );
	x = 0;
	a = 0;
	while (tab[x])
	{
		h = ft_atoi(tab[x]);
		if ((x + 1) % p.row != 0 || x == 0)
		{	
			if (tab[x + 1])
				nval = ft_atoi(tab[x + 1]); 
			if (h == 0 || h != (nval))
				hdraw(&p, a % p.row, b, h, nval, 0x269D8F);	
			else if (h == ft_atoi(tab[x + 1])) 
				hdraw(&p, a % p.row, b, h, nval, 0xFF0000);
		}
		if (x + p.row < p.row * p.col)
		{	
			yval = ft_atoi(tab[x + p.row]);
			if (h == 0 || h != ft_atoi(tab[x + p.row]))
				vdraw(&p, a % p.row, b, h, yval, 0x269D8F);
			else if (h == ft_atoi(tab[x + p.row])) 
				vdraw(&p, a % p.row, b, h, yval, 0xFF0000);
		}
		a++;
		x++;
		b = a / p.row;
	}
	printf("[%d]", x);
	return (0);
}

int	main(int ac, char **av)
{
	t_param	p;

	ac = 0;
	p.key = 10;
	p.height = 400;
	p.width = 200;
	p.mouse = 1;
	p.justify = 0;
	p.mlx = mlx_init();
	p.win = mlx_new_window(p.mlx, 1000, 1000, "fdf");
	p.file = av[1];
	if (read_file(av[1], p) == -1)
	{
		printf("A file is required\n");
		return (0);
	}
	mlx_key_hook(p.win, ft_key, &p);
	mlx_mouse_hook(p.win, ft_mouse_hook, &p);
	mlx_loop(p.mlx);
	return (0);
}
