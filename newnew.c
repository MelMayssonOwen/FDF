/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newnew.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mowen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 11:40:48 by mowen             #+#    #+#             */
/*   Updated: 2017/08/02 01:08:30 by mowen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

# include "stdio.h"

void	draw(t_stor *s)
{
	int tx;
	int ty;

	ty = 0;
	s->tmpstart_x = s->realstart_x;
	s->tmpstart_y = s->realstart_y;
	while (ty < s->len - 1)
	{
		s->x = s->tmpstart_x;
		s->y = s->tmpstart_y;
		tx = 0;
		while (tx < s->nb_w - 1)
		{
			s->x0 = s->x;
			s->y0 = s->y - (s->tab[ty][tx] * s->z);
			s->x1 = s->x + s->x_var;
			s->y1 = s->y - (s->y_var + (s->tab[ty][tx + 1] * s->z));
			drawline(s);
			s->x0 = s->x + s->x_var;
			s->y0 = s->y - (s->y_var + (s->tab[ty][tx + 1] * s->z));
			s->x1 = s->x + (s->x_var*2);
			s->y1 = s->y - (s->tab[ty + 1][tx + 1] * s->z);
			drawline(s);
			tx++;
			s->x += s->x_var;//move up right
			s->y -= s->y_var;
		}
		s->tmpstart_x += s->x_var;
		s->tmpstart_y += s->y_var;
		ty++;
	}
}

void	launch(t_stor *s)
{
	s->color = WHITE;
	s->realstart_x = 400;
	s->realstart_y = 400;
	s->x_var = 20;
	s->y_var = 10;
	s->z = 3;
	draw(s);
}

int	movement(int a, t_stor *s)
{
	a = 0;
	if (a == 1)
	{
	}
	else if (a == 2)
	{
		s->realstart_x += 10;
	}
	else if (a == 3)
		s->realstart_y += 10; 
	else if (a == 4)
		s->realstart_y -= 10;
	return (a);
}



int	commands(int keycode, t_stor *s)
{
	if (keycode == 53)
		exit(1);
	else if (keycode == LEFT)
	{s->color = 0x00000000;
		draw(s);
		s->realstart_x -= 10;
	s->color = WHITE;
		draw(s);}
	else if (keycode == RIGHT)
		movement(2, s);
	else if (keycode == UP)
		movement(3, s);
	else if (keycode == DOWN)
		movement(4, s);
	else if (keycode == PLUS)
		;
	else if (keycode == MINUS)
		;
	else if (keycode == LETTERC)
		;
	else if (keycode == ONE)
		;
	else if (keycode == TWO)
		;
	//printf("keycode = %d\n", keycode);
	draw(s);
	keycode = 0;
	s->x = 0;
	return (0);
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
	launch(s);
	mlx_key_hook(s->win, commands, s);
	mlx_loop(s->mlx);
	return (0);
}
