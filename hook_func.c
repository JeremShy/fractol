/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 11:07:29 by jcamhi            #+#    #+#             */
/*   Updated: 2017/05/24 11:07:32 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int	key_hook(int kc, void *param)
{
	t_data *data;

	data = (t_data*)param;
	if (kc == 53)
		free_mlx_and_exit(data);
	if (kc == 45)
		change_it_and_print(data, 5);
	else if (kc == 35)
	{
		data->is_paused = (data->is_paused == 0 ? 1 : 0);
		data->mx = -1;
		data->my = -1;
	}
	else if (kc == 126 || kc == 125 || kc == 123 || kc == 124)
		move_func(data, kc);
	else if (kc == 12 || kc == 13)
		color_key(data, kc);
	else if (kc == 14)
		change_fractal_and_print(data);
	else if (kc == 15)
		cycle_mouse_mode(data);
	else if (kc == 46)
		if (data->iteration_number > 0)
			change_it_and_print(data, -5);
	return (0);
}

int	mouse_hook(int button, int x, int y, void *param)
{
	t_data	*data;

	if (x < 0 || x > WIN_SIZE || y < 0 || y > WIN_SIZE)
		return (0);
	data = (t_data*)param;
	if (button == 1 || button == 5)
	{
		zoom(data, 0.25, x, y);
		fractal(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	}
	else if (button == 2 || button == 4)
	{
		zoom(data, -0.25, x, y);
		fractal(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	}
	return (0);
}

int	mouse_moove_hook(int x, int y, t_data *data)
{
	if (x < 0 || x > WIN_SIZE || y < 0 || y > WIN_SIZE || data->is_paused)
		return (0);
	if (data->mouse_mode == 'w')
		handle_mouse_w(data, x, y);
	else
		handle_mouse_n(data, x, y);
	fractal(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}
