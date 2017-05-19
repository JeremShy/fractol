#include <fractol.h>

int	main()
{
	t_data data;

	ft_printf("Hi sir !\n");
	printf("%f\n", conv_win_to_rep(1, 0.1, 4.2));
	data.iteration_number = DEFAULT_ITERATION_NBR;
	data.fractal = mandelbrot;
	if (!init_the_mlx(&data))
		return (0);
	fill_image(&data, 0xFFFFFF);
	data.min_x = 0.1;
	data.min_y = 0.1;
	data.max_x = 4.2;
	data.max_y = 4.2;
	data.fractal(&data);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_key_hook(data.win, key_hook, &data);
	mlx_mouse_hook(data.win, mouse_hook, &data);
	mlx_loop(data.mlx);
	return (0);
}
