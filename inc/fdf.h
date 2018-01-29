/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 12:08:46 by ssabbah           #+#    #+#             */
/*   Updated: 2018/01/29 18:24:39 by ssabbah          ###   ########.fr       */
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

# define WIDTH 1500
# define HEIGHT 1000

# define BLUE 0x72CAFF
# define GREEN 0x47D600
# define BROWN 0x752E00
# define WHITE 0xFFFFFF
# define PINK 0xFF65EF
# define YELLOW 0xFEF94D
# define PURPLE 0x3E0C76

# define PAGEUP 126
# define PAGEDOWN 125
# define C 8
# define W 13
# define S 1
# define PLUS 69
# define MINUS 78
# define ROT1 91
# define ROT2 87
# define ESC 53
# define DEL 51

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
	int			col0;
	int			col1;
	int			col2;
	int 		col3;
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
	int			isox;
	int			isoy;
	int			startx;
	int			starty;
	int			startz;
	int			endz;

}				t_param;

int				solve(char **tab, t_param *p);
int				create_image(char **tab, t_param *p);
int				map_dimension(char *file, t_param *p);
int				ft_key(int keycode, t_param *p);
int				ft_mouse_hook(int button, int x, int y, t_param *p);
int				vcoord(t_param *p, int x0, int y0);
int				hcoord(t_param *p, int x0, int y0);
int				vfill(t_param *p, int x, int y);
int				hfill(t_param *p, int x, int y);
int				drawline(int isox1, int isoy1, t_param *p);
#endif
