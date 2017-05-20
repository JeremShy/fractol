#include <fractol.h>

void	change_it_and_print(t_data *data, int it)
{
	data->iteration_number += it;
	data->fractal(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
