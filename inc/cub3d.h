#ifndef CUB3D_H
# define CUB3D_H


// ----------------------------------------------------------------------------
//!		INCLUDES:
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
# include <stdbool.h>	// bool
# include <fcntl.h>	    // open func
# include <limits.h>	// for macros
# include "../MLX/mlx.h"
# include "../libft/libft.h"


// ----------------------------------------------------------------------------
//!		MACROS:
# define RED   "\x1B[31m"
# define GRN   "\x1B[32m"
# define YEL   "\x1B[33m"
# define BLU   "\x1B[34m"
# define MAG   "\x1B[35m"
# define CYN   "\x1B[36m"
# define WHT   "\x1B[37m"
# define RESET "\x1B[0m"

# define WINDOW_NAME "Das ist ein window lol"
# define WIDHT 1000
# define HIGHT 700
# define MLX_ERROR -1
# define ESCAPE 53
// directions:
# define LEFT 123
# define RIGHT 124
# define DOWN 125
# define UP 126
// ----------------------------------------------------------------------------
//!		STRUCTS:

typedef struct s_hold
{
	void	*mlx;
	void	*mlx_win;
	void	*img_ptr;
	int32_t	x;
	int32_t	y;

}						t_hold;

// ----------------------------------------------------------------------------
//!		FUNCTIONS:

int32_t init_hold(t_hold *hold);
int key_hook(int keycode, t_hold *hold);
void draw_grit(t_hold *hold);
int32_t create_window(t_hold *hold);
int update_dot_position(t_hold *hold);
int32_t	destroy_window(t_hold *hold);

#endif