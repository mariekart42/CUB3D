#include "../inc/cub3d.h"

void	put_horizontal_line(t_hold *hold)
{
	int	x1;
	t_put_line *p_l;

	p_l = hold->put_line;
	x1 = p_l->x[0];
	if (x1 <= p_l->x[1])
	{
		while (x1 <= p_l->x[1])
		{
			mlx_pixel_put(hold->mlx, hold->mlx_win, x1, p_l->y[0], \
				p_l->colour);
			x1++;
		}
	}
	else
	{
		while (x1 >= p_l->x[1])
		{
			mlx_pixel_put(hold->mlx, hold->mlx_win, x1, p_l->y[0], \
				p_l->colour);
			x1--;
		}
	}
}

void	put_vertical_line(t_hold *hold)
{
	int	y1;
	t_put_line *p_l;

	p_l = hold->put_line;
	y1 = p_l->y[0];
	if (y1 <= p_l->y[1])
	{
		while (y1 <= p_l->y[1])
		{
			mlx_pixel_put(hold->mlx, hold->mlx_win, p_l->x[0], y1, \
				p_l->colour);
			y1++;
		}
	}
	else
	{
		while (y1 >= p_l->y[1])
		{
			mlx_pixel_put(hold->mlx, hold->mlx_win, p_l->x[0], y1, \
				p_l->colour);
			y1--;
		}
	}
}
void	line_algo(t_hold *hold)
{
	double	slow_factor;
	double	fast_factor;
	t_put_line *p_l;

	p_l = hold->put_line;
	check_koordinates(hold->put_line);
	init_direction_speed(hold->put_line);
	slow_factor = get_slow_factor(hold->put_line);
	fast_factor = get_fast_factor(hold->put_line);
	while (reached_second_point(hold->put_line) == false)
	{
		hold->put_line->fast[0] += fast_factor;
		if (distance_to_line(hold->put_line, slow_factor, fast_factor) > 0.5)
			p_l->slow[0] += slow_factor;
		mlx_pixel_put(hold->mlx, hold->mlx_win, find_x(hold->put_line, "x1"), \
						find_y(hold->put_line, "y1"), p_l->colour);
	}
}

// explaination different if-statements:
// 1. if bot dots are exactly the same -> just put the one pixel
// 2. if both dots have the same x-val -> its just a vertical line
// 3. if both dots have the same y-val -> its just a horizontal line
// 4. else we need to put the line with the line algo
void	put_line(t_hold *hold)
{
	t_put_line *p_l;

	p_l = hold->put_line;
	if (p_l->x[0] == p_l->x[1] && p_l->y[0] == p_l->y[1])
		mlx_pixel_put(hold->mlx, hold->mlx_win, p_l->x[0], \
					hold->put_line->y[0], p_l->colour);
	else if (p_l->x[0] == p_l->x[1])
		put_vertical_line(hold);
	else if (p_l->y[0] == p_l->y[1])
		put_horizontal_line(hold);
	else
		line_algo(hold);
}