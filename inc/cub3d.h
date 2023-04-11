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

typedef struct s_put_line
{
	double	x[2];
	double	y[2];
	int32_t	linecount_map;
	int32_t	wordcount_map;
	int32_t	colour;
	int32_t	cross_colour;
	double	slow[2];
	double	fast[2];
}				t_put_line;

typedef struct s_hold
{
	void	*mlx;
	void	*mlx_win;
	void	*img_ptr;
	int32_t	x;
	int32_t	y;
	struct s_put_line	*put_line;

}						t_hold;

// ----------------------------------------------------------------------------
//!		FUNCTIONS:

int32_t init_hold(t_hold *hold);
int key_hook(int keycode, t_hold *hold);
int32_t create_window(t_hold *hold);
int update_dot_position(t_hold *hold);
int32_t	destroy_window(t_hold *hold);


// 00_put_line.c
void	put_horizontal_line(t_hold *hold);
void	put_vertical_line(t_hold *hold);
void	line_algo(t_hold *hold);
void	put_line(t_hold *hold);

// 01_put_line.c
double	find_x(t_put_line *p_l, char *y1_or_y2);
double	find_y(t_put_line *p_l, char *y1_or_y2);
bool	reached_second_point(t_put_line *p_l);
double	distance_to_line(t_put_line *p_l, double slow_factor, double fast_factor);

// 02_put_line.c
double	get_slow_factor(t_put_line *p_l);
double	get_fast_factor(t_put_line *p_l);
void	init_direction_speed(t_put_line *p_l);
void	check_koordinates(t_put_line *p_l);

// 03_put_line.c
double	m(t_put_line *x_data, int case_);
double	b(t_put_line *x_data, int case_);
void	error_msg(char *msg);


// delete_later.c
void draw_line_of_view_of_player(t_hold *hold);
void init_put_line(t_hold *hold, double want_x, double want_y);
void draw_grit(t_hold *hold);

#endif