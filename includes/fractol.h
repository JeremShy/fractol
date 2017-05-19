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
	void	*img;
	char	*addr;
	int		bpp;
	int 	size_line;
	int		endian;
}				t_data;

typedef struct	s_coord
{
	int		x;
	int		y;
}				t_coord;

int				handle_error_void(void *variable, void *error_value, char *msg);
void			put_pixel_to_image(t_data *data, int color, int x, int y);
void			clear_image(t_data *data);
int				get_color_code(int r, int v, int b);
int				init_the_mlx(t_data *data);


#endif
