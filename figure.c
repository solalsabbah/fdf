/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 17:54:16 by ssabbah           #+#    #+#             */
/*   Updated: 2018/01/09 17:55:33 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	draw(t_param *p, int x, int y, int col)
{
	int a;
	int b;
	int x1;
	int angle;
	int	R;
	int isoX;
	int isoY;

	x1 = x;
	x = x + 100;
	y = y + 100;
	a = x;
	b = y;
	angle = 0;
	p->win = p->win;
	col = col + 1;
	while (b < y + 45)
	{
		a = x;
		while (a++ < x + 45)
		{
			isoX = a - b + 200;
			isoY = (a + b) / 2 + 200;
			mlx_pixel_put(p->mlx, p->win, isoX, isoY, col); // Draw dot
		}
		b++;
	}
	///// DRAW A LINE ///////

	/*while (x != a)
	  {
	  mlx_pixel_put(p->mlx, p->win, x,y+((b-y)*(x - x1))/(a-x1), col);
	  x--;
	  }*/
	R = 19;

	///// DRAW A CIRCLE //////

	/*	while (R < 300)
		{
		angle = 0;
		while (angle < 360)
		{
		mlx_pixel_put(p->mlx, p->win, (x1 + (R * cos(angle))), (y + (R * sin(angle))), col);
		angle++;
		if (R == 50)
		R = 100;
		}
		R++;
		}*/

	////// DRAW A FULL CIRCLE /////

	/*	while (R < 300)
		{
		angle = 0;
		while (angle < 720)
		{
		mlx_pixel_put(p->mlx, p->win, (x1 + (R * cos(angle))), (y + ((R + 10)* sin(angle))), col);
		angle++;
		if (R == 50)
		R = 100;
		}
		R++;
		}*/

	return (0);
}
