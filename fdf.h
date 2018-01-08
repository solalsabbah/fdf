/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 12:08:46 by ssabbah           #+#    #+#             */
/*   Updated: 2018/01/08 16:40:41 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

typedef struct	s_param
{
	void	*mlx;
	void	*win;
	void	*image;
	int		key;
	int		mouse;
	int		rot;
	char	*file;

}				t_param;

int		read_file(char *str, t_param p);
int		ft_key(int keycode, t_param *p);
int		vdraw(t_param *p, int x, int y, int col);
int		hdraw(t_param *p, int x, int y, int col);

#endif
