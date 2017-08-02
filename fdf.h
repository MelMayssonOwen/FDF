#ifndef FDF_H

# include "./libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include "./minilibx_macos/mlx.h"

# define FDF_H

# define GRID_SIZE	10
# define HEIGHT_COEF	2

# define WHITE		0x00FFFFFF
# define RED		0x00FF0000
# define GREEN		0x0000FF00
# define BLUE		0x000000FF
# define CYAN		0x0000AAAA

# define LEFT		123
# define RIGHT		124
# define UP		125
# define DOWN		126
# define LETTERC	8
# define ONE		18
# define TWO		19
# define PLUS		24
# define MINUS		27


typedef struct				s_stor // parse and tab creation
{
	int			tx;
	int			ty;
	int			nb_w;
	int			len;
	int			**tab;
	int			realstart_x;
	int			realstart_y;
	int			tmpstart_x;
	int			tmpstart_y;
	int			x0;
	int			y0;
	int			x1;
	int			y1;
	int			y2;
	int			y3;
	int			start_x;
	int			start_y;
	int			x_var;
	int			y_var;
	int			z;
	int			iter;
	int			keycode;
	int			color;
	int			background;
	int			front;
	int			win_x;
	int			win_y;
	int			x;
	int			y;
	void			*mlx;
	void			*win;
}					t_stor;//

int		my_key_funct(int keycode, t_stor *stor);
void		drawline(t_stor *s);
void		clear_win(t_stor *s);
void		size_file(char **av, t_stor *s);
void		aff_tab(t_stor *s);
void		create_tab(char **av, t_stor *s);
int	commands(int key, t_stor *s);
void	height(int a, t_stor *s);
void	size(int a, t_stor *s);
void	movement_LR(int a, t_stor *s);
void	movement_UD(int a, t_stor *s);
void	launch(t_stor *s);
void	draw(t_stor *s);
void	draw_helper(t_stor *s);
void	pan(int a, t_stor *s);
void	invert_colors(int a, t_stor *s);
#endif
