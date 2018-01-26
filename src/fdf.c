/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 12:06:26 by ssabbah           #+#    #+#             */
/*   Updated: 2018/01/26 17:36:48 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
#include "./minilibx_macos/mlx.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int		init_p(t_param *p)
{
	p->key = 10;
	p->up = 500;
	p->width = 500;
	p->mouse = 1;
	p->justify = 1;
	p->height = 1;
	p->alpha = 50;
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
	file = ft_strnew(1);
	while (get_next_line(fd, &line))
	{
		file = ft_strjoin(file, line);
		file = ft_strjoin(file, "\n");
		free(line);
	}
	map_dimension(file, p);
	return (ft_split(file));
}

int		solve(char **tab, t_param *p)
{
	int		x;
	int		b;
	int		h;
	int		nval;
	int		yval;

	x = 0;
	b = 0;
	while (tab[x])
	{
		h = ft_atoi(tab[x]);
		if ((x + 1) % p->row != 0 || (x == 0 && tab[x + 1]))
		{
			nval = ft_atoi(tab[x + 1]);
			hfill(p, x % p->row, b, h, nval);
		}
		if (x + p->row < p->row * p->col)
		{
			yval = ft_atoi(tab[x + p->row]);
			vfill(p, x % p->row, b, h, yval);
		}
		x++;
		b = x / p->row;
	}
	return (0);
}

int		create_image(char **tab, t_param *p)
{
	p->image_ptr = mlx_new_image(p->mlx, WIN_WIDTH, WIN_HEIGHT);
	p->image = (int *)mlx_get_data_addr(p->image_ptr,
			&p->bpp, &p->size_l, &p->endian);
	solve(tab, p);
	mlx_put_image_to_window(p->mlx, p->win, p->image_ptr, 0, 0);
	return (0);
}

int		main(int ac, char **av)
{
	t_param	p;

	init_p(&p);
	p.file = av[1];
	if (ac-- != 2)
	{
		ft_putstr("One and only one file is required\n");
		return (0);
	}
	if (ft_strncmp(".fdf", &av[1][ft_strlen(av[1]) - 4], 5) != 0 || (p.tab = file2tab(av[1], &p)) == NULL)
	{
		ft_putstr("The file is not valid\n");
		return (0);
	}
	p.mlx = mlx_init();
	p.win = mlx_new_window(p.mlx, WIN_WIDTH, WIN_HEIGHT, "fdf");
	create_image(p.tab, &p);
	mlx_hook(p.win, 2, 3, ft_key, &p);
	mlx_loop(p.mlx);
	return (0);
}