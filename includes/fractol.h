#ifndef FRACTOL_H
# define FRACTOL_H

# define WIN_SIZE 1200
# define DEFAULT_ITERATION_NBR 50

# include <ft_printf.h>
# include <libft.h>
# include <mlx.h>
# include <math.h>
typedef struct	s_data
{
	void					*mlx;
	void					*win;
	void					*img;
	char					*addr;
	int						bpp;
	int						size_line;
	int						endian;
	unsigned int	iteration_number;
	double				scale;
	double				min_x;
	double				max_x;
	double				min_y;
	double				max_y;
	void					(*fractal)();
}				t_data;

typedef struct	s_coord
{
	int		x;
	int		y;
}				t_coord;

int				handle_error_void(void *variable, void *error_value, char *msg);

void			put_pixel_to_image(t_data *data, int color, int x, int y);
void			clear_image(t_data *data);
void			fill_image(t_data *data, int color);
int				get_color_code(int r, int v, int b);

int				init_the_mlx(t_data *data);
void			free_mlx_and_exit(t_data *data);

int				key_hook(int kc, void *param);
int 			mouse_hook(int button, int x, int y, void *param);

void			mandelbrot(t_data *data);

double		module(double a, double b);

double		conv_rep_to_win(double x, double min, double max);


#endif
