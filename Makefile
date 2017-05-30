SRC_NAME = main.c \
						utils.c \
						mlx_img_func.c \
						mlx_general_func.c \
						hook_func.c \
						mandelbrot.c \
						complexe_nbr.c \
						calculs_repere.c \
						zoom.c \
						key_event.c \
						fractal.c \
						julia.c \
						bship.c \
						color.c \
						cycle_color_b.c \
						cycle_color_d.c \
						mouse_event.c

LIBFT_N = lib/libft.a
LIBFTPRINTF_N = lib/libftprintf.a
LIBMLX_N = lib/libmlx.a

OBJ_PATH = ./obj/

LIB_PATH = ./lib/

INC_PATH = ./includes

NAME = fractol

CC = gcc

CFLAGS = -Werror -Wextra -Wall -g

LFLAGS = -Llib/ -lft -lftprintf -lmlx

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
LIB = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))

all : $(NAME)

$(LIBFT_N) :
	@mkdir -p lib
	make -C libsrcs/libft

$(LIBFTPRINTF_N) :
	@mkdir -p lib
	make -C libsrcs/ft_printf

$(LIBMLX_N) :
	@mkdir -p lib
	make -C libsrcs/mlx

$(NAME) : $(LIBFT_N) $(LIBFTPRINTF_N) $(LIBMLX_N) $(OBJ)
	@mkdir -p lib
	$(CC) $(LFLAGS) $(INC) -o $@ $^ -framework OpenGL -framework AppKit

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
	/bin/rm -fv $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	make -C libsrcs/libft clean
	make -C libsrcs/ft_printf clean
	make -C libsrcs/mlx clean

fclean: clean
	rm -fv $(NAME)
	make -C libsrcs/libft fclean
	make -C libsrcs/ft_printf fclean
	make -C libsrcs/mlx fclean
	@rmdir lib 2> /dev/null || true


re: fclean all

.PHONY : all clean fclean re
