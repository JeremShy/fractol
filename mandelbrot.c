#include <fractol.h>

static int	mb_is_on(double a, double b, int max_iteration)
{
	double	za;
	double	zb;
	double zatmp;
	int iteration;

	return (0xFF);
	iteration = 1;
	za = 0;
	zb = 0;
	while (iteration <= max_iteration)
	{
		zatmp = za;
		za = (za * za) - (zb * zb) + (a);
		zb = (2 * zatmp * zb) + (b);
		iteration++;
		if (module(za, zb) > 2)
			return (-1);
	}
	return(0xFF);
 }

void mandelbrot(t_data *data)
{
	double	a;
	double	b;
	int	color;

	ft_printf("Calling mandelbrot() - %d;\n", data->iteration_number);

	a = data->min_x;
	while (a < data->max_x)
	{
		b = data->min_y;
		while (b < data->max_y)
		{
			if ((color = mb_is_on(a, b, data->iteration_number)) >= 0)
				put_pixel_to_image(data, color, conv_rep_to_win(a, data->min_x, data->max_x), conv_rep_to_win(b, data->min_y, data->max_y));
			// b = b + 1 / (WIN_SIZE / (data->max_y - data->min_y));
			b = b + 1 / (WIN_SIZE / 4);
		}
		// a = a + 1 / (WIN_SIZE / (data->max_x - data->min_x));
		a = a + 1 / (WIN_SIZE / 4);
	}
	ft_printf("Leaving mandelbrot();\n");
}
