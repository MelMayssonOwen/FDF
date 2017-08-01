/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mowen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 11:40:48 by mowen             #+#    #+#             */
/*   Updated: 2017/08/01 22:22:23 by mowen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

# include "stdio.h"

void	params_first(t_stor *s)
{
	s->realstart_x = 400;
	s->realstart_y = 400;
	s->x_var = 20;
	s->y_var = 10;
	s->z = 3;
}

void	params_line(t_stor *s)
{
	s->tmpstart_x = s->realstart_x + s->x_var;
	s->tmpstart_y = s->realstart_y - s->y_var;
	s->x0 = s->tmpstart_x;
	s->y0 = s->tmpstart_y;
}


void	line(t_stor *s)
{
	s->ty = 0;
	while (s->ty < s->len)
	{
		s->tmpstart_x -= s->x_var;
		s->tmpstart_y += s->y_var;
		s->x0 = s->tmpstart_x;
		s->y0 = s->tmpstart_y;
		s->y2 = s->tmpstart_y;// + s->tab[s->ty][s->tx];
		s->tx = 0;
		while (s->tx < s->nb_w -1)
		{
			printf("s->tx %d\n", s->tx);
			s->x1 = s->x0 + s->x_var;
			s->y1 = s->y0 + s->y_var;
			s->y3 = s->y0 - (s->tab[s->ty][s->tx+1] * s->z) + s->y_var;
			drawline(s);
			s->x0 = s->x1;
			s->y0 = s->y1;
			s->y2 = s->y3;
			s->tx++;
		}
		s->ty++;
	}
}

void	params_column(t_stor *s)
{
	s->tmpstart_x = s->realstart_x - s->x_var;
	s->tmpstart_y = s->realstart_y - s->y_var;
	s->x0 = s->realstart_x;
	s->y0 = s->realstart_y;
}

void	column(t_stor *s)
{
	s->tx = 0;
	while (s->tx < s->nb_w)
	{
		s->tmpstart_x += s->x_var;
		s->tmpstart_y += s->y_var;
		s->x0 = s->tmpstart_x;
		s->y0 = s->tmpstart_y;
		s->y2 = s->tmpstart_y;// + s->tab[s->ty-1][s->tx];
		s->ty = 0;
		while (s->ty < s->len -1)
		{
			s->x1 = s->x0 - s->x_var;
			s->y1 = s->y0 + s->y_var;
			s->y3 = s->y0 + s->y_var;//- (s->tab[s->ty][s->tx] * s->z);
			drawline(s);
			s->x0 = s->x1;
			s->y0 = s->y1;
			s->y2 = s->y3;
			s->ty++;
		}
		s->tx++;
	}
}


int	main(int ac, char **av)
{
	t_stor *s;

	s = malloc(sizeof(t_stor));
	s->nb_w = 0;
	s->len = 0;
	if (ac != 2)
		ft_putnerror("wrong number of files");
	size_file(av, s);
	create_tab(av, s);
	s->mlx = mlx_init();
	s->win = mlx_new_window(s->mlx, 1000, 800, "FDF");
	params_first(s);
	params_line(s);
	line(s);
	params_column(s);
	column(s);
	mlx_key_hook(s->win, my_key_funct, s);
	mlx_loop(s->mlx);
	return (0);
}
