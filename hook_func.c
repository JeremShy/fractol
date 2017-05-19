#include <fractol.h>

int key_hook(int kc, void *param)
{
	t_data *data;

	data = (t_data*)param;
	ft_printf("%d - \n", kc);
	if (kc == 53)
		free_mlx_and_exit(data);
	if (kc == 45)
	{
		data->iteration_number += 5;
		// clear_image(data);
		fill_image(data, 0xFFFFFF);
		data->fractal(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	}
	else if (kc == 46)
	{
		data->iteration_number -= 5;
		// clear_image(data);
		fill_image(data, 0xFFFFFF);
		data->fractal(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	}
	return (0);
}

int mouse_hook(int button, int x, int y, void *param)
{
	t_data *data;

	data = (t_data*)param;
	ft_printf("button  : %d, x : %d, y : %d\n", button, x, y);
	return (0);
}
