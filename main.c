/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 12:06:26 by ssabbah           #+#    #+#             */
/*   Updated: 2018/01/04 18:29:59 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"

typedef struct	s_param
{
	void *mlx;
	void *win;	
}				t_param;

int	draw(void *mlx, void *win, int x, int y)
{
	while (x < 800)
	{
		while (y < 400) 
		{
			mlx_pixel_put(mlx, win, x, y, 0xFF0000);
			mlx_pixel_put(mlx, win, x + 1, y, 0xFF0000);
			mlx_pixel_put(mlx, win, x + 2, y, 0x269D8F);
			mlx_pixel_put(mlx, win, x + 3, y, 0x269D8F);
			y++;
		}
		x = x + 50;
		y = 0;
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
	if (keycode == 126)
		x = x + 10;
//	draw(p->mlx, p->win, x, y);
	return (0);
}

int	ft_mouse_hook(int button, int x, int y, t_param *p)
{
	printf("mouse event (%d:%d)\n",x, y);
	return (0);
}

int	main(int ac, char **av)
{
	t_param	p;
	char	*line;
	int		x;
	int		y;
	int		fd;
	int		a;
	int		b;

	y = 0;
	a = 0;
	b = 0;
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (0);
	p.mlx = mlx_init();
	p.win = mlx_new_window(p.mlx, 800, 800, "fdf");
	while (get_next_line(fd, &line)) 
	{
		x = 0;
		while (line[x])
		{
			if (line[x] == '0' && line[x + 1] == ' ')
			{	
				while (a < 1000)
				{
					mlx_pixel_put(p.mlx, p.win, x + a, y, 0x269D8F);
					printf("%d\n", a);
					a++;
				}
			}
			if (line[x]  '0')
				mlx_pixel_put(p.mlx, p.win, x, y, 0xFF0000);
			x++;
		}
		y++;
	}
	mlx_key_hook(p.win, ft_key, &p);
	mlx_mouse_hook(p.win, ft_mouse_hook, &p);
	mlx_loop(p.mlx);
	return (0);
}
