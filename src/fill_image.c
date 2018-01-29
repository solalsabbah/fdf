/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 12:25:13 by ssabbah           #+#    #+#             */
/*   Updated: 2018/01/29 17:31:40 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include <stdio.h>

int		col(t_param *p)
{
		if (p->col0 % 3 == 0)
		{
			p->col1 = WHITE;
			p->col2 = WHITE; 
			p->col3 = WHITE;
		}
		if (p->col0 % 3 == 1)
		{
			p->col1 = WHITE;
			p->col2 = BLUE;
			p->col3 = BROWN;
		}
		if (p->col0 % 3 == 2)
		{
			p->col1 = PINK;
			p->col2 = YELLOW;
			p->col3 = PURPLE;
		}
		return (0);
}

int		put_color(int isoX, int isoY, t_param *p)
{
		col(p);
		if (p->startz == 0 && p->endz == 0)
			p->image[isoX + isoY * WIN_WIDTH] = p->col1;
		else if (p->startz != 0 && p->endz != 0) 
			p->image[isoX + isoY * WIN_WIDTH] = p->col2;
		else
			p->image[isoX + isoY * WIN_WIDTH] = p->col3;
		return (0);
}

void	draw_one(int isoX, int isoY, int isoX1, int isoY1, t_param *p)
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
		if ((isoX + isoY * WIN_WIDTH) <= WIN_WIDTH * WIN_HEIGHT && isoX < WIN_WIDTH && isoY < WIN_HEIGHT && (isoX + isoY * WIN_WIDTH > 0))
			put_color(isoX, isoY, p);
		if (isoX == isoX1 && isoY == isoY1)
			break ;
		e2 = 2 * err;
		err += (e2 >= p->dy) ? p->dy : 0;
		isoX += (e2 >= p->dy) ? sx : 0;
		err += (e2 <= p->dx) ? p->dx: 0;
		isoY += (e2 <= p->dx) ? sy : 0;
	}
}

void	draw_two(int isoX, int isoY, int isoX1, int isoY1, t_param *p)
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
		if ((isoX + isoY * WIN_WIDTH) <= WIN_WIDTH * WIN_HEIGHT && isoX < WIN_WIDTH && isoY < WIN_HEIGHT && (isoX + isoY * WIN_WIDTH > 0))
			put_color(isoX, isoY, p);
		if (isoX == isoX1 && isoY == isoY1)
			break ;
		e2 = 2 * err;
		err +=(e2 >= p->dy) ? p->dy : 0;
		isoX += (e2 >= p->dy) ? sx : 0;
		err += (e2 <= p->dx) ? p->dx: 0;
		isoY += (e2 <= p->dx) ? sy : 0;
	}
}

int	drawline(int isoX, int isoY, int isoX1, int isoY1, t_param *p)
{

	p->dx = abs_val(isoX1 - isoX);
	p->dy = -abs_val(isoY1 - isoY);
	if (-p->dy > p->dx) 
		draw_one(isoX, isoY, isoX1, isoY1, p);
	else
		draw_two(isoX, isoY, isoX1, isoY1, p);
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
	p->startz = h;
	p->endz = nval;	
	p->x0 *= cos(p->alpha);
	p->y0 *= sin(p->alpha);
	p->x1 *= cos(p->alpha);
	p->y1 *= sin(p->alpha);
	isoX = p->x0 - p->y0 + p->up;
	isoY = (p->x0 + p->y0) + p->width;
	isoX1 = p->x1 - p->y1 + p->up;
	isoY1 = (p->x1 + p->y1) + p->width;
	drawline(isoX, isoY, isoX1, isoY1, p);
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
	p->startz = h;
	p->endz = nval;	
	p->x0 *= cos(p->alpha);
	p->y0 *= sin(p->alpha);
	p->x1 *= cos(p->alpha);
	p->y1 *= sin(p->alpha);
	isoX = p->x0 - p->y0 + p->up;
	isoY = (p->x0 + p->y0) + p->width;
	isoX1 = p->x1 - p->y1 + p->up;
	isoY1 = (p->x1 + p->y1)  + p->width;
	drawline(isoX, isoY, isoX1, isoY1, p);
	return (0);
}
