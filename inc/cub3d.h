#ifndef CUB3D_H
# define CUB3D_H


// ----------------------------------------------------------------------------
//!		INCLUDES:
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>		// debugging
#include <math.h>		// cos and sin
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

# define WINDOW_NAME "u gay"
# define WIDHT 1000
# define HIGHT 700
#define PLAYER_POSITION_X 500
#define PLAYER_POSITION_Y 200
# define MLX_ERROR -1
# define ESCAPE 53
// # define SPEED 5
// # define ROTATION_SPEED 0.1
// # define STEP_SIZE 20
# define LINE_LEN 50

// directions:
# define LEFT 123
# define RIGHT 124
# define W 13
# define A 0
# define S 1
# define D 2

// ----------------------------------------------------------------------------
//!		STRUCTS:
typedef struct s_hold
{
	void	*mlx;
	void	*mlx_win;
	void	*img_ptr;
	char	*img_data;
	int32_t img_width;
	int32_t img_height;
	int32_t bits_per_pixel;



	float x;
	float y;
	float x_look;
	float y_look;
	float angle;
	bool go;
}						t_hold;

// ----------------------------------------------------------------------------
//!		FUNCTIONS:
void draw_line(void *mlx, void *win, int x0, int y0, int x1, int y1, int color);

int32_t init_hold(t_hold *hold);
int32_t create_window(t_hold *hold);
int32_t	destroy_window(t_hold *hold);



//!	KEYEVENTS:
int32_t update_dot_position(t_hold *hold);
float init_pi_val(int32_t keycode, char *sin_or_cos);
void calc_new_coordinate(t_hold *hold, int32_t keycode);
void calc_new_look_dir(t_hold *hold, int32_t keycode);
int32_t key_hook(int keycode, t_hold *hold);



// delete_later.c
void draw_line_of_view_of_player(t_hold *hold);
void init_put_line(t_hold *hold, double want_x, double want_y);
void draw_grit(t_hold *hold);
void draw_looking_direction(t_hold *hold);
void put_cross(t_hold *hold,int x, int y);
void put_info_on_window(t_hold *hold);

#endif