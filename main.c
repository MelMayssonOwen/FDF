/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mowen <mowen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 13:28:31 by mowen             #+#    #+#             */
/*   Updated: 2017/08/01 00:29:09 by mowen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "fdf.h"

# include <stdio.h>

void		drawline(t_stor *stor)
{
	double	dx;
	double	dy;
	double	x;
	double	y;
	double	tmp;

	x = (double)stor->x0;
	y = (double)stor->y0;
	dx = stor->x1 - stor->x0;
	dy = stor->y1 - stor->y0;
	tmp = sqrt((dx * dx) + (dy * dy));
	dx /= tmp;
	dy /= tmp;
	while (tmp >= 0)
	{
		mlx_pixel_put(stor->mlx, stor->win, x, y, COLOR);
		x += dx;
		y += dy;
		tmp--;
	}
}
void	magic_happens(t_stor *stor)
{
	int tx;
	int ty;
	int x;
	int y;


	y = 100;
	ty = 0;
	while (ty < stor->len)
	{
		tx = 0;
		x = 100;
		while (tx < stor->nb_w)
		{
			mlx_pixel_put(stor->mlx, stor->win, x, y-(stor->tab[ty][tx]/HEIGHT_COEF), COLOR);
			tx++;
			x+=GRID_SIZE;
		}
		ty++;
		y+=GRID_SIZE;
	}
}

void	ruler(t_stor *stor)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (x < 1000)
	{
		mlx_pixel_put(stor->mlx, stor->win, x, y, 0x00FF0000);
		x+=10;
	}
}

void	clear_win(t_stor *stor)
{
	int x;
	int y;

	y = 0;
	while (y++ <= 800)
	{
		x = 0;
		while (x++ <= 1000)
			mlx_pixel_put(stor->mlx, stor->win, x, y, 0x00000000);
	}
}

void	placedots(t_stor *stor)
{
	int tx;
	int ty;
	int i;
	int j;

	i = 0;
	j = 0;

	ty = 0;
	stor->x = stor->start_x;
	stor->y = stor->start_y;
	while (ty < stor->len)
	{
		printf("y loop %d\n", i++);
		tx = 0;
		while (tx < stor->nb_w)
		{
			printf("x loop [%d] %d   x = %d, y = %d\n", i, j++, stor->x, stor->y);
			mlx_pixel_put(stor->mlx, stor->win, stor->x, stor->y-(stor->tab[ty][tx]*stor->z), COLOR);
			stor->x+=stor->x_var;
			stor->y-=stor->y_var;
			tx++;
		}
		stor->start_y += stor->y_var;
		stor->y = stor->start_y;
		stor->start_x += stor->x_var;
		stor->x = stor->start_x;
		ty++;
	}
}

void	vertical(t_stor *stor)
{
	int ty;
	int tx;

	int i;

	i = 0;
	ty = 0;
	tx = 0;
	while (tx < stor->nb_w)
	{
		int j;
		j = 1;
		printf("y loop %d\n", i++);
		
		
		ty = 0;
		while (ty < stor->len)
		{
			printf("x loop [%d] %d x0 = %d, y0 = %d  x1 = %d, y1 = %d\n", i, j++, \
					stor->x0, stor->y0, stor->x1, stor->y1);
		
			drawline(stor);
			stor->x0 -= stor->x_var;
			stor->y0 += stor->y_var;
			stor->x1 -= stor->x_var;
			stor->y1 += stor->y_var;
			ty++;
		}
		stor->start_y += stor->y_var;
		stor->start_x += stor->x_var;
		stor->x0 = stor->start_x;
		stor->y0 = stor->start_y;
		stor->x1 = stor->start_x + stor->x_var;
		stor->y1 = stor->start_y + stor->y_var;
		tx++;

	}
}

void	horizontal(t_stor *stor)
{
	int ty;
	int tx;

	int i;

	i = 0;

	ty = 0;
	tx = 0;
	stor->x0 = stor->start_x;
	stor->y0 = stor->start_y;
		//	stor->y0 -= stor->y_var + (stor->tab[ty][tx]);
	stor->x1 = stor->start_x + stor->x_var;
		//	stor->y1 += stor->y_var + (stor->tab[ty][tx]);
	stor->y1 = stor->start_y + stor->y_var;
	while (ty < stor->len)
	{
		printf("y loop %d\n", i++);
		tx = 0;
			int j = 1;
			while (tx < stor->nb_w)
		{
			printf("x loop [%d] %d x0 = %d, y0 = %d  x1 = %d, y1 = %d\n", i, j++, \
					stor->x0, stor->y0, stor->x1, stor->y1);
			drawline(stor);
			stor->x0 += stor->x_var;
			stor->y0 -= stor->y_var;
			stor->x1 += stor->x_var;
			stor->y1 -= stor->y_var;
			tx++;
		}
		stor->start_y += stor->y_var;
		stor->start_x += stor->x_var;
		stor->x0 = stor->start_x;
		stor->y0 = stor->start_y;
		stor->x1 = stor->start_x + stor->x_var;
		stor->y1 = stor->start_y + stor->y_var;
		ty++;
	}
}

void	params(t_stor *stor)
{
	stor->start_x = 300;
	stor->start_y = 300;

	stor->z = 10;
}

int	my_key_funct(int keycode, t_stor *stor)//return a value with keycode blablabla
{
	if (keycode == 53)
		exit(1);
	else if (keycode == 24 || keycode == 69)
	{
		params(stor);
		clear_win(stor);
		stor->x_var += 1;
		stor->y_var -= 1;
		placedots(stor);
	}
	else if (keycode == 27 || keycode == 78)
		stor->iter-=10;

	else if (keycode == LEFT)
	{
		clear_win(stor);
		stor->start_x -= 10;
		placedots(stor);
	}
	else if (keycode == RIGHT)
	{
		clear_win(stor);
		stor->start_x += 10;
		placedots(stor);
	}
	else if (keycode == UP)
	{
		clear_win(stor);
		stor->start_y -= 10;
		placedots(stor);
	}
	else if (keycode == DOWN)
	{
		clear_win(stor);
		stor->start_y += 10;
		placedots(stor);
	}
	printf("keycode : %d\n", keycode);
	stor->x = 0;
	keycode = 0;
	return (0);
}

void		size_that_file(char **av, t_stor *stor) //give size and basic errors
{
	int fd;
	char *line;

	fd = -1;
	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &line))
	{
		if (stor->len == 0)
			stor->nb_w = ft_count_words(line, 32);
		else if (stor->nb_w != ft_count_words(line, 32))
			ft_putnerror("file not square");
		stor->len++;
		free(line);
	}
	if (close(fd) != 0)
		ft_putnerror("file didn't close properly");
}


void	aff_tab(t_stor *stor)
{
	for(int i = 0; i < stor->len; i++)
	{
		for(int j = 0; j < stor->nb_w; j++) 
			printf("%d ", stor->tab[i][j]);
		printf("\n");
	}
}


void		tab_create(t_stor *stor, char **av)
{
	char	*line;
	int		fd;
	int		x;
	int		y;
	int		i;

	fd = -1;
	fd = open(av[1], O_RDONLY);
	stor->tab = (int**)malloc(sizeof(int*) * stor->len);
	x = 0;
	while (get_next_line(fd, &line))
	{
		stor->tab[x] = (int*)malloc(sizeof(int) * stor->nb_w);
		y = 0;
		i = 0;
		while(y < stor->nb_w)
		{
			i += ft_strspn(&line[i], " ");
			stor->tab[x][y] = ft_atoi(&line[i]);
			y++;
			i += ft_strcspn(&line[i], " ");
		}
		x++;
		free(line);
	}
	if (close(fd) != 0)
		ft_putnerror("file didn't close properly");

}

int		main(int ac, char **av)
{
	t_stor	*stor;
	//   t_server	s[1];

	stor = malloc(sizeof(t_stor));
	stor->nb_w = 0;
	stor->len = 0;
	if (ac != 2)
		ft_putnerror("wrong number of file");
	size_that_file(av, stor);
	tab_create(stor, av);
	aff_tab(stor);
	stor->mlx = mlx_init();
	stor->win = mlx_new_window(stor->mlx, 1000, 800, "FDF");
	params(stor);// params to start
	stor->x_var = 20;
	stor->y_var = 10;
	//placedots(stor);//first lunch with start params
	horizontal(stor);
	params(stor);// params to start
	vertical(stor);
	mlx_key_hook(stor->win, my_key_funct, stor);// movements clear and placedots again
	ruler(stor);
	//magic_happens(stor);
	mlx_loop(stor->mlx);
	return (0);
}
