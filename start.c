/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 12:06:26 by ssabbah           #+#    #+#             */
/*   Updated: 2018/01/04 17:21:42 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct	s_param
{
	void *mlx;
	void *win;	
}				t_param;

int	ft_key(int keycode, t_param *p)
{
	static int x;
	static int y;

	printf("key event %d\n", keycode);
	x = 1 + x;
	y = 1 + y;
	if (keycode == 125)
		mlx_pixel_put(p->mlx, p->win, 370, 210 + y, 0xFFFFFF);
	if (keycode == 126)
		mlx_pixel_put(p->mlx, p->win, 370, 210 - y, 0xFFFFFF);
	if (keycode == 124)
		mlx_pixel_put(p->mlx, p->win, 370 + x, 210, 0xFFFFFF);
	if (keycode == 123)
		mlx_pixel_put(p->mlx, p->win, 370 - x, 210, 0xFFFFFF);
	if (keycode == 53)
		exit(0);
	return (0);
}

int	ft_mouse_hook(int button, int x, int y, t_param *p)
{
	printf("mouse event (%d:%d)\n",x, y);
	return (0);
}

int	draw(void *mlx, void *win)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	printf("%p\n", mlx);
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

int	main()
{
	t_param p;

	p.mlx = mlx_init();
	p.win = mlx_new_window(p.mlx, 800, 400, "fdf");
	draw(p.mlx, p.win);
	mlx_key_hook(p.win, ft_key, &p);
	mlx_mouse_hook(p.win, ft_mouse_hook, &p);	
	mlx_loop(p.mlx);
	return (0);
}
