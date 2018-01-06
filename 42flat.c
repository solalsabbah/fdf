/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 12:06:26 by ssabbah           #+#    #+#             */
/*   Updated: 2018/01/06 19:34:41 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "./libft/libft.h"

typedef struct	s_param
{
	void	*mlx;
	void	*win;	
	void	*image;
	int		key;
	int		mouse;
	char	*file;

}				t_param;

int	ft_mouse_hook(int button, int x, int y, t_param *p)
{
	printf("mouse event (%d:%d)\n",x, y);
	return (0);
}

int	draw(t_param *p, int x, int y, int col)
{
	int a; 
	int b;

	x = x * p->key;
	y = y * p->key;
	b = 0;

	while (b % p->key != 0 || b == 0)
	{
		a = 0;
		while (a % p->key != 0 || a == 0)
		{
			mlx_pixel_put(p->mlx, p->win, x + a, y + b, col);
			a++;	
		}
		b++;
	}
	return (0);
}

int read_file(char *str, t_param p)
{
	int		x;
	int		y;
	int		fd;
	int		nb;
	char	*line;
	char	*image_string;
	
	y = 0;	
	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (-1);
//	p.image = mlx_new_image(p.mlx, 55 * x, 11 * y); // image 
//	image_string = mlx_get_data_addr(p.image, );
	while (get_next_line(fd, &line)) 
	{
		x = 0;
		while (line[x])
		{
			if (line[x] == ' ')
				x++;
			else
			{
				nb = ft_atoi(&line[x]);
				if (nb == 0)
					draw(&p, x, y, 0x269D8F);	
				else
					draw(&p, x + 1, y, 0xFF0000);
				while (line[x] >= '0' && line[x] <= '9')
					x++;
			}
		}
		y++;
	}
	return (0);
}

int	ft_key(int keycode, t_param *p)
{
	int x;
	int y;

	x = 0;
	y = 0;
	printf("key event %d\n", keycode);
	if (keycode == 53)
		exit(0);
	if (keycode == 126) // up
	{
		p->key += 1;
		mlx_clear_window(p->mlx, p->win);
		read_file(p->file, *p);
	}
	if (keycode == 125) // down
	{
		p->key -= 1;
		mlx_clear_window(p->mlx, p->win);
		read_file(p->file, *p);
	}
	if (keycode == 51) // escape
		mlx_clear_window(p->mlx, p->win);
	if (keycode == 36)
		read_file(p->file, *p);
	return (keycode);
}

int	main(int ac, char **av)
{
	t_param	p;
	
	p.key = 10;
	p.mouse = 1;
	p.mlx = mlx_init();
	p.win = mlx_new_window(p.mlx, 55 * 25, 11 * 25, "fdf");
	p.file = av[1];
	if (read_file(av[1], p) == -1)
		return (0);
	mlx_key_hook(p.win, ft_key, &p);
	mlx_mouse_hook(p.win, ft_mouse_hook, &p);
	mlx_loop(p.mlx);
	return (0);
}
