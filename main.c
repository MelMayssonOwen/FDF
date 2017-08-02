/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mowen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 11:40:48 by mowen             #+#    #+#             */
/*   Updated: 2017/08/02 12:51:05 by mowen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		drawline(t_stor *s)
{
	double		dx;
	double		dy;
	double		x;
	double		y;
	double		tmp;

	x = (double)s->x0;
	y = (double)s->y0;
	dx = s->x1 - s->x0;
	dy = (s->y1) - s->y0;
	tmp = sqrt((dx * dx) + (dy * dy));
	dx /= tmp;
	dy /= tmp;
	while (tmp >= 0)
	{
		mlx_pixel_put(s->mlx, s->win, x, y, s->color);
		x += dx;
		y += dy;
		tmp--;
	}
}

void		draw_helper(t_stor *s)
{
	s->x0 = s->x;
	s->y0 = s->y - (s->tab[s->ty][s->tx] * s->z);
	s->x1 = s->x + s->x_var;
	s->y1 = s->y - (s->y_var + (s->tab[s->ty][s->tx + 1] * s->z));
	drawline(s);							
	s->x0 = s->x + s->x_var;
	s->y0 = s->y - (s->y_var + (s->tab[s->ty][s->tx + 1] * s->z));
	s->x1 = s->x + (s->x_var * 2);
	s->y1 = s->y - (s->tab[s->ty + 1][s->tx + 1] * s->z);
	drawline(s);
	s->tx++;
	s->x += s->x_var;
	s->y -= s->y_var;
}

void		draw(t_stor *s)
{
	s->ty = 0;
	s->tmpstart_x = s->realstart_x;
	s->tmpstart_y = s->realstart_y;
	while (s->ty < s->len - 1)
	{
		s->x = s->tmpstart_x;
		s->y = s->tmpstart_y;
		s->tx = 0;
		while (s->tx < s->nb_w - 1)
			draw_helper(s);
		s->tmpstart_x += s->x_var;
		s->tmpstart_y += s->y_var;
		s->ty++;
	}
}

void		launch(t_stor *s)
{
	s->color = WHITE;
	s->front = WHITE;
	s->background = 0x00000000;
	s->realstart_x = 400;
	s->realstart_y = 400;
	s->x_var = 20;
	s->y_var = 10;
	s->z = 3;
	draw(s);
}

int		main(int ac, char **av)
{
	t_stor *s;

	s = malloc(sizeof(t_stor));
	s->nb_w = 0;
	s->len = 0;
	if (ac != 2)
		ft_putnerror("wrong number of files");
	if (av[1][0] == '/' || av[1] == NULL)
		ft_putnerror("You don't crash me bitch");
	size_file(av, s);
	create_tab(av, s);
	s->mlx = mlx_init();
	s->win_x = 800;
	s->win_y = 600;
	if (s->nb_w > 100 || s->len > 80)
	{
		s->win_x = 1600;
		s->win_y = 800;
	}
	s->win = mlx_new_window(s->mlx, s->win_x, s->win_y, "FDF");
	launch(s);
	mlx_key_hook(s->win, commands, s);
	mlx_loop(s->mlx);
	return (0);
}
