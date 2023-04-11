#include "../inc/cub3d.h"

/*
 * - if i need the value of the second x (of P2), 
 *   string needs to be "x2"
 * - function returns the x_value that is either fast[0] or slow[0]
 */
double	find_x(t_put_line *p_l, char *y1_or_y2)
{
	if (ft_strncmp(y1_or_y2, "x2", 2) == 0)
		return (p_l->x[1]);
	else if (p_l->slow[1] == 120)
		return (p_l->slow[0]);
	else
		return (p_l->fast[0]);
}

/*
 * - if i need the value of the second y (of P2), 
 *   string needs to be "y2"
 * - function returns the y_value that is either fast[0] or slow[0]
 */
double	find_y(t_put_line *p_l, char *y1_or_y2)
{
	if (ft_strncmp(y1_or_y2, "y2", 2) == 0)
		return (p_l->y[1]);
	else if (p_l->slow[1] == 121)
		return (p_l->slow[0]);
	else
		return (p_l->fast[0]);
}

/*
 * function returns 'true' if the given x and y values
 * are identical with the second Point (end-point)
 * reutrns false if not
 */
bool	reached_second_point(t_put_line *p_l)
{
	if (find_x(p_l, "x1") == p_l->x[1] && find_y(p_l, "y1") == p_l->y[1])
		return (true);
	else
		return (false);
}

/*
 * function calculates the disctance between the current coordinate and 
 * either:    the point on the line with the same y-value (y = mx+b)
 * 		   or the point on the line with the same x-value (x = [y-b]/m)
 * 	=>	depends on the gradient and the fast/slow-direction of the line (4 cases)
 * CASE 1: 					   |  CASE 2:
 * - negative gradient		   |  - negative gradient
 * - fast direction = x	       |  - fast_direction = y
 *   y						   |	y 
 *  0_^ 					   |   0_^			x P2
 *	1_|      		 		   |   1_|           
 *  2_|              x P2	   |   2_|
 *  3_| P1 x            	   |   3_|   P1 x		
 *  4_I-------------->x		   |   4_I-------------->x
 *    0 1 2 3 4 5 6 7 		   |	 0 1 2 3 4 5 6 7
 * 	    => y = mx+b			   |	   => x = [y-b]/m
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 * CASE 3:					   |  CASE 4:
 * - positive gradient		   |  - positive gradient
 * - fast direction = x		   |  - fast direction = y 
 *   y						   |    y 
 *  0_^ 					   |  0_^   P2 x		
 *	1_|        				   |  1_|           
 *  2_| P1 x            	   |  2_|
 *  3_|              x P2	   |  3_|   		x P1
 *  4_I-------------->x		   |  4_I-------------->x
 *    0 1 2 3 4 5 6 7 		   |    0 1 2 3 4 5 6 7
 * 		=> x = [y-b]/m		   | 	  => y = mx+b	
 */
double	distance_to_line(t_put_line *p_l, double slow_factor, double fast_factor)
{
	if ((p_l->slow[1] == 121 && slow_factor == -1 && fast_factor == 1) \
		|| (p_l->slow[1] == 120 && slow_factor == 1 && fast_factor == 1))
		return (find_y(p_l, "y1") - (m(p_l, 1) * \
				find_x(p_l, "x1") + b(p_l, 1)));
	if (p_l->slow[1] == 121 && slow_factor == 1 && fast_factor == 1)
		return ((HIGHT - find_y(p_l, "y1")) - (m(p_l, 3) * \
				find_x(p_l, "x1") + b(p_l, 3)));
	if (p_l->slow[1] == 120 && slow_factor == 1 && fast_factor == -1)
		return (((HIGHT - find_y(p_l, "y1") + b(p_l, 2)) / m(p_l, 2)) - \
				find_x(p_l, "x1"));
	else
		error_msg("failed to execute distance_to_line\n");
	return (0);
}