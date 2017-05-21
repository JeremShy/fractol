#include <fractol.h>

static int	mb_is_on(double a, double b, int max_iteration)
{
	double	za;
	double	zb;
	double	zatmp;
	int		iteration;

	iteration = 1;
	za = 0;
	zb = 0;
	while (iteration <= max_iteration)
	{
		zatmp = za;
		za = (za * za) - (zb * zb) + (a);
		zb = (2 * zatmp * zb) + (b);
		if (module(za, zb) > 2)
			return (0xFF00 * (iteration * 100 / max_iteration) / 100);
		iteration++;
	}
	return (0);
}

void		mandelbrot(t_data *data)
{
	double	a;
	double	b;

	a = 0;
	while (a < WIN_SIZE)
	{
		b = 0;
		while (b < WIN_SIZE)
		{
			put_pixel_to_image(data, mb_is_on(conv_win_to_rep(a, data->min_x,
				data->max_x), conv_win_to_rep(b, data->min_y, data->max_y),
				data->iteration_number), a, b);
			b++;
		}
		a++;
	}
}
