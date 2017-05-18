#include <fractol.h>

int main()
{
	t_data data;

	ft_printf("Hi !\n");
	data.mlx = mlx_init();
	if (handle_error_void(data.mlx, NULL, "Error with mlx_init"))
		return (0);

	data.win = mlx_new_window(data.mlx, WIN_SIZE, WIN_SIZE, "fractol - Rainbow Dash is best pony !");
	if (handle_error_void(data.win, NULL, "Error with mlx_new_window"))
		return (0);
	mlx_loop(data.mlx);
	return (0);
}
