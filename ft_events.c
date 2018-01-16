/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 16:39:37 by ssabbah           #+#    #+#             */
/*   Updated: 2018/01/16 18:19:57 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int	ft_key(int keycode, t_param *p)
{
	printf("%d\n", keycode);
	if (keycode == 91) // 8
		p->alpha += 10;
	if (keycode == 87) // 5
		p->alpha -= 10; 
	if (keycode == 53)
		exit(0);
	if (keycode == 126)
		p->key += 1;
	if (keycode == 125 && p->key > 5)
		p->key -= 1;
	if (keycode == 0 && p->key > 5)
		p->justify -= 2;
	if (keycode == 2 && p->key > 5)
		p->justify += 2;
	if (keycode == 1)
		p->width += 3;
	if (keycode == 13)
		p->width -= 3;
	if (keycode == 69)
		p->height += 1;
	if (keycode == 78)
		p->height -= 1;
	if (keycode == 51)
		mlx_clear_window(p->mlx, p->win);
	mlx_clear_window(p->mlx, p->win);
	create_image(p->tab, p);
	return (keycode);
}
