/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mowen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 11:40:48 by mowen             #+#    #+#             */
/*   Updated: 2017/08/02 03:00:39 by mowen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

# include   <stdio.h>

void	movement_UD(int a, t_stor *s)
{
	if (a == UP)
	{
		s->color = s->background;
		draw(s);
		s->realstart_y += 20;
		s->color = s->front;
		draw(s);
	}
	else if (a == DOWN)
	{
		s->color = s->background;
		draw(s);
		s->realstart_y -= 20;
		s->color = s->front;
		draw(s);
	}
}

void	movement_LR(int a, t_stor *s)
{
	if (a == LEFT)
	{
		s->color = s->background;
		draw(s);
		s->realstart_x -= 20;
		s->color = s->front;
		draw(s);
	}
	else if (a == RIGHT)
	{
		s->color = s->background;
		draw(s);
		s->realstart_x += 20;
		s->color = s->front;
		draw(s);
	}
	else
		movement_UD(a, s);
}

void	size(int a, t_stor *s)
{
	if (a == PLUS)
	{
		s->color = s->background;
		draw(s);
		s->x_var += 4;
		s->y_var += 2;
		s->color = s->front;
		draw(s);
	}
	else if (a == MINUS)
	{
		s->color = s->background;
		draw(s);
		s->x_var -= 4;
		s->y_var -= 2;
		s->color = s->front;
		draw(s);
	}
}

void	height(int a, t_stor *s)
{
	if (a == 43)
	{
		s->color = s->background;
		draw(s);
		s->z--;
		s->color = s->front;
		draw(s);
	}
	else if (a == 47)
	{
		s->color = s->background;
		draw(s);
		s->z++;
		s->color = s->front;
		draw(s);
	}
}

int	commands(int key, t_stor *s)
{
	if (key == 53)
		exit(1);
	else if (key == LEFT || key == RIGHT || key == UP || key == DOWN)
		movement_LR(key, s);
	else if (key == PLUS || key == MINUS)
		size(key, s);
	else if (key == 43 || key == 47)
		height(key, s);
	else if (key == 30 || key == 33)
		pan(key, s);
	else if (key == 8)
		invert_colors(key, s);
	printf ("key = %d\n", key);
	key = 0;
	s->x = 0;
	return (0);
}
