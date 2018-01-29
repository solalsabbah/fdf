/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 12:08:46 by ssabbah           #+#    #+#             */
/*   Updated: 2018/01/29 12:17:22 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "../libft/libft.h"
# include "../minilibx/mlx.h"

# define WIN_WIDTH 1500
# define WIN_HEIGHT 1000

# define BLUE 0x72CAFF
# define GREEN 0x47D600
# define BROWN 0x752E00

typedef struct	s_param
{
	void		*mlx;
	void		*win;
	void		*image_ptr;
	char		**tab;
	char		*file;
	int			*image;
	int			bpp;
	int			size_l;
	int			endian;
	int			key;
	int			mouse;
	int			rot;
	float		alpha;
	int			row;
	int			col;
	int			width;
	int			up;
	int			height;
	int			justify;
	int			x0;
	int			y0;
	int			x1;
	int			y1;
	int			dx;
	int			dy;
}				t_param;

int				solve(char **tab, t_param *p);
int				create_image(char **tab, t_param *p);
int				map_dimension(char *file, t_param *p);
int				ft_key(int keycode, t_param *p);
int				ft_mouse_hook(int button, int x, int y, t_param *p);
int				vfill(t_param *p, int x, int y, int h, int nval);
int				hfill(t_param *p, int x, int y, int h, int nval);
int				vdraw(t_param *p, int x, int y, int h, int nval, int col);
int				hdraw(t_param *p, int x, int y, int h, int nval, int col);

#endif
