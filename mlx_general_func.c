#include <fractol.h>

int	init_the_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (handle_error_void(data->mlx, NULL, "Error with mlx_init"))
		return (0);
	data->win = mlx_new_window(data->mlx, WIN_SIZE, WIN_SIZE,
		"fractol - Rainbow Dash is best pony !");
	if (handle_error_void(data->win, NULL, "Error with mlx_new_window"))
		return (0);
	data->img = mlx_new_image(data->mlx, WIN_SIZE, WIN_SIZE);
	if (handle_error_void(data->img, NULL, "Error with mlx_new_image"))
		return (0);
	data->img = mlx_new_image(data->mlx, WIN_SIZE, WIN_SIZE);
	if (handle_error_void(data->img, NULL, "Error with mlx_new_image"))
		return (0);
	data->addr = mlx_get_data_addr(data->img, &(data->bpp), &(data->size_line),
		&(data->endian));
	if (handle_error_void(data->addr, NULL, "Error with mlx_get_data_addr"))
		return (0);
	if (data->bpp != 32 || data->endian != 0)
	{
		ft_printf(
			"Please use a school mac with 32 bpp and little endian ! :D <3\n");
		return (0);
	}
	return (1);
}
