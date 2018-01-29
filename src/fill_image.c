/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 12:25:13 by ssabbah           #+#    #+#             */
/*   Updated: 2018/01/29 18:15:06 by ssabbah          ###   ########.fr       */
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

int		put_color(int isox, int isoy, t_param *p)
{
	col(p);
	if (p->startz == 0 && p->endz == 0)
		p->image[isox + isoy * WIDTH] = p->col1;
	else if (p->startz != 0 && p->endz != 0)
		p->image[isox + isoy * WIDTH] = p->col2;
	else
		p->image[isox + isoy * WIDTH] = p->col3;
	return (0);
}

void	draw_one(int isox, int isoy, int isox1, int isoy1, t_param *p)
{
	int sx;
	int sy;
	int err;
	int e2;

	sx = (isox1 - isox < 0) ? -1 : 1;
	sy = (isoy1 - isoy < 0) ? -1 : 1;
	err = p->dx + p->dy;
	while (isox != isox1)
	{
		if ((isox + isoy * WIDTH) <= WIDTH * HEIGHT &&
				isox < WIDTH && isoy < HEIGHT && (isox + isoy * WIDTH > 0))
			put_color(isox, isoy, p);
		if (isox == isox1 && isoy == isoy1)
			break ;
		e2 = 2 * err;
		err += (e2 >= p->dy) ? p->dy : 0;
		isox += (e2 >= p->dy) ? sx : 0;
		err += (e2 <= p->dx) ? p->dx : 0;
		isoy += (e2 <= p->dx) ? sy : 0;
	}
}

void	draw_two(int isox, int isoy, int isox1, int isoy1, t_param *p)
{
	int sx;
	int sy;
	int err;
	int e2;

	sx = (isox1 - isox < 0) ? -1 : 1;
	sy = (isoy1 - isoy < 0) ? -1 : 1;
	err = p->dx + p->dy;
	while (isoy != isoy1)
	{
		if ((isox + isoy * WIDTH) <= WIDTH * HEIGHT &&
				isox < WIDTH && isoy < HEIGHT && (isox + isoy * WIDTH > 0))
			put_color(isox, isoy, p);
		if (isox == isox1 && isoy == isoy1)
			break ;
		e2 = 2 * err;
		err += (e2 >= p->dy) ? p->dy : 0;
		isox += (e2 >= p->dy) ? sx : 0;
		err += (e2 <= p->dx) ? p->dx : 0;
		isoy += (e2 <= p->dx) ? sy : 0;
	}
}

int	drawline(int isox, int isoy, int isox1, int isoy1, t_param *p)
{
	p->dx = abs_val(isox1 - isox);
	p->dy = -abs_val(isoy1 - isoy);
	if (-p->dy > p->dx)
		draw_one(isox, isoy, isox1, isoy1, p);
	else
		draw_two(isox, isoy, isox1, isoy1, p);
	return (0);
}
