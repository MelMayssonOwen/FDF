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
	mlx_pixel_put(s->mlx, s->win, x, y, 0x00AAAAAA);
	x += dx;
	y += dy;
	tmp -= 1;
    }
}

void	magic_happens(t_stor *stor, t_server *s)
{
    int z;
    int y;

    z = 0;
    y = 0;
    while (z < (stor->len - 1))
    {
	if (stor->tab[z][y + 1] && stor->tab[z + 1] != '\0')
	{
	    stor->x0 = stor->tab[z][y];
	}
    }
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
    // if (stor->nb_w != stor->len)
    //	ft_putnerror("file not square");
    if (close(fd) != 0)
	ft_putnerror("file didn't close properly");
}

/*
   void		aff_tab(t_stor *stor)
   {
   int i;
   int j;

   i = 0;
   while (i < 11)
   {
   j = 0;
   while (j < 19)
   {
   printf("%d ", stor->tab[i][j]);
   j++;
   }
   printf("\n");
   i++;
   }
   }
   */

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
	printf("test\n");
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
		stor->tab[x][y] = ft_atoi(&line[i]);
		i += ft_strcspn(&line[i], " \n");
		i++;
		y++;
	    }
	    free(line);
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
	printf("%dx%d\n", stor->nb_w, stor->len);
	aff_tab(stor);
	//s->mlx = mlx_init();
	//s->win = mlx_new_window(s->mlx, 1000, 1000, "FDF");
	//mlx_key_hook(s->win, my_key_funct, s);
	//magic_happens(stor, s);
	//mlx_loop(s->mlx);
	return (0);
    }
