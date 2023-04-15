#ifndef CUB3D_H
# define CUB3D_H


// ----------------------------------------------------------------------------
//!		INCLUDES:
#include <unistd.h>
#include <math.h>
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
#define PLAYER_POSITION_X 100
#define PLAYER_POSITION_Y 200
# define MLX_ERROR -1
# define ESCAPE 53
# define SPEED 5
# define ROTATION_SPEED 0.1
# define STEP_SIZE 20
// directions:
# define LEFT 123
# define RIGHT 124

// school mac:
# define W 13
# define A 0
# define S 1
# define D 2

<<<<<<< HEAD
// delete later
#define LINE_LEN 20 // len between player and direction point
=======
>>>>>>> baaa00c0419f089c06dae4d1cf689271e191521c
// ----------------------------------------------------------------------------
//!		STRUCTS:
typedef struct s_hold
{
	void	*mlx;
	void	*mlx_win;
	void	*img_ptr;
	char	**map;

	float x_dir;
	float y_dir;
	float angle;
	bool go;
// bool	forward;
// bool	backward;
// bool	left;
// bool	right;

	// int32_t cord_x;
	// int32_t cord_y;
	double dir_x;
	double dir_y;
	int32_t	x;
	int32_t	y;
<<<<<<< HEAD
	// int32_t pr_x;
	// int32_t pr_y;
	// int32_t	next_x;
	// int32_t	next_y;
=======
	int32_t pr_x;
	int32_t pr_y;
	int32_t	next_x;
	int32_t	next_y;
	double angle;
>>>>>>> baaa00c0419f089c06dae4d1cf689271e191521c
	int32_t img_width;
	int32_t img_height;
	int32_t bits_per_pixel;
	char	*img_data;
}						t_hold;

// ----------------------------------------------------------------------------
//!		FUNCTIONS:
void draw_line(void *mlx, void *win, int x0, int y0, int x1, int y1, int color);

int32_t init_hold(t_hold *hold);
int key_hook(int keycode, t_hold *hold);
int32_t create_window(t_hold *hold);
int update_dot_position(t_hold *hold);
int32_t	destroy_window(t_hold *hold);


// delete_later.c
void draw_line_of_view_of_player(t_hold *hold);
void init_put_line(t_hold *hold, double want_x, double want_y);
void draw_grit(t_hold *hold);
void draw_looking_direction(t_hold *hold);
void put_cross(t_hold *hold,int x, int y);

#endif