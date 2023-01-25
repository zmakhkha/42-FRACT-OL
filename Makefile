
LIBFT_PATH = libft
LIBFT_A_PATH = libft/libft.a
NAME = mandelbrot

SRC = mandelbrot_main.c Common_files/mlx_utils.c
OBJ = $(SRC:.c=.o)


CC = cc

CFLAGS = 

all: $(NAME_R) NAME

NAME : SRC_R
	$(CC)  $(CFLAGS) $(OBJ) $(LIBFT_A_PATH) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

SRC_R : $(OBJ)
	@make -C $(LIBFT_PATH)

%.o : %.c Common_files/header.h
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean:
	@rm -f $(OBJ) $(NAME)

re	: fclean	all

.PHONY: all clean fclean re