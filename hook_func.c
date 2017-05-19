#include <fractol.h>

int key_hook(int kc, void *param)
{
	t_data *data;
	ft_printf("%d - \n", kc);
	data = (t_data*)param;
	if (kc == 53)
	{
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_image(data->mlx, data->img);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int loop_hook(void *param)
{
	return (0);
}
