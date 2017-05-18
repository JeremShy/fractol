#include <fractol.h>

void	put_pixel_to_image(t_data *data, int color, int x, int y)
{
	char		*img;
	size_t	value;

	// ft_printf("color : %#X\n", color);
	value = mlx_get_color_value(data->mlx, color);
	// ft_printf("value : %#X\n", color);

	// ft_printf("b : %#x, v : %#x, r : %#x", value >> 16, (value >> 8) - ((value >> 16) << 8), value - ((value >> 8) << 8));

	(data->addr)[y * data->size_line + x * 4 + 0] = value - ((value >> 8) << 8);
	(data->addr)[y * data->size_line + x * 4 + 1] = (value >> 8) - ((value >> 16) << 8);
	(data->addr)[y * data->size_line + x * 4 + 2] = value >> 16;
}

void clear_image(t_data *data)
{
	size_t i;

	i = 0;
	while (i < WIN_SIZE * data->size_line)
	{
		(data->addr)[i] = 0;
		i++;
	}
}
