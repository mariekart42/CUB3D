# include "../inc/cub3d.h"

double	m(t_put_line *x_data, int case_)
{
	double	m;

	m = (x_data->y[1] - x_data->y[0]) / (x_data->x[1] - x_data->x[0]);
	if (case_ == 2 && m < 0)
		m *= -1;
	if (case_ == 3 && m > 0)
		m *= -1;
	return (m);
}

/*
 * function calculates the y-intercept b (y = mx+[b])
 * 		b = m * x1 - y1
 *  or  b = m * x2 - y1
 * (i always take x2 and y2 cause they don't change during the algo)
 */
double	b(t_put_line *x_data, int case_)
{
	double	b;

	if (case_ == 1 || case_ == 4)
	{
		b = m(x_data, 1) * x_data->x[1] - x_data->y[1];
		return (b * (-1));
	}
	else if (case_ == 3)
	{
		b = m(x_data, 3) * x_data->x[1] - (HIGHT - x_data->y[1]);
		if (b < 0)
			b *= -1;
		return (b);
	}
	else
	{
		b = m(x_data, 2) * x_data->x[1] - (HIGHT - x_data->y[1]);
		if (b < 0)
			b *= -1;
		return (b);
	}
}

void	error_msg(char *msg)
{
	write(STDERR_FILENO, msg, ft_strlen(msg));
	exit(EXIT_FAILURE);
}
