#include <fractol.h>

int main()
{
	t_data data;

	ft_printf("Hi !\n");

	if (!init_the_mlx(&data))
		return 0;
	clear_image(&data);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_loop(data.mlx);
	return (0);
}
