#ifndef FDF_H

# include "./libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include "./minilibx_macos/mlx.h"

# define FDF_H

# define GRID_SIZE	10
# define HEIGHT_COEF	2

# define COLOR		0x00FFFFFF
# define RED		0x00FF0000
# define GREEN		0x0000FF00
# define BLUE		0x000000FF
# define CYAN		0x0000AAAA

# define LEFT		123
# define RIGHT		124
# define UP		125
# define DOWN		126

typedef struct			s_stor // parse and tab creation
{
	int			nb_w;
	int			len;
	int			**tab;
	int			x0;
	int			y0;
	int			x1;
	int			y1;
}						t_stor;

typedef struct			s_server // necessary mlx
{
	int			iter;
	void		*mlx;
	void		*win;
	int			keycode;
	int			color;
	int			x;
	int			y;
}						t_server;


#endif
