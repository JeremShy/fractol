/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculs_repere.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 11:07:13 by jcamhi            #+#    #+#             */
/*   Updated: 2017/05/24 11:07:14 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

double	conv_rep_to_win(double x, double min, double max)
{
	double	diff;
	double	ret;
	double	prop;

	diff = 0 - min;
	min += diff;
	max += diff;
	prop = WIN_SIZE / max;
	ret = (x + diff) * prop;
	return (ret);
}

double	conv_win_to_rep(double x, double min, double max)
{
	double	diff;
	double	ret;
	double	prop;

	diff = 0 - min;
	min += diff;
	max += diff;
	prop = max / WIN_SIZE;
	ret = (x * prop) - diff;
	return (ret);
}
