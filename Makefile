SRC_NAME = main.c

OBJ_PATH = ./obj/

INC_PATH = ./includes

NAME = fractol

CC = gcc

CFLAGS = -Werror -Wextra -Wall -g

LFLAGS = -Llib/ -lft -lftprintf -lmlx

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))

all : $(NAME)

$(NAME) : $(OBJ)
	@mkdir -p lib
	make -C libsrcs/libft
	make -C libsrcs/ft_printf
	make -C libsrcs/mlx
	$(CC) $(LFLAGS) $(INC) -o $@ $^

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
	/bin/rm -fv $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null
	make -C libsrcs/libft clean
	make -C libsrcs/ft_printf clean
	make -C libsrcs/mlx clean

fclean: clean
	rm -fv $(NAME)
	make -C libsrcs/libft fclean
	make -C libsrcs/ft_printf fclean
	make -C libsrcs/mlx fclean
	@rmdir lib

re: fclean all

.PHONY : all clean fclean re
