/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mowen <mowen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 02:25:27 by mowen             #+#    #+#             */
/*   Updated: 2017/08/02 03:43:31 by mowen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		clear_win(t_stor *s)
{
	int	x;
	int	y;

	x = 0;
	while (x < s->win_x)
	{
		y = 0;
		while (y < s->win_y)
		{
			mlx_pixel_put(s->mlx, s->win, x, y, s->background);
			y++;
		}
		x++;
	}
}

void		pan(int a, t_stor *s)
{
	if (a == 33)
	{
		s->color = s->background;
		draw(s);
		s->x_var += 2;
		s->y_var -= 4;
		s->color = s->front;
		draw(s);
	}
	else if (a == 30)
	{
		s->color = s->background;
		draw(s);
		s->x_var -= 2;
		s->y_var += 4;
		s->color = s->front;
		draw(s);
	}
}

void		invert_colors(int a, t_stor *s)
{
	int	swap;

	if (a == 8)
	{
		swap = s->background;
		s->background = s->front;
		s->front = swap;
		clear_win(s);
		s->color = s->front;
		draw(s);
	}
	else if (a == 18)
	{
		clear_win(s);
		launch(s);
	}
	else
	{
		colors(a, s);
		s->color = s->front;
		draw(s);
	}

}

void		colors(int a, t_stor *s)
{
	if (a == 15)
	{
		s->color = s->background;
		draw(s);
		s->front = RED;
	}
	else if (a == 5)
	{
		s->color = s->background;
		draw(s);
		s->front = GREEN;
	}
	else if (a == 11)
	{
		s->color = s->background;
		draw(s);
		s->front = CYAN;
	}
	else if (a == 13)
	{
		s->color = s->background;
		draw(s);
		s->front = WHITE;
	}
}
