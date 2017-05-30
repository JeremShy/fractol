/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 11:07:27 by jcamhi            #+#    #+#             */
/*   Updated: 2017/05/24 11:07:28 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static void	*img_thread_func_1(void *datas)
{
	t_data	*data;
	double	a;
	double	b;

	data = (t_data*)datas;
	a = 0;
	while (a <= WIN_SIZE / 2)
	{
		b = 0;
		while (b <= WIN_SIZE / 2)
		{
			put_pixel_to_image(data, data->fractal(conv_win_to_rep(a,
				data->min_x,
				data->max_x), conv_win_to_rep(b, data->min_y, data->max_y),
				data->iteration_number, data), a, b);
			b++;
		}
		a++;
	}
	pthread_exit(NULL);
}

static void	*img_thread_func_2(void *datas)
{
	t_data	*data;
	double	a;
	double	b;

	data = (t_data*)datas;
	a = WIN_SIZE / 2 + 1;
	while (a <= WIN_SIZE - 1)
	{
		b = 0;
		while (b <= WIN_SIZE / 2)
		{
			put_pixel_to_image(data, data->fractal(conv_win_to_rep(a,
				data->min_x,
				data->max_x), conv_win_to_rep(b, data->min_y, data->max_y),
				data->iteration_number, data), a, b);
			b++;
		}
		a++;
	}
	pthread_exit(NULL);
}

static void	*img_thread_func_3(void *datas)
{
	t_data	*data;
	double	a;
	double	b;

	data = (t_data*)datas;
	a = 0;
	while (a <= WIN_SIZE / 2)
	{
		b = WIN_SIZE / 2 + 1;
		while (b <= WIN_SIZE - 1)
		{
			put_pixel_to_image(data, data->fractal(conv_win_to_rep(a,
				data->min_x, data->max_x),
				conv_win_to_rep(b, data->min_y, data->max_y),
				data->iteration_number, data), a, b);
			b++;
		}
		a++;
	}
	pthread_exit(NULL);
}

static void	*img_thread_func_4(void *datas)
{
	t_data	*data;
	double	a;
	double	b;

	data = (t_data*)datas;
	a = WIN_SIZE / 2 + 1;
	while (a <= WIN_SIZE - 1)
	{
		b = WIN_SIZE / 2 + 1;
		while (b <= WIN_SIZE - 1)
		{
			put_pixel_to_image(data, data->fractal(conv_win_to_rep(a,
				data->min_x,
				data->max_x), conv_win_to_rep(b, data->min_y, data->max_y),
				data->iteration_number, data), a, b);
			b++;
		}
		a++;
	}
	pthread_exit(NULL);
}

void		fractal(t_data *data)
{
	pthread_t threads[4];

	pthread_create(threads + 0, NULL, img_thread_func_1, data);
	pthread_create(threads + 1, NULL, img_thread_func_2, data);
	pthread_create(threads + 2, NULL, img_thread_func_3, data);
	pthread_create(threads + 3, NULL, img_thread_func_4, data);
	pthread_join(threads[0], NULL);
	pthread_join(threads[1], NULL);
	pthread_join(threads[2], NULL);
	pthread_join(threads[3], NULL);
}
