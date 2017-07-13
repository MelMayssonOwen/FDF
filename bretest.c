void	draw_that_bitch(int x0, int y0, int x1, int y1)
{
	double	dx;
	double	dy;
	double	x;
	double	y;
	double	temp;

	x = (double)x0;
	y = (double)y0;
	dx = x1 - x0;
	dy = y1 - y0;
	temp = sqrt((dx * dx) + (dy * dy));
	dx /= temp;
	dy /= temp;
	while (temp >= 0)
	{
		mlx_put_pixel_to_img(x, y, sw);
		x += dx;
		y += dy;
		temp -= 1;
	}
}

void	ft_put_pixel(t_swag *sw)
{
	int z;
	int y;

	z = 0;
	y = 0;
	while (z < (sw->stop - 1))
	{
		while (y < sw->cpt)
		{
			if (sw->ytab[z][y + 1] && sw->ytab[z][y + 1] != '\0')
				ft_line(sw, z, y);
			if (sw->ytab[z + 1][y] && sw->ytab[z + 1] != NULL)
				ft_column(sw, z, y);
			y++;
		}
		y = 0;
		z++;
	}
	y = -1;
	while (y++ < sw->cpt && sw->ytab[z][y + 1] != '\0')
		ft_line(sw, z, y);
}
