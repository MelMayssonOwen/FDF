/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mowen <mowen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 13:28:31 by mowen             #+#    #+#             */
/*   Updated: 2017/08/01 19:52:03 by mowen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "fdf.h"

# include <stdio.h>

void		drawline(t_stor *s)
{
	double	dx;
	double	dy;
	double	x;
	double	y;
	double	tmp;

	x = (double)s->x0;
	y = (double)s->y0;
	dx = s->x1 - s->x0;
	dy = (s->y3) - s->y2;
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

void	clear_win(t_stor *s)
{
	int x;
	int y;

	y = 0;
	while (y++ <= 800)
	{
		x = 0;
		while (x++ <= 1000)
			mlx_pixel_put(s->mlx, s->win, x, y, 0x00000000);
	}
}

int	my_key_funct(int keycode, t_stor *s)
{
	if (keycode == 53)
		exit(1);
	printf("keycode : %d\n", keycode);
	keycode = 0;
	s->x = 0;
	return (0);
}

void		size_file(char **av, t_stor *s)
{
	int fd;
	char *line;

	fd = -1;
	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &line))
	{
		if (s->len == 0)
			s->nb_w = ft_count_words(line, 32);
		else if (s->nb_w != ft_count_words(line, 32))
			ft_putnerror("file not square");
		s->len++;
		free(line);
	}
	if (close(fd) != 0)
		ft_putnerror("file didn't close properly");
}


void	aff_tab(t_stor *s)
{
	for(int i = 0; i < s->len; i++)
	{
		for(int j = 0; j < s->nb_w; j++) 
			printf("%d ", s->tab[i][j]);
		printf("\n");
	}
}


void		create_tab(char **av, t_stor *s)
{
	char	*line;
	int		fd;
	int		x;
	int		y;
	int		i;

	fd = -1;
	fd = open(av[1], O_RDONLY);
	s->tab = (int**)malloc(sizeof(int*) * s->len);
	x = 0;
	while (get_next_line(fd, &line))
	{
		s->tab[x] = (int*)malloc(sizeof(int) * s->nb_w);
		y = 0;
		i = 0;
		while(y < s->nb_w)
		{
			i += ft_strspn(&line[i], " ");
			s->tab[x][y] = ft_atoi(&line[i]);
			y++;
			i += ft_strcspn(&line[i], " ");
		}
		x++;
		free(line);
	}
	if (close(fd) != 0)
		ft_putnerror("file didn't close properly");

}
