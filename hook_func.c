#include <fractol.h>

int key_hook(int kc, void *param)
{
	t_data *data;

	data = (t_data*)param;
	ft_printf("%d - \n", kc);
	if (kc == 53)
		free_mlx_and_exit(data);
	return (0);
}
