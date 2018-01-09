/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 12:06:26 by ssabbah           #+#    #+#             */
/*   Updated: 2018/01/09 18:38:12 by ssabbah          ###   ########.fr       */
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

char	**file2tab(char *str)
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
	return (ft_split(file));
}

int read_file(char *str, t_param p)
{
	int		x;
	//int		y;
	int		a;
	int		b;
	int		h;
	//int	hval;
	int		nval;
	char	**tab;
	//	char	*image_string;

	if (!(tab = file2tab(str)))
		return (-1);
	//	p.image = mlx_new_image(p.mlx, 55 * x, 11 * y); // image 
	//	image_string = mlx_get_data_addr(p.image, );
	x = 0;
	a = 0;
	int i;
	int j;
	int e;
	int f;
	i = 0;
	j = 0;
	/*	while (tab[i])
		{
		j = 0;
		while (j <= 4)
		{
		e = j * 50;
		f = (i % 6) * 50;
		draw(&p, e, f, 0x269DFF);
		j++;
		}
		i++;
		}
		*/
	while (tab[x])
	{
		h = ft_atoi(tab[x]);
		if (tab[x + 1]) 
			nval = ft_atoi(tab[x + 1]);
		if (h == 0 || h != (nval))
			hdraw(&p, a % 19, b, h, nval, 0x269D8F);	
		else if (h == ft_atoi(tab[x + 1])) 
			hdraw(&p, a % 19, b, h, nval, 0xFF0000);
		if (h == 0 || h != ft_atoi(tab[x + 19]))
			vdraw(&p, a % 19, b, h, nval, 0x269D8F);
		else if (h == ft_atoi(tab[x + 19])) 
			vdraw(&p, a % 19, b, h, nval, 0xFF0000);
		a++;
		x++;
		b = a / 19;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_param	p;

	ac = 0;
	p.key = 10;
	p.mouse = 1;
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
