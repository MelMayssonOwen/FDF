#include "../libft/libft.h"
#include "fdf.h"

# include <stdio.h>

static void		drawline(int x0, int y0, int x1, int y1, t_server *s)
{
	double dx;
	double dy;
	double tmp;

	dx = x1 - x0;
	dy = y1 - y0;
	tmp = sqrt((dx * dx) + (dy * dy));
	dx /= tmp;
	dy /= tmp;
	while (tmp >= 0)
	{
		mlx_pixel_put(s->mlx, s->win, x0, y1, env->color);
		env->x += dx;
		env->y += dy;
		tmp--;
	}
	return (0);

}

int	my_key_funct(int keycode, t_server	*s)//return a value with keycode blablabla
{
	if (keycode == 53)
		exit(1);
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
	}
	f (stor->nb_w != stor->len)
		ft_putnerror("file not square");
	if (close(fd) != 0)
		ft_putnerror("file didn't close properly");
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
	x = -1;
	while (get_next_line(fd, &line))
	{
		stor->tab[++x] = (int*)malloc(sizeof(int) * stor->nb_w);
		y = 0;
		i = 0;
		while(y < stor->nb_w)
		{
			i++;
			i += ft_strcspn(&line[i], " \n");
			stor->tab[x][y] = ft_atoi(&line[i]);
			y++;
		}
	}
}

void	draw_wire_frame(t_server *s, t_stor *stor)
{
	int 	x;
	int 	y;
	int pointx;
	int pointy;


	pointy = 500;
	y = 0;
	while (y <= stor->len)
	{
	pointx = 500;
		x = 0;
		while (x <= stor->nb_w)
		{
			drawline(pointx, pointy, pointx+10 ,pointy-10, s);
			pointx+=10;
		pointy-=10;
			x++;
		}
		y++;
		pointy+=10;
	}
}

int		main(int ac, char **av)
{
	t_stor	*stor;
	t_server	s[1];

	stor = malloc(sizeof(t_stor));
	stor->nb_w = 0;
	stor->len = 0;
	if (ac != 2)
		ft_putnerror("wrong number of file");
	size_that_file(av, stor);
	tab_create(stor, av);
	s->mlx = mlx_init();
	s->win = mlx_new_window(s->mlx, 1000, 1000, "hey bitch");
	mlx_key_hook(s->win, my_key_funct, s);
//	draw_wire_frame(s, stor);
	drawline(600, 600, 100, 100, s);
	mlx_loop(s->mlx);
	//print_fdf(stor);
	return (0);
}
