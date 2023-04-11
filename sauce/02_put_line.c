#include "../inc/cub3d.h"

double	get_slow_factor(t_put_line *p_l)
{
	if (p_l->slow[1] == 120)
		return (1);
	else if (p_l->slow[1] == 121 && p_l->y[0] > p_l->y[1])
		return (-1);
	if (p_l->slow[1] == 121 && p_l->y[0] < p_l->y[1])
		return (1);
	else
		error_msg("not able to access slow_factor ---> exit here\n");
	exit(EXIT_FAILURE);
}

/*
 * same as get_slow_fatcor() but for the fast factor
 * check out get_slow_factor() for more information
 */
double	get_fast_factor(t_put_line *p_l)
{
	if (p_l->fast[1] == 120)
		return (1);
	else if (p_l->fast[1] == 121 && p_l->y[0] > p_l->y[1])
		return (-1);
	else if (p_l->fast[1] == 121 && p_l->y[0] < p_l->y[1])
		return (1);
	else
		error_msg("not able to access fast_factor ---> exit here\n");
	exit(EXIT_FAILURE);
}

/*
 * fast and slow direction:
 * - fast direction means, that the distance between 
 *   eg. x1 - x0 is bigger then y1 - y0
 * 
 * y ^							(x2/y2)
 * 	 |							x P2
 * 	 |   						.
 * 	 | (x1/y1)					.
 * 	 |   P1 x . . . . . . . . . .
 * 	 I------------------------------>
 * 									x
 * => while we alwyas need to make a step in the fast direction, 
 * 	  making a step to the slow direction is not always needed
 * fast/slow[0] is the content of the 'fast' or 'slow' direction (either x or y)
 * fast/slow[1] is either 120 for 'x' or 121 for 'y'
 */
void	init_direction_speed(t_put_line *p_l)
{
	double	tmp_x;
	double	tmp_y;

	tmp_x = p_l->x[1] - p_l->x[0];
	tmp_y = p_l->y[1] - p_l->y[0];
	if (tmp_x < 0)
		tmp_x *= -1;
	if (tmp_y < 0)
		tmp_y *= -1;
	if (tmp_x >= tmp_y)
	{
		p_l->slow[0] = p_l->y[0];
		p_l->slow[1] = 121;
		p_l->fast[0] = p_l->x[0];
		p_l->fast[1] = 120;
	}
	else
	{
		p_l->slow[0] = p_l->x[0];
		p_l->slow[1] = 120;
		p_l->fast[0] = p_l->y[0];
		p_l->fast[1] = 121;
	}
}

/*
 * function checks if P1 is always on the right side from P2 
 * (P2 always left side)
 * if that's not the case, the two points swap positions
 */
void	check_koordinates(t_put_line *p_l)
{
	int32_t	swap_variable;

	if (p_l->x[0] > p_l->x[1])
	{
		swap_variable = p_l->x[0];
		p_l->x[0] = p_l->x[1];
		p_l->x[1] = swap_variable;
		swap_variable = p_l->y[0];
		p_l->y[0] = p_l->y[1];
		p_l->y[1] = swap_variable;
	}
}