/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 16:38:57 by ssabbah           #+#    #+#             */
/*   Updated: 2018/01/11 16:09:12 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


int	hdraw(t_param *p, int x0, int y0, int h, int nval, int col)
{
	int x1;
	int y1;
	int isoX;
	int isoY;
	int isoX1;
	int isoY1;
	int tmp;
	int r;
	int s;

	r = 1;

	x1 = (x0 + 1) * p->key;

	x0 = x0 * p->key;
	y0 = y0 * p->key;
	y1 = y0;
	x0 = x0 - 1 * h;
	y0 = y0 - h / 2;

	x1 = x1 - 1 * nval;
	y1 = y1 - nval / 2;

	isoX = x0 - r * y0 + p->height;
	isoY = (x0 + y0) / 2 + p->width;
	isoX1 = x1 - r * y1 + p->height;
	isoY1 = (x1 + y1) / 2 + p->width;
	tmp = isoX;
	if (tmp < isoX1) 
	{
		while (tmp != isoX1)
		{
			mlx_pixel_put(p->mlx, p->win, tmp + p->justify,isoY+((isoY1-isoY)*(tmp - isoX))/(isoX1-isoX), col);
			tmp++;
		}
	}
	else 
	{
		while (tmp != isoX1)
		{
			mlx_pixel_put(p->mlx, p->win, tmp + p->justify,isoY+((isoY1-isoY)*(tmp - isoX))/(isoX1-isoX), col);
			tmp--;
		}
	}

	return (0);
}

int	vdraw(t_param *p, int x0, int y0, int h, int nval, int col)
{
	int x1;
	int y1;
	int tmp;
	int isoX;
	int isoY;
	int isoX1;
	int isoY1;
	int	r;
	
	r = 1;

	x1 = x0 * p->key;
	y1 = (y0 + 1) * p->key;
	x0 = x0 * p->key;
	y0 = y0 * p->key;

	x0 = x0 - 1 * h;
	y0 = y0 - h / 2;
	x1 = x1 - 1 * nval;
	y1 = y1 - nval / 2;

	isoX = x0 - r * y0 + p->height;
	isoY = (x0 + y0) / 2 + p->width;;
	isoX1 = x1 - r * y1 + p->height;
	isoY1 = (x1 + y1) / 2 + p->width;
	tmp = isoX;
	if (isoX != isoX1) 
	{
		while (tmp != isoX1)
		{
			mlx_pixel_put(p->mlx, p->win, tmp + p->justify,isoY+((isoY1-isoY)*(tmp - isoX))/(isoX1-isoX), col);
			tmp--;
		}
	}
	return (0);
}
