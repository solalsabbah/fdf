/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 16:39:37 by ssabbah           #+#    #+#             */
/*   Updated: 2018/01/11 17:39:46 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_mouse_hook(int button, int x, int y, t_param *p)
{
	button = 0;
	p->key = p->key;
	printf("mouse event (%d:%d)\n",x, y);
	return (0);
}

int	ft_key(int keycode, t_param *p)
{

	printf("key event %d\n", keycode);
	printf("p key %d\n", p->key);
	if (keycode == 53)
		exit(0);
	if (keycode == 126) // up
	{
		p->key += 1;
		mlx_clear_window(p->mlx, p->win);
		solve(p->tab, p);
	}
	if (keycode == 125 && p->key > 5) // down
	{
		p->key -= 1;
		mlx_clear_window(p->mlx, p->win);
		solve(p->tab, p);
	}
	if (keycode == 0 && p->key > 5) // a
	{
		p->justify -= 2;
		mlx_clear_window(p->mlx, p->win);
		solve(p->tab, p);
	}
	if (keycode == 2 && p->key > 5) // d
	{
		p->justify += 2;
		mlx_clear_window(p->mlx, p->win);
		solve(p->tab, p);
	}
	if (keycode == 1) // w
	{
		p->width += 3;
		mlx_clear_window(p->mlx, p->win);
		solve(p->tab, p);
	}
	if (keycode == 13) // s
	{
		p->width -= 3;
		mlx_clear_window(p->mlx, p->win);
		solve(p->tab, p);
	}
	if (keycode == 51) // escape
		mlx_clear_window(p->mlx, p->win);
	if (keycode == 36)
		solve(p->tab, p);
	return (keycode);
}
