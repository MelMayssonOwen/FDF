/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mowen <mowen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 13:28:31 by mowen             #+#    #+#             */
/*   Updated: 2017/08/02 14:18:37 by mowen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		size_file(char **av, t_stor *s)
{
	s->fd = -1;
	s->len = 0;
	s->nb_w = 0;
	if (!ft_strlen(av[1]))
		ft_putnerror("try with a real file !");
	if ((s->fd = open(av[1], O_RDONLY)) == -1)
		ft_putnerror("failed to open");
	while (get_next_line(s->fd, &s->line))
	{
		if (s->len == 0)
			s->nb_w = ft_count_words(s->line, 32);
		else if (ft_count_words(s->line, 32) != s->nb_w)
			ft_putnerror("file not square");
		if (ft_strspn(s->line, "1234567890 +-") != ft_strlen(s->line))
			ft_putnerror("file not conform");
		s->len++;
		free(s->line);
	}
	if (!s->len)
		ft_putnerror("file not conform");
	if (close(s->fd) != 0)
		ft_putnerror("file didn't close properly");
}

void		create_tab(char **av, t_stor *s)
{
	s->fd = -1;
	if ((s->fd = open(av[1], O_RDONLY)) == -1)
		ft_putnerror("failed to open");
	if (!(s->tab = (int**)malloc(sizeof(int*) * s->len)))
		ft_putnerror("error");
	s->x = 0;
	while (get_next_line(s->fd, &s->line))
	{
		if (!(s->tab[s->x] = (int*)malloc(sizeof(int) * s->nb_w)))
			ft_putnerror("error");
		s->y = 0;
		s->i = 0;
		while(s->y < s->nb_w)
		{
			s->i += ft_strspn(&s->line[s->i], " ");
			s->tab[s->x][s->y] = ft_atoi(&s->line[s->i]);
			s->y++;
			s->i += ft_strcspn(&s->line[s->i], " ");
		}
		s->x++;
		free(s->line);
	}
	if (close(s->fd) != 0)
		ft_putnerror("file didn't close properly");
}
