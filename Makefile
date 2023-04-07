NAME	= cub3d
LIBFT	= libft

CFLAGS	= -Wall -Wextra -Werror
MLX		= -Lmlx -lmlx -framework OpenGL -framework AppKit
DEBUG	= -fsanitize=address

SRC		= sauce/main.c
SRC_PATH = sauce/
OBJ_PATH = obj/
INC_PATH = inc/

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

OBJ = $(SRC:%.c=%.o)

$(NAME): $(OBJ)
	$(MAKE) -C MLX/
	$(CC) $(OBJ) $(MLX) $(DEBUG) -o $(NAME)

clean:
	@$(RM) $(NAME)
	
fclean: clean
	@$(MAKE) clean -C MLX/
	@$(MAKE) clean -C libft/
	
re: fclean all