/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle_color_d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 11:07:25 by jcamhi            #+#    #+#             */
/*   Updated: 2017/05/24 11:07:26 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static void	cycle_color_d_2(t_data *data)
{
	if (data->color_r == 0x11
			&& data->color_g == 0xFF && data->color_b == 0xBB)
	{
		data->color_r = 0xFF;
		data->color_g = 0xFF;
		data->color_b = 0xFF;
	}
	else if (data->color_r == 0xFF
			&& data->color_g == 0xFF && data->color_b == 0xFF)
	{
		data->color_r = 0;
		data->color_g = 0;
		data->color_b = 0xFF;
	}
}

void		cycle_color_d(t_data *data)
{
	if (data->color_r == 0 && data->color_g == 0 && data->color_b == 0xFF)
	{
		data->color_b = 0;
		data->color_g = 0xFF;
	}
	else if (data->color_r == 0 && data->color_g == 0xFF && data->color_b == 0)
	{
		data->color_r = 0xFF;
		data->color_g = 0;
	}
	else if (data->color_r == 0xFF && data->color_g == 0 && data->color_b == 0)
	{
		data->color_r = 0x11;
		data->color_g = 0xFF;
		data->color_b = 0xBB;
	}
	else
		cycle_color_d_2(data);
}
