/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 16:38:57 by ssabbah           #+#    #+#             */
/*   Updated: 2018/01/10 17:24:24 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


int	hdraw(t_param *p, int x0, int y0, int h, int nval, int col)
{
	int a;
	int b;
	int isoX;
	int isoY;

	int x1;
	int y1;
	int a1;
	int b1;
	int isoX1;
	int isoY1;
	int tmp;

	x1 = (x0 + 1) * p->key + 400;

	x0 = x0 * p->key + 400;
	y0 = y0 * p->key + 200;
	a = x0 - 1 * h;
	b = y0 - h / 2;

	y1 = y0;
	a1 = x1 - 1 * nval;
	b1 = y1 - nval / 2;

	isoX = a - b;
	isoY = (a + b) / 2;
	isoX1 = a1 - b1;
	isoY1 = (a1 + b1) / 2;
	tmp = isoX;
	while (tmp != isoX1)
	{
		mlx_pixel_put(p->mlx, p->win, tmp,isoY+((isoY1-isoY)*(tmp - isoX))/(isoX1-isoX), col);
		tmp++;
	}
	return (0);
}

int	vdraw(t_param *p, int x0, int y0, int h, int nval, int col)
{
	int a;
	int b;
	int isoX;
	int isoY;

	int x1;
	int y1;
	int a1;
	int b1;
	int isoX1;
	int isoY1;
	int tmp;

	x1 = x0 * p->key + 400;
	y1 = (y0 + 1) * p->key + 200;
	x0 = x0 * p->key + 400;
	y0 = y0 * p->key + 200;
	
	a = x0 - 1 * h;
	b = y0 - h / 2;
	a1 = x1 - 1 * nval;
	b1 = y1 - nval / 2;

	isoX = a - b;
	isoY = (a + b) / 2;
	isoX1 = a1 - b1;
	isoY1 = (a1 + b1) / 2;
	tmp = isoX;
	if (isoX != isoX1) 
	{
		while (tmp != isoX1)
		{
			mlx_pixel_put(p->mlx, p->win, tmp,isoY+((isoY1-isoY)*(tmp - isoX))/(isoX1-isoX), col);
			tmp--;
		}
	}
	return (0);
}
