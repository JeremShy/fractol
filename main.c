#include <fractol.h>

int	main()
{
	t_data data;

	ft_printf("Hi sir !\n");
	data.iteration_number = DEFAULT_ITERATION_NBR;
	data.fractal = mandelbrot;
	if (!init_the_mlx(&data))
		return (0);
	fill_image(&data, 0xFFFFFF);
	data.min_x = -1.5;
	data.min_y = -1.5;
	data.max_x = 1;
	data.max_y = 1;
	data.fractal(&data);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_key_hook(data.win, key_hook, &data);
	mlx_mouse_hook(data.win, mouse_hook, &data);
	mlx_loop(data.mlx);
	return (0);
}
