/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mowen <mowen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 13:28:31 by mowen             #+#    #+#             */
/*   Updated: 2017/08/02 13:09:35 by mowen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		size_file(char **av, t_stor *s)
{
	int fd;
	char *line;

	fd = -1;
	if (!ft_strlen(av[1]))
		ft_putnerror("try with a real file !");
	if ((fd = open(av[1], O_RDONLY)) == -1)
		ft_putnerror("failed to open");
	while (get_next_line(fd, &line))
	{
		if (s->len == 0)
			s->nb_w = ft_count_words(line, 32);
		else if (s->nb_w != ft_count_words(line, 32))
			ft_putnerror("file not square");
		if (ft_strspn(line, "1234567890 ") != ft_strlen(line))
			ft_putnerror("file not conform");
		s->len++;
		free(line);
	}
	if (close(fd) != 0)
		ft_putnerror("file didn't close properly");
}

void		create_tab(char **av, t_stor *s)
{
	char		*line;
	int		fd;

	fd = -1;
	if ((fd = open(av[1], O_RDONLY)) == -1)
		ft_putnerror("failed to open");
	s->tab = (int**)malloc(sizeof(int*) * s->len);
	s->x = 0;
	while (get_next_line(fd, &line))
	{
		s->tab[s->x] = (int*)malloc(sizeof(int) * s->nb_w);
		s->y = 0;
		s->i = 0;
		while(s->y < s->nb_w)
		{
			s->i += ft_strspn(&line[s->i], " ");
			s->tab[s->x][s->y] = ft_atoi(&line[s->i]);
			s->y++;
			s->i += ft_strcspn(&line[s->i], " ");
		}
		s->x++;
		free(line);
	}
	if (close(fd) != 0)
		ft_putnerror("file didn't close properly");
}
