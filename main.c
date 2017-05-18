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

	data.img = mlx_new_image(data.mlx, WIN_SIZE, WIN_SIZE);
	if (handle_error_void(data.img, NULL, "Error with mlx_new_image"))
		return (0);

	data.img = mlx_new_image(data.mlx, WIN_SIZE, WIN_SIZE);
	if (handle_error_void(data.img, NULL, "Error with mlx_new_image"))
		return (0);

	data.addr = mlx_get_data_addr(data.img, &(data.bpp), &(data.size_line), &(data.endian));
	if (handle_error_void(data.addr, NULL, "Error with mlx_get_data_addr"))
		return (0);

	if (data.bpp != 32 || data.endian != 0)
	{
		ft_printf("Please use a school mac with 32 bpp and little endian ! :D <3\n");
		return (0);
	}

	// put_pixel_to_image(data, 255, 255, 255, 24, 24);
	int color;

	color = (0xFF << 0) + (0x00 << 8) + (0x00 << 16);

	int i = 0;
	int j = 0;

	while (i < WIN_SIZE)
	{
		while (j < WIN_SIZE)
		{
			put_pixel_to_image(&data,(0xFF << 0) + (0xFF << 8) + (0xFF << 16), i, j);
			j++;
		}
		j = 0;
		i++;
	}
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);


	ft_printf("pouet !\n");
	clear_image(&data);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);

	mlx_loop(data.mlx);
	return (0);
}
