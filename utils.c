/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 11:07:51 by jcamhi            #+#    #+#             */
/*   Updated: 2017/05/24 11:07:53 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int		handle_error_void(void *variable, void *error_value, char *msg)
{
	if (variable == error_value)
	{
		ft_printf("%s\n", msg);
		return (1);
	}
	return (0);
}

t_fract	handle_av(int ac, char **av)
{
	if (ac < 2)
	{
		ft_printf("usage: %s [Mandelbrot | Julia | BShip]\n", av[0]);
		return (0);
	}
	if (ft_strequ(av[1], "Mandelbrot"))
		return (mandelbrot);
	else if (ft_strequ(av[1], "Julia"))
		return (julia);
	else if (ft_strequ(av[1], "BShip"))
		return (bship);
	ft_printf("%s: illegal option: \"%s\"\nusage: %s %s\n",
			av[0], av[1], av[0], "Mandelbrot | Julia | BShip");
	return (NULL);
}
