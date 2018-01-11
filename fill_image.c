/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 12:25:13 by ssabbah           #+#    #+#             */
/*   Updated: 2018/01/11 17:40:38 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
int	hcoord(t_param *p, int x0, int y0, int h, int nval)
{
	int x1;
	int	y1;

	x1 = (x0 + 1) * p->key;
	x0 = x0 * p->key;
	y0 = y0 * p->key;
	y1 = y0;
	x0 = x0 - 1 * h;
	y0 = y0 - h / 2;
	x1 = x1 - 1 * nval;
	y1 = y1 - nval / 2;
	p->x0 = x0;
	p->x1 = x1;
	p->y0 = y0;
	p->y1 = y1;
	return (0);
}

int	hfill(t_param *p, int x0, int y0, int h, int nval, int col)
{
	int isoX;
	int isoY;
	int isoX1;
	int isoY1;
	int tmp;

	//r = -3 + p->justify;
	hcoord(p, x0, y0, h, nval);

	isoX = p->x0 -  p->y0 + p->height;
	isoY = (p->x0 + p->y0) / 2 + (p->width + WIN_WIDTH);
	isoX1 = p->x1 -  p->y1 + p->height;
	isoY1 = (p->x1 + p->y1) / 2 + (p->width + WIN_WIDTH);
	tmp =  isoX;
	if (tmp < isoX1)
	{
		while (tmp != isoX1)
		{
			if ((tmp * WIN_WIDTH) + (isoY + ((isoY1-isoY) * (tmp - isoX)) / (isoX1-isoX)) < WIN_WIDTH * WIN_HEIGHT)
				p->image[(tmp * WIN_WIDTH) + (isoY + ((isoY1-isoY) * (tmp - isoX)) / (isoX1-isoX))] = col;
			tmp++;
		}
	}
	else
	{
		while (tmp != isoX1)
		{
			if ((tmp * WIN_WIDTH) + (isoY + ((isoY1-isoY) * (tmp - isoX)) / (isoX1-isoX)) < WIN_WIDTH * WIN_HEIGHT)
				p->image[(tmp * WIN_WIDTH) + (isoY + ((isoY1-isoY) * (tmp - isoX)) / (isoX1-isoX))] = col;
			tmp--;
		}
	}

	return (0);
}

int	vcoord(t_param *p, int x0, int y0, int h, int nval)
{
	int x1;
	int y1;

	x1 = x0 * p->key;
	y1 = (y0 + 1) * p->key;
	x0 = x0 * p->key;
	y0 = y0 * p->key;
	x0 = x0 - 1 * h;
	y0 = y0 - h / 2;
	x1 = x1 - 1 * nval;
	y1 = y1 - nval / 2;
	p->x0 = x0;
	p->x1 = x1;
	p->y0 = y0;
	p->y1 = y1;
	return (0);
}

int	vfill(t_param *p, int x0, int y0, int h, int nval, int col)
{
	
	int isoX;
	int isoY;
	int isoX1;
	int isoY1;
	int tmp;
	
	int	r;

	r = -3;

	vcoord(p, x0, y0, h, nval);

	isoX = p->x0 - p->y0 + p->height;
	isoY = (p->x0 + p->y0) / 2 + p->width;
	isoX1 = p->x1 - p->y1 + p->height;
	isoY1 = (p->x1 + p->y1) / 2 + p->width;
	tmp = isoX;
	if (tmp < isoX1)
	{
		while (tmp != isoX1)
		{
			if (((tmp) + (isoY + ((isoY1-isoY) * (tmp - isoX)) / (isoX1-isoX))) < WIN_WIDTH * WIN_HEIGHT)
				p->image[((tmp) * WIN_WIDTH + (isoY + ((isoY1-isoY) * (tmp - isoX)) / (isoX1-isoX)))] = col;
			tmp++;
		}
	}
	else
	{
		while (tmp != isoX1)
		{
			if (((tmp) + (isoY + ((isoY1-isoY) * (tmp - isoX)) / (isoX1-isoX))) < WIN_WIDTH * WIN_HEIGHT)
				p->image[((tmp) * WIN_WIDTH + (isoY + ((isoY1-isoY) * (tmp - isoX)) / (isoX1-isoX)))] = col;
			tmp--;
		}
	}
	return (0);
}
