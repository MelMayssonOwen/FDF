#include "../libft/libft.h"
#include "fdf.h"

# include <stdio.h>

void		drawline(t_stor *stor, t_server *s)
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
		mlx_pixel_put(s->mlx, s->win, x, y, COLOR);
		x += dx;
		y += dy;
		tmp--;
	}
}
void	magic_happens(t_stor *stor, t_server *s)
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
	    	mlx_pixel_put(s->mlx, s->win, x, y-(stor->tab[ty][tx]/HEIGHT_COEF), COLOR);
	    	tx++;
	    	x+=GRID_SIZE;
	    }
	    ty++;
	    y+=GRID_SIZE;
	}
}

void	ruler(t_server *s)
{
    int x;
    int y;

    x = 0;
    y = 0;
    while (x < 1000)
    {
    	mlx_pixel_put(s->mlx, s->win, x, y, 0x00FF0000);
    	x+=10;
    }
}

void	placedots(t_stor *stor, t_server *s)
{
	int tx;
	int ty;
	int start_x;
	int start_y;
	int x;
	int y;

	int i;
	int j;

	i = 0;
	j = 0;

	start_x = 300;
	start_y = 300;

	x = 300;
	y = 300;
	ty = 0;
	while (ty < stor->len)
	{
	    printf("y loop %d\n", i++);
	    tx = 0;
	    while (tx < stor->nb_w)
	    {
	    	printf("x loop [%d] %d   x = %d, y = %d\n", i, j++, x, y);
	    	mlx_pixel_put(s->mlx, s->win, x, y-(stor->tab[ty][tx]*10), COLOR);
	    	x+=20;
	    	y-=10;
	    	tx++;
	    }
	    start_y += 14;
	    y = start_y;
	    start_x += 14;
	    x = start_x;
	    ty++;
	}
}

int	my_key_funct(int keycode, t_server	*s)//return a value with keycode blablabla
{
	if (keycode == 53)
		exit(1);
	else if (keycode == 24 || keycode == 69)
	{
		s->iter+=10;
	}
	else if (keycode == 27 || keycode == 78)
		s->iter-=10;
	printf("keycode : %d\n", keycode);
	s->x = 0;
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
	{
	    printf("%d ", stor->tab[i][j]);
	}
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
    t_server	s[1];

    stor = malloc(sizeof(t_stor));
    stor->nb_w = 0;
    stor->len = 0;
    if (ac != 2)
	ft_putnerror("wrong number of file");
    size_that_file(av, stor);
    tab_create(stor, av);
    aff_tab(stor);
    s->mlx = mlx_init();
    s->win = mlx_new_window(s->mlx, 1000, 800, "FDF");
    stor->x1 = 100;
    stor->y1 = 100;
    s->iter = 20;
    mlx_key_hook(s->win, my_key_funct, s);
    placedots(stor, s);
    ruler(s);
    //magic_happens(stor, s);
    mlx_loop(s->mlx);
    return (0);
}
