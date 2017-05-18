#ifndef FRACTOL_H
# define FRACTOL_H

# define WIN_SIZE 840

# include <ft_printf.h>
# include <libft.h>
# include <mlx.h>

typedef struct	s_data
{
	void	*mlx;
	void	*win;
}				t_data;

int				handle_error_void(void *variable, void *error_value, char *msg);

#endif
