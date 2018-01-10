/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 11:47:38 by ssabbah           #+#    #+#             */
/*   Updated: 2018/01/10 19:19:49 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
		read_file(p->file, *p);
	}
	if (keycode == 125 && p->key > 5) // down
	{
		p->key -= 1;
		mlx_clear_window(p->mlx, p->win);
		read_file(p->file, *p);
	}
	if (keycode == 0 && p->key > 5) // a
	{
		p->justify -= 2;
		mlx_clear_window(p->mlx, p->win);
		read_file(p->file, *p);
	}
	if (keycode == 2 && p->key > 5) // d
	{
		p->justify += 2;
		mlx_clear_window(p->mlx, p->win);
		read_file(p->file, *p);
	}
	if (keycode == 1) // w
	{
		p->width += 3;
		mlx_clear_window(p->mlx, p->win);
		read_file(p->file, *p);
	}
	if (keycode == 13) // s
	{
		p->width -= 3;
		mlx_clear_window(p->mlx, p->win);
		read_file(p->file, *p);
	}
	if (keycode == 51) // escape
		mlx_clear_window(p->mlx, p->win);
	if (keycode == 36)
		read_file(p->file, *p);
	return (keycode);
}
