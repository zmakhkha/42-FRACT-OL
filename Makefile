
LIBFT_PATH = libft
LIBFT_A_PATH = libft/libft.a
NAME = mandelbrot

SRC = mandelbrot_main.c Common_files/mlx_utils.c Common_files/ft_colors.c Common_files/ft_hooks.c
OBJ = $(SRC:.c=.o)


CC = cc

CFLAGS = -Wall -Werror -Wextra

all: $(NAME_R) NAME

NAME : SRC_R
	@$(CC)  $(CFLAGS) $(SRC) $(LIBFT_A_PATH) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

SRC_R : $(OBJ)
	@make -C $(LIBFT_PATH)

%.o : %.c Common_files/header.h
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
	@make clean -C libft
	@rm -f $(OBJ)

fclean:
	@make fclean -C libft
	@rm -f $(OBJ) $(NAME)

re	: fclean	all

.PHONY: all clean fclean re