/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 11:07:33 by jcamhi            #+#    #+#             */
/*   Updated: 2017/05/24 11:07:35 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int	julia(double a, double b, int max_iteration, t_data *data)
{
	double	cx;
	double	cy;
	double	tmp;
	int		iteration;

	cx = data->cx;
	cy = data->cy;
	iteration = 1;
	while (iteration <= max_iteration)
	{
		tmp = a;
		a = (a * a) - (b * b) + (cx);
		b = (2 * tmp * b) + (cy);
		iteration++;
		if (module(a, b) > 2)
			return (color(data, iteration, max_iteration));
	}
	return (0);
}
