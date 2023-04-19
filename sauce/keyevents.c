# include "../inc/cub3d.h"

int32_t update_dot_position(t_hold *hold)
{
    mlx_put_image_to_window(hold->mlx, hold->mlx_win, hold->img_ptr, 0, 0);
	draw_looking_direction(hold);
	put_info_on_window(hold);
    mlx_put_image_to_window(hold->mlx, hold->mlx_win, hold->player_img_ptr, hold->x-10, hold->y-10);
    mlx_do_sync(hold->mlx);
    return (0);
}

float pi_val(int32_t keycode, char *sin_or_cos)
{
    if (ft_strncmp(sin_or_cos, "sin", 3) == 0)
    {
        if (keycode == A)
            return (0.5 * M_PI);
        if (keycode == D)
            return (1.5 * M_PI);
        if (keycode == S)
            return (M_PI);
    }
    else if (ft_strncmp(sin_or_cos, "cos", 3) == 0)
    {
        if (keycode == A)
            return (0.5 * M_PI);
        if (keycode == D)
            return (2.5 * M_PI);
        if (keycode == S)
            return (3 * M_PI);
    }
    return (0);
}

/* function calculates based on the keyhook_events, new position of the player */
void calc_new_coordinate(t_hold *hold, int32_t keycode)
{
    float store_x;
    float tmp_x;
	float tmp_y;

    tmp_x = hold->x_look - hold->x;
    tmp_y = hold->y - hold->y_look;
    store_x = hold->x;
    hold->x = hold->x + (hold->x_look - hold->x) * cos(pi_val(keycode, "cos")) \
            + (hold->y_look - hold->y) * sin(pi_val(keycode, "sin"));
    hold->y = hold->y + (hold->y_look - hold->y) * cos(pi_val(keycode, "cos")) \
            - (hold->x_look - store_x) * sin(pi_val(keycode, "sin"));
    hold->x_look = hold->x + tmp_x;
    hold->y_look = hold->y - tmp_y;
}

/* function calculates the new looking_direction based on the updated x and y values */
void calc_new_look_dir(t_hold *hold, int32_t keycode)
{
    float store_x_look;

	store_x_look = hold->x_look;
    if (keycode == LEFT)
    {
        hold->x_look = hold->x + (hold->x_look - hold->x) * cos(hold->angle) \
                    + (hold->y_look - hold->y) * sin(hold->angle);
        hold->y_look =hold->y + (hold->y_look - hold->y) * cos(hold->angle) \
                    - (store_x_look - hold->x) * sin(hold->angle);
    }
	else
	{
		hold->x_look = hold->x + (hold->x_look - hold->x) * cos(2*M_PI+hold->angle) \
                    + (hold->y_look - hold->y) * sin(2*M_PI-hold->angle);
        hold->y_look =hold->y + (hold->y_look - hold->y) * cos(2*M_PI+hold->angle) \
                    - (store_x_look - hold->x) * sin(2*M_PI-hold->angle);
	}
}

int32_t key_hook(int keycode, t_hold *hold)
{
    if (keycode == ESCAPE)
        exit(0);
    if (keycode == A || keycode == W || keycode == S || keycode == D)
        calc_new_coordinate(hold, keycode);
    if (keycode == LEFT || keycode == RIGHT)
        calc_new_look_dir(hold, keycode);
    return (0);
}