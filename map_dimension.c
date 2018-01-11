/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_dimension.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 16:38:22 by ssabbah           #+#    #+#             */
/*   Updated: 2018/01/11 17:40:49 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		map_dimension(char *file, t_param *p)
{
	int i;
	int nb;

	i = 0;
	p->col = 0;
	nb = 0;
	while (file[i])
	{
		while (file[i] == ' ')
			i++;
		if (file[i] >= '0' && file[i] <= '9' && p->col == 0)
			nb++;
		while (file[i] >= '0' && file[i] <= '9')
			i++;
		if (file[i] == '\n')
			p->col += 1;
		i++;
	}
	p->row = nb;
	return (0);
}
