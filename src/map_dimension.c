/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_dimension.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 16:38:22 by ssabbah           #+#    #+#             */
/*   Updated: 2018/02/01 15:04:30 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int		map_dimension(char *file, t_param *p)
{
	int i;
	int nb;

	i = -1;
	p->col = 0;
	nb = 0;
	while (file[++i])
	{
		p->row = 0;
		while (file[i] != '\n')
		{
			while (file[i] == ' ')
				i++;
			if ((file[i] >= '0' && file[i] <= '9') || file[i] == '-')
				p->row++;
			while ((file[i] >= '0' && file[i] <= '9') || file[i] == '-')
				i++;
		}
		if (nb != p->row && p->col != 0)
			return (-1);
		nb = p->row;
		p->col++;
	}
	p->row = nb;
	return (0);
}
