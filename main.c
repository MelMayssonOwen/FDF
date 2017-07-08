#include "../projects/libft/libft.h"
#include "fdf.h"
# include <stdio.h>

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
    if (stor->nb_w != stor->len)
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

int		main(int ac, char **av)
{
    t_stor	*stor;

    stor = malloc(sizeof(t_stor));
    stor->nb_w = 0;
    stor->len = 0;
    if (ac != 2)
	ft_putnerror("wrong number of file");
    size_that_file(av, stor);
    tab_create(stor, av);
    print_fdf(stor);
    return (0);
}
