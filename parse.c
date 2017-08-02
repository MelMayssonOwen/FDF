/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mowen <mowen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 13:28:31 by mowen             #+#    #+#             */
/*   Updated: 2017/08/02 03:30:19 by mowen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
