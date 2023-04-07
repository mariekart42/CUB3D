NAME = cub3d
LIBFT = libft
SRC =	sauce/main.c

CFLAGS = -Wall -Wextra -Werror -Iincludes -g
# DEBUG = -fsanitize=address
LIBS = -Lmlx -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

OBJ = $(SRC:%.c=%.o)

$(NAME): $(OBJ)
	$(MAKE) -C MLX/
	cd libft && make bonus; cd ../
	$(CC) $(LIBFT)/libft.a $(OBJ) $(CFLAGS) $(LIBS)  -o $(NAME)
	@echo "Everything compiled successfully"

g:
	$(MAKE) -C libft/
	$(CC) $(SRC) $(CFLAGS) $(LIBS) $(LIBFT)/libft.a -o $(NAME)
	@echo "my shit compiled successfully"

clean:
	@$(RM) $(NAME)
	
fclean: clean
	@$(MAKE) clean -C MLX/
	@$(MAKE) clean -C libft/
	
re: fclean all