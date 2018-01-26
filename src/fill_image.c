/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 12:25:13 by ssabbah           #+#    #+#             */
/*   Updated: 2018/01/26 17:39:15 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	draw_one(int isoX, int isoY, int isoX1, int isoY1, t_param *p, int col)
{
	int sx;
	int sy;
	int err;
	int e2;

	sx = (isoX1 - isoX < 0) ? -1 : 1;
	sy = (isoY1 - isoY < 0) ? -1 : 1;
	err = p->dx + p->dy;
	while (isoX != isoX1)
	{
		if ((isoX + isoY * WIN_WIDTH) <= WIN_WIDTH * WIN_HEIGHT && isoX < WIN_WIDTH && isoY < WIN_HEIGHT)
			p->image[isoX + isoY * WIN_WIDTH] = col;
		if (isoX == isoX1 && isoY == isoY1)
			break ;
		e2 = 2 * err;
		err += (e2 >= p->dy) ? p->dy : 0;
		isoX += (e2 >= p->dy) ? sx : 0;
		err += (e2 <= p->dx) ? p->dx: 0;
		isoY += (e2 <= p->dx) ? sy : 0;
	}
}

void	draw_two(int isoX, int isoY, int isoX1, int isoY1, t_param *p, int col)
{
	int sx;
	int sy;
	int err;
	int e2;

	sx = (isoX1 - isoX < 0) ? -1 : 1;
	sy = (isoY1 - isoY < 0) ? -1 : 1;
	err = p->dx + p->dy;
	while (isoY != isoY1)
	{
		if ((isoX + isoY * WIN_WIDTH) <= WIN_WIDTH * WIN_HEIGHT && isoX < WIN_WIDTH && isoY < WIN_HEIGHT)
			p->image[isoX + isoY * WIN_WIDTH] = col;
		if (isoX == isoX1 && isoY == isoY1)
			break ;
		e2 = 2 * err;
		err +=(e2 >= p->dy) ? p->dy : 0;
		isoX += (e2 >= p->dy) ? sx : 0;
		err += (e2 <= p->dx) ? p->dx: 0;
		isoY += (e2 <= p->dx) ? sy : 0;
	}
}

int	drawline(int isoX, int isoY, int isoX1, int isoY1, t_param *p, int col)
{

	p->dx = abs_val(isoX1 - isoX);
	p->dy = -abs_val(isoY1 - isoY);
	if (-p->dy > p->dx) 
		draw_one(isoX, isoY, isoX1, isoY1, p, col);
	else
		draw_two(isoX, isoY, isoX1, isoY1, p, col);
	return (0);
}

int	hcoord(t_param *p, int x0, int y0, int h, int nval)
{
	int x1;
	int	y1;

	x1 = (x0 + 1) * p->key;
	x0 = x0 * p->key;
	y0 = y0 * p->key;
	y1 = y0;
	x0 = x0 - (h * p->height);
	y0 = y0 - (h * p->height) / 2;
	x1 = x1 - (nval * p->height);
	y1 = y1 - (nval * p->height) / 2;
	p->x0 = x0;
	p->x1 = x1;
	p->y0 = y0;
	p->y1 = y1;
	return (0);
}

int	hfill(t_param *p, int x0, int y0, int h, int nval)
{
	int isoX;
	int isoY;
	int isoX1;
	int isoY1;

	hcoord(p, x0, y0, h, nval);
	p->x0 *= cos(p->alpha);
	p->y0 *= sin(p->alpha);
	p->x1 *= cos(p->alpha);
	p->y1 *= sin(p->alpha);
	isoX = p->x0 - p->y0 + p->up;
	isoY = (p->x0 + p->y0) + p->width;
	isoX1 = p->x1 - p->y1 + p->up;
	isoY1 = (p->x1 + p->y1) + p->width;
	if (h != 0 && nval != 0)
		drawline(isoX, isoY, isoX1, isoY1, p, BROWN);
	else if (h != nval)
		drawline(isoX, isoY, isoX1, isoY1, p, GREEN);
	else	
		drawline(isoX, isoY, isoX1, isoY1, p, BLUE);
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
	x0 = x0 - 1 * (h * p->height);
	y0 = y0 - (h * p->height) / 2;
	x1 = x1 - 1 * (nval * p->height);
	y1 = y1 - (nval * p->height) / 2;
	p->x0 = x0;
	p->x1 = x1;
	p->y0 = y0;
	p->y1 = y1;
	return (0);
}

int	vfill(t_param *p, int x0, int y0, int h, int nval)
{

	int isoX;
	int isoY;
	int isoX1;
	int isoY1;

	vcoord(p, x0, y0, h, nval);	
	p->x0 *= cos(p->alpha);
	p->y0 *= sin(p->alpha);
	p->x1 *= cos(p->alpha);
	p->y1 *= sin(p->alpha);
	isoX = p->x0 - p->y0 + p->up;
	isoY = (p->x0 + p->y0) + p->width;
	isoX1 = p->x1 - p->y1 + p->up;
	isoY1 = (p->x1 + p->y1)  + p->width;
	if (h != 0 && nval != 0)
		drawline(isoX, isoY, isoX1, isoY1, p, BROWN);
	else if (h != nval)
		drawline(isoX, isoY, isoX1, isoY1, p, GREEN);
	else	
		drawline(isoX, isoY, isoX1, isoY1, p, BLUE);
	return (0);
}
