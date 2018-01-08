/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 16:38:57 by ssabbah           #+#    #+#             */
/*   Updated: 2018/01/08 16:39:48 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	hdraw(t_param *p, int x, int y, int col)
{
	int a;

	x = x * p->key + 200;
	y = y * p->key + 300;
	a = 0;
	while (a % p->key != 0 || a == 0)
	{
		mlx_pixel_put(p->mlx, p->win, x + a, y, col);
		a++;
	}
	return (0);
}

int	vdraw(t_param *p, int x, int y, int col)
{
	int b;

	x = x * p->key + 200;
	y = y * p->key + 300;
	b = 0;
	while (b % p->key != 0 || b == 0)
	{
		mlx_pixel_put(p->mlx, p->win, x, y + b, col);
		b++;
	}
	return (0);
}
