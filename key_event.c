/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 11:07:37 by jcamhi            #+#    #+#             */
/*   Updated: 2017/05/24 11:07:40 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	change_it_and_print(t_data *data, int it)
{
	data->iteration_number += it;
	fractal(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

void	move_func(t_data *data, int kc)
{
	if (kc == 126)
	{
		data->min_y -= (data->max_y - data->min_y) / 25;
		data->max_y -= (data->max_y - data->min_y) / 25;
	}
	else if (kc == 125)
	{
		data->min_y += (data->max_y - data->min_y) / 25;
		data->max_y += (data->max_y - data->min_y) / 25;
	}
	else if (kc == 123)
	{
		data->min_x -= (data->max_x - data->min_x) / 25;
		data->max_x -= (data->max_x - data->min_x) / 25;
	}
	else if (kc == 124)
	{
		data->min_x += (data->max_x - data->min_x) / 25;
		data->max_x += (data->max_x - data->min_x) / 25;
	}
	fractal(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

void	color_key(t_data *data, int kc)
{
	if (kc == 12)
	{
		cycle_type(data);
	}
	else if (kc == 13)
	{
		if (data->color_type == 'b' || data->color_type == 'e')
			cycle_color_b(data);
		else if (data->color_type == 'd')
			cycle_color_d(data);
	}
	fractal(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

void	change_fractal_and_print(t_data *data)
{
	if (data->fractal == mandelbrot)
		data->fractal = julia;
	else if (data->fractal == julia)
		data->fractal = bship;
	else
		data->fractal = mandelbrot;
	fractal(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

void	cycle_mouse_mode(t_data *data)
{
	if (data->mouse_mode == 'w')
		data->mouse_mode = 'n';
	else
		data->mouse_mode = 'w';
}
