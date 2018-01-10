/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 11:47:38 by ssabbah           #+#    #+#             */
/*   Updated: 2018/01/10 16:43:48 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_key(int keycode, t_param *p)
{
	int x;
	int y;

	x = 0;
	y = 0;
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
	if (keycode == 51) // escape
		mlx_clear_window(p->mlx, p->win);
	if (keycode == 36)
		read_file(p->file, *p);
	return (keycode);
}
