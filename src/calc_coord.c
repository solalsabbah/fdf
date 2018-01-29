/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_coord.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 17:41:04 by ssabbah           #+#    #+#             */
/*   Updated: 2018/01/29 18:36:47 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	hcoord(t_param *p, int x0, int y0)
{
	int x1;
	int	y1;

	x1 = (x0 + 1) * p->key;
	x0 = x0 * p->key;
	y0 = y0 * p->key;
	y1 = y0;
	x0 = x0 - (p->startz * p->height);
	y0 = y0 - (p->startz * p->height) / 2;
	x1 = x1 - (p->endz * p->height);
	y1 = y1 - (p->endz * p->height) / 2;
	p->x0 = x0;
	p->x1 = x1;
	p->y0 = y0;
	p->y1 = y1;
	return (0);
}

int	hfill(t_param *p, int x0, int y0)
{
	int isox;
	int isoy;
	int isox1;
	int isoy1;

	hcoord(p, x0, y0);
	p->x0 *= cos(p->alpha);
	p->y0 *= sin(p->alpha);
	p->x1 *= cos(p->alpha);
	p->y1 *= sin(p->alpha);
	isox = p->x0 - p->y0 + p->up;
	isoy = (p->x0 + p->y0) + p->width;
	isox1 = p->x1 - p->y1 + p->up;
	isoy1 = (p->x1 + p->y1) + p->width;
	p->isox = isox;
	p->isoy = isoy;
	drawline(isox1, isoy1, p);
	return (0);
}

int	vcoord(t_param *p, int x0, int y0)
{
	int x1;
	int y1;

	x1 = x0 * p->key;
	y1 = (y0 + 1) * p->key;
	x0 = x0 * p->key;
	y0 = y0 * p->key;
	x0 = x0 - 1 * (p->startz * p->height);
	y0 = y0 - (p->startz * p->height) / 2;
	x1 = x1 - 1 * (p->endz * p->height);
	y1 = y1 - (p->endz * p->height) / 2;
	p->x0 = x0;
	p->x1 = x1;
	p->y0 = y0;
	p->y1 = y1;
	return (0);
}

int	vfill(t_param *p, int x0, int y0)
{
	int isox;
	int isoy;
	int isox1;
	int isoy1;

	vcoord(p, x0, y0);
	p->x0 *= cos(p->alpha);
	p->y0 *= sin(p->alpha);
	p->x1 *= cos(p->alpha);
	p->y1 *= sin(p->alpha);
	isox = p->x0 - p->y0 + p->up;
	isoy = (p->x0 + p->y0) + p->width;
	isox1 = p->x1 - p->y1 + p->up;
	isoy1 = (p->x1 + p->y1) + p->width;
	p->isox = isox;
	p->isoy = isoy;
	drawline(isox1, isoy1, p);
	return (0);
}
