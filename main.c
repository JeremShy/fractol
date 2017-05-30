/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 11:07:40 by jcamhi            #+#    #+#             */
/*   Updated: 2017/05/24 11:07:41 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static void	init_data(t_data *data)
{
	data->min_x = -1.5;
	data->min_y = -1.5;
	data->max_x = 1.5;
	data->max_y = 1.5;
	data->cx = 0.1;
	data->cy = .4;
	data->mx = -1;
	data->my = -1;
	data->is_paused = 0;
	data->mouse_mode = 'n';
}

int			main(int ac, char **av)
{
	t_data data;

	data.iteration_number = DEFAULT_ITERATION_NBR;
	if (!(data.fractal = handle_av(ac, av)))
		return (0);
	if (!init_the_mlx(&data))
		return (0);
	fill_image(&data, 0xFFFFFF);
	init_color(&data);
	init_data(&data);
	fractal(&data);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_key_hook(data.win, key_hook, &data);
	mlx_mouse_hook(data.win, mouse_hook, &data);
	mlx_hook(data.win, 6, (1L << 6), mouse_moove_hook, &data);
	mlx_loop(data.mlx);
	return (0);
}
