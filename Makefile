NAME	= cub3d
LIBFT	= libft

CFLAGS	= -Wall -Wextra -Werror -g
MLX		= -Lmlx -lmlx -framework OpenGL -framework AppKit
# DEBUG	= -fsanitize=address

LIB_F = libft
LIB = libft/libft.a

SRC		=	sauce/main.c \
			sauce/delete_later.c \
			sauce/00_put_line.c \
			sauce/01_put_line.c \
			sauce/02_put_line.c \
			sauce/03_put_line.c

SRC_PATH = sauce/
OBJ_PATH = obj/
INC_PATH = inc/

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

OBJ = $(SRC:%.c=%.o)

$(NAME): $(OBJ)
	cd libft && $(MAKE)
	$(CC) $(OBJ) $(MLX) $(DEBUG) $(LIB) -o $(NAME)

fclean: clean
	$(RM) $(NAME)
	@make fclean -C $(LIB_F)

clean:
	$(RM) $(OBJ_PATH)
	cd libft && $(MAKE) clean
	$(RM) sauce/*.o MLX/*.o
	@make clean -C $(LIB_F)

	
re: fclean all