/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 16:38:57 by ssabbah           #+#    #+#             */
/*   Updated: 2018/01/09 18:51:16 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	hdraw(t_param *p, int x, int y, int h, int nval, int col)
{
	int a;
	int b;
	int isoX;
	int isoY;

	x = x * p->key + 600;
	y = y * p->key + 200;
	a = x - 1 * h;
	b = y - h / 2;
	printf("{%d}\n", a);
	printf("[%d]\n", x + p->key);
	while (a < x + p->key)
	{
	//	printf("%d\n", a);
		isoX = a - b;
		isoY = (a + b) / 2;
		mlx_pixel_put(p->mlx, p->win, isoX, isoY, col);
		a++;
	}
	return (0);
}

int	vdraw(t_param *p, int x, int y, int h, int nval, int col)
{
	int a;
	int b;
	int isoX;
	int isoY;

	x = x * p->key + 600;
	y = y * p->key + 200;
	a = x - 1 * h;
	b = y - h / 2;
	while (b < y + p->key)
	{
		isoX = a - b;
		isoY = (a + b) / 2;
		mlx_pixel_put(p->mlx, p->win, isoX, isoY, col);
		b++;
	}
	return (0);
}
