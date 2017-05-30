/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 11:07:42 by jcamhi            #+#    #+#             */
/*   Updated: 2017/05/24 11:07:44 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int	mandelbrot(double a, double b, int max_iteration, t_data *data)
{
	double	za;
	double	zb;
	double	zatmp;
	int		iteration;

	(void)data;
	iteration = 1;
	za = 0;
	zb = 0;
	while (iteration <= max_iteration)
	{
		zatmp = za;
		za = (za * za) - (zb * zb) + (a);
		zb = (2 * zatmp * zb) + (b);
		iteration++;
		if (module(za, zb) > 2)
			return (color(data, iteration, max_iteration));
	}
	return (0);
}
