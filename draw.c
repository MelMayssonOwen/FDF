/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mowen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 11:40:48 by mowen             #+#    #+#             */
/*   Updated: 2017/07/08 13:06:51 by mowen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
   void		draw(t_stor *stor)
   {

   }
   */
static void		drawline(int x0, int y0, int x1, int y1, t_server *s)
{
	int dx, dy, p, x, y;

	dx = x1 - x0;
	dy = y1 - y0;

	x = x0;
	y = y0;

	p = 2 * dy - dx;

	while(x < x1)
	{
		if(p >= 0)
		{
			mlx_pixel_put(s->mlx, s->win, x, y, s->color);
			y = y + 1;
			p = p + 2 * dy - 2 * dx;
		}
		else
		{
			mlx_pixel_put(s->mlx, s->win, x, y, s->color);
			p = p + 2 * dy;
		}
		x = x + 1;
	}
}
int	my_key_funct(int keycode, t_server	*s)//return a value with keycode blablabla
{
	if (keycode == 53)
		exit(1);
	keycode = 0;
	return (0);
}


