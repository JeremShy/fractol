/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 11:07:49 by jcamhi            #+#    #+#             */
/*   Updated: 2017/05/24 11:08:35 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	handle_mouse_n(t_data *data, int x, int y)
{
	data->cx = -2.5 + 5.0 * (double)x / (double)WIN_SIZE;
	data->cy = -2.5 + 5.0 * (double)y / (double)WIN_SIZE;
}

void	handle_mouse_w(t_data *data, int x, int y)
{
	if (data->mx == -1 || data->my == -1)
	{
		data->mx = x;
		data->my = y;
		return ;
	}
	if (x < data->mx)
		data->cx -= .05;
	else if (x > data->mx)
		data->cx += .05;
	if (y < data->my)
		data->cy -= .05;
	else if (y > data->my)
		data->cy += .05;
	data->mx = x;
	data->my = y;
}
