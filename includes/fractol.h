/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 11:08:07 by jcamhi            #+#    #+#             */
/*   Updated: 2017/05/24 11:10:12 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIN_SIZE 840
# define DEFAULT_ITERATION_NBR 50

# include <ft_printf.h>
# include <libft.h>
# include <mlx.h>
# include <math.h>
# include <pthread.h>

typedef struct	s_data
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*addr;
	char			color_type;
	char			mouse_mode;
	int				bpp;
	int				size_line;
	int				endian;
	int				is_paused;
	int				color;
	int				color_r;
	int				color_g;
	int				color_b;
	unsigned int	iteration_number;
	double			scale;
	double			min_x;
	double			max_x;
	double			min_y;
	double			max_y;
	double			cx;
	double			cy;
	double			mx;
	double			my;
	int				(*fractal)();
}				t_data;

typedef int		(*t_fract)(double, double, int, t_data *);

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
int				mouse_hook(int button, int x, int y, void *param);
int				mouse_moove_hook(int x, int y, t_data	*data);

int				mandelbrot(double a, double b, int max_iteration, t_data *data);
int				julia(double a, double b, int max_iteration, t_data *data);
int				bship(double a, double b, int max_iteration, t_data *data);

double			module(double a, double b);

double			conv_rep_to_win(double x, double min, double max);
double			conv_win_to_rep(double x, double min, double max);

void			zoom(t_data *data, double ratio_zoom, int x, int y);

void			change_it_and_print(t_data *data, int it);
void			move_func(t_data *data, int kc);
void			color_key(t_data *data, int kc);
void			change_fractal_and_print(t_data	*data);
void			cycle_mouse_mode(t_data *data);

void			fractal(t_data *data);

t_fract			handle_av(int ac, char **av);

int				color(t_data *data, int it, int max_it);
void			init_color(t_data *data);
void			cycle_type(t_data	*data);

void			cycle_color_d(t_data *data);
void			cycle_color_b(t_data *data);

void			handle_mouse_w(t_data *data, int x, int y);
void			handle_mouse_n(t_data *data, int x, int y);

#endif
