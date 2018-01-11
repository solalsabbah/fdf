/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 12:06:26 by ssabbah           #+#    #+#             */
/*   Updated: 2018/01/11 17:41:16 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "./minilibx_macos/mlx.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "./libft/libft.h"

int	init_p(t_param *p)
{
	p->key = 10;
	p->height = 500;
	p->width = 500;
	p->mouse = 1;
	p->justify = 0;
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
	//line = ft_strnew(2);
	while (get_next_line(fd, &line)) 
	{
		file = ft_strjoin(file, line);
		file = ft_strjoin(file, "\n");
	}
	map_dimension(file, p);
	return (ft_split(file));
}

int	solve(char **tab, t_param *p)
{
	int		x;
	int		a;
	int		b;
	int		h;
	int		nval;
	int		yval;
	int		bpp;
	int		size_l;
	int		endian;

	x = 0;
	a = 0;
	b = 0;
	p->image_ptr = mlx_new_image(p->mlx, 1000, 1000); // image 
	p->image = (int *)mlx_get_data_addr(p->image_ptr, &bpp, &size_l, &endian);
	while (tab[x])
	{
		h = ft_atoi(tab[x]);
		if ((x + 1) % p->row != 0 || (x == 0 && tab[x + 1]))
		{
			if (tab[x + 1])
				nval = ft_atoi(tab[x + 1]); 
			if (h == 0 || h != (nval))
				//	hdraw(&p, a % p->row, b, h, nval, 0x269D8F);	
				hfill(p, a % p->row, b, h, nval, 0x269D8F);	
			else if (h == ft_atoi(tab[x + 1])) 
				//	hdraw(&p, a % p->row, b, h, nval, 0x0008FF);
				hfill(p, a % p->row, b, h, nval, 0x0008FF);	
		}
		if (x + p->row < p->row * p->col)
		{	
			yval = ft_atoi(tab[x + p->row]);
			if (h == 0 || h != ft_atoi(tab[x + p->row]))
				//	vdraw(&p, a % p->row, b, h, yval, 0x269D8F);
				vfill(p, a % p->row, b, h, yval, 0x269D8F);
			else if (h == ft_atoi(tab[x + p->row])) 
				//	vdraw(&p, a % p->row, b, h, yval, 0x0008FF);
				vfill(p, a % p->row, b, h,  yval, 0x0008FF);
		}
		a++;
		x++;
		b = a / p->row;
	}
	mlx_put_image_to_window(p->mlx, p->win, p->image_ptr, 0, 0);
	return (0);
}

int	main(int ac, char **av)
{
	t_param	p;
	char 	**tab;

	init_p(&p);
	p.file = av[1];
	ac = 0;
	if ((tab = file2tab(av[1], &p)) == NULL)
	{
		printf("A file is required\n");
		return (0);
	}
	p.tab = tab;
	p.mlx = mlx_init();
	p.win = mlx_new_window(p.mlx, WIN_WIDTH, WIN_HEIGHT, "fdf");
	solve(tab, &p);
	mlx_key_hook(p.win, ft_key, &p);
	mlx_mouse_hook(p.win, ft_mouse_hook, &p);
	mlx_loop(p.mlx);
	return (0);
}
