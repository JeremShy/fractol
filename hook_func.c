#include <fractol.h>

int	key_hook(int kc, void *param)
{
	t_data *data;

	data = (t_data*)param;
	ft_printf("%d - \n", kc);
	if (kc == 53)
		free_mlx_and_exit(data);
	if (kc == 45)
	{
		change_it_and_print(data, 5);
	}
	else if (kc == 46)
		if (data->iteration_number > 0)
			change_it_and_print(data, -5);
	return (0);
}

int	mouse_hook(int button, int x, int y, void *param)
{
	t_data	*data;

	data = (t_data*)param;
	if (button == 1 || button == 5)
	{
		zoom(data, 0.25, x, y);
		fill_image(data, 0xFFFFFF);
		data->fractal(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	}
	else if (button == 2 || button == 4)
	{
		zoom(data, -0.25, x, y);
		fill_image(data, 0xFFFFFF);
		data->fractal(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	}
	return (0);
}
