/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 11:07:54 by jcamhi            #+#    #+#             */
/*   Updated: 2017/05/24 11:07:59 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	zoom(t_data *data, double ratio_zoom, int x, int y)
{
	double	xp;
	double	yp;

	xp = conv_win_to_rep(x, data->min_x, data->max_x);
	yp = conv_win_to_rep(y, data->min_y, data->max_y);
	data->max_x = data->max_x - (data->max_x - xp) * ratio_zoom;
	data->min_x = data->min_x + (xp - data->min_x) * ratio_zoom;
	data->max_y = data->max_y - (data->max_y - yp) * ratio_zoom;
	data->min_y = data->min_y + (yp - data->min_y) * ratio_zoom;
}
