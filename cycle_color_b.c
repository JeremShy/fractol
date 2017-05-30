/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle_color_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 11:07:23 by jcamhi            #+#    #+#             */
/*   Updated: 2017/05/24 11:07:25 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static void	cycle_color_b_2(t_data *data)
{
	if (data->color == 0x1100FF)
		data->color = 0xFF1111;
	else if (data->color == 0xFF1111)
		data->color = 0xBBCC00;
	else if (data->color == 0xBBCC00)
		data->color = 0xFF11FF;
	else if (data->color == 0xFF11FF)
		data->color = 0x1111FF;
	else if (data->color == 0x1111FF)
		data->color = 0xAABBCC;
}

void		cycle_color_b(t_data *data)
{
	if (data->color == 0xAABBCC)
		data->color = 0xFF0000;
	else if (data->color == 0xFF0000)
		data->color = 0x00FD12;
	else if (data->color == 0x00FD12)
		data->color = 0xAA0011;
	else if (data->color == 0xAA0011)
		data->color = 0x1100FF;
	else
		cycle_color_b_2(data);
}
