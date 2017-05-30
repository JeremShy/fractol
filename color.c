/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 11:07:18 by jcamhi            #+#    #+#             */
/*   Updated: 2017/05/24 11:07:19 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int		color(t_data *data, int it, int max_it)
{
	if (data->color_type == 'b')
		return (data->color * it / max_it);
	else if (data->color_type == 'd')
		return (get_color_code(data->color_r * it
					/ max_it, data->color_g * it / max_it,
					data->color_b * it / max_it));
	else
		return (data->color * it / max_it) * data->cx * data->cy;
}

void	cycle_type(t_data *data)
{
	if (data->color_type == 'b')
		data->color_type = 'd';
	else if (data->color_type == 'd')
		data->color_type = 'e';
	else if (data->color_type == 'e')
		data->color_type = 'b';
}

void	init_color(t_data *data)
{
	data->color_type = 'd';
	data->color_r = 0;
	data->color_g = 0;
	data->color_b = 0xFF;
	data->color = 0xAABBCC;
}
