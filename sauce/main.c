# include "../inc/cub3d.h"
# include "../libft/libft.h"

int32_t	destroy_window(t_hold *hold)
{
	mlx_destroy_window(hold->mlx, hold->mlx_win);
	exit(0);
}

int update_dot_position(t_hold *hold)
{
    if (hold->go == true)
    {
        mlx_clear_window(hold->mlx, hold->mlx_win);
        mlx_put_image_to_window(hold->mlx, hold->mlx_win, hold->img_ptr, (hold->x) - 10, (hold->y) - 10);
        // printf("x: %d\ny: %d\nx_look: %d\ny_look: %d\n\n", hold->x, hold->y, hold->x_look, hold->y_look);
        // hold->x = hold->x_look;
        // hold->y = hold->y_look;
        // hold->x_look = 0;
        // hold->y_look = 0;
        put_info_on_window(hold);
        draw_looking_direction(hold);

    }
    else
    {
        mlx_clear_window(hold->mlx, hold->mlx_win);
        put_info_on_window(hold);
        draw_looking_direction(hold);

    }
    // else
    //     mlx_put_image_to_window(hold->mlx, hold->mlx_win, hold->img_ptr, hold->x - 10, hold->y-10);

    return (0);
}

int32_t create_window(t_hold *hold)
{
    // hold->x = (int)hold->x;
    // hold->y = (int)hold->y;
    hold->mlx_win = mlx_new_window(hold->mlx, 1000, 800, "WINDOW_NAME");
    if (!hold->mlx_win)
	{
		free(hold->mlx_win);
		return (0);
	}
    hold->bits_per_pixel = 8;
    hold->img_ptr = mlx_xpm_file_to_image(hold->mlx, "invader.xpm", (int*)&hold->x, (int*)&hold->y);

    // hold->img_data = mlx_get_data_addr(hold->img_ptr, &hold->bits_per_pixel, &hold->img_width, &hold->img_height);
    
    // if firection is N:
    hold->x_look = hold->x;
    hold->y_look = hold->y - LINE_LEN;
    return (1);
}

float init_pi_val(int32_t keycode, char *sin_or_cos)
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

float calc_new_coordinate(t_hold *hold, int32_t keycode, char x_or_y, float store_x)
{
    float pi_val_sin;
    float pi_val_cos;

    pi_val_sin = init_pi_val(keycode, "sin");
    pi_val_cos = init_pi_val(keycode, "cos");
    if (x_or_y == 'x')
        return (hold->x + (hold->x_look - hold->x) * cos(pi_val_cos) + (hold->y_look - hold->y) * sin(pi_val_sin));
    else
        return (hold->y + (hold->y_look - hold->y) * cos(pi_val_cos) - (hold->x_look - store_x) * sin(pi_val_sin));
    // hold->x = hold->x + (hold->x_look - hold->x) * cos(pi_val_cos *M_PI) + (hold->y_look - hold->y) * sin(pi_val_sin *M_PI);
    // hold->y =hold->y + (hold->y_look - hold->y) * cos(pi_val_cos *M_PI) - (hold->x_look - hold->x) * sin(pi_val_sin *M_PI);
}

int32_t key_hook(int keycode, t_hold *hold)
{
    float store_x_look;
    float store_x;

        float tmp_x;
        float tmp_y;
    if (keycode == ESCAPE)
        exit(0);
    if (keycode == A || keycode == W|| keycode == S || keycode == D)
    {
        tmp_x = hold->x_look-hold->x;
        tmp_y = hold->y-hold->y_look;
        store_x = hold->x;
        hold->x = calc_new_coordinate(hold, keycode, 'x', 0);
        hold->y = calc_new_coordinate(hold, keycode, 'y', store_x);
        hold->x_look = hold->x + (tmp_x);
        hold->y_look = hold->y - (tmp_y);
        hold->go = true;
    }

    // if (keycode == A)
    // {
    //     tmp_x = hold->x_look-hold->x;
    //     tmp_y = hold->y-hold->y_look;
    //     store_x = hold->x;
    //     hold->x = hold->x + (hold->x_look - hold->x) * cos(0.5 *M_PI) + (hold->y_look - hold->y) * sin(0.5 *M_PI);
    //     hold->y =hold->y + (hold->y_look - hold->y) * cos(0.5 *M_PI) - (hold->x_look - store_x) * sin(0.5 *M_PI);
    //     hold->x_look = hold->x + (tmp_x);
    //     hold->y_look = hold->y - (tmp_y);
    //     hold->go = true;
    // }
    // else if (keycode == D)
    // {
    //     tmp_x = hold->x_look-hold->x;
    //     tmp_y = hold->y-hold->y_look;
    //     store_x = hold->x;
    //     hold->x = hold->x + (hold->x_look - hold->x) * cos((2.5*M_PI)) + (hold->y_look - hold->y) * sin((1.5*M_PI));
    //     hold->y =hold->y + (hold->y_look - hold->y) * cos((2.5*M_PI)) - (hold->x_look - store_x) * sin((1.5*M_PI));
    //     hold->x_look = hold->x + (tmp_x);
    //     hold->y_look = hold->y - (tmp_y);
    //     hold->go = true;
    // }
    // else if (keycode == S)
    // {
    //     tmp_x = hold->x_look-hold->x;
    //     tmp_y = hold->y-hold->y_look;
    //     store_x = hold->x;
    //     hold->x = hold->x + (hold->x_look - hold->x) * cos((3*M_PI)) + (hold->y_look - hold->y) * sin((M_PI));
    //     hold->y =hold->y + (hold->y_look - hold->y) * cos((3*M_PI)) - (hold->x_look - store_x) * sin((M_PI));
    //     hold->go = true;
    //     hold->x_look = hold->x + (tmp_x);
    //     hold->y_look = hold->y - (tmp_y);
    // }
    // if (keycode == W)
    // {

    //     tmp_x = hold->x_look-hold->x;
    //     tmp_y = hold->y-hold->y_look;
    //     store_x = hold->x;
    //     hold->x = hold->x + (hold->x_look - hold->x) * cos((0)) + (hold->y_look - hold->y) * sin((0));
    //     hold->y =hold->y + (hold->y_look - hold->y) * cos((0)) - (hold->x_look - store_x) * sin((0));
    //     hold->go = true;
    //     hold->x_look = hold->x + (tmp_x);
    //     hold->y_look = hold->y - (tmp_y);



    //     // tmp_x = hold->x_look-hold->x;
    //     // tmp_y = hold->y-hold->y_look;
    //     // hold->y = hold->y_look;
    //     // hold->x = hold->x_look;
    //     // hold->x_look += tmp_x;
    //     // hold->y_look -= tmp_y;
    //     // hold->go = true;
    // }
    if (keycode == LEFT)
    {
        store_x_look = hold->x_look;
        hold->x_look = hold->x + (hold->x_look - hold->x) * cos(hold->angle) + (hold->y_look - hold->y) * sin(hold->angle);
        hold->y_look =hold->y + (hold->y_look - hold->y) * cos(hold->angle) - (store_x_look - hold->x) * sin(hold->angle);
        hold->go = false;
    }
    if (keycode == RIGHT)
    {
        store_x_look = hold->x_look;
        hold->x_look = hold->x + (hold->x_look - hold->x) * cos(2*M_PI+hold->angle) + (hold->y_look - hold->y) * sin(2*M_PI-hold->angle);
        hold->y_look =hold->y + (hold->y_look - hold->y) * cos(2*M_PI+hold->angle) - (store_x_look - hold->x) * sin(2*M_PI-hold->angle);
        hold->go = false;
    }
    return (0);
}

int32_t init_hold(t_hold *hold)
{
    hold->mlx = mlx_init();
    if (!hold->mlx)
		return (0);
    hold->x = 100;
    hold->y = 100;
    hold->x_look = 100;
    hold->y_look = 100;
    hold->go = false;
    return (1);
}

// gpt putline
void draw_line(void *mlx, void *win, int x0, int y0, int x1, int y1, int color)
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx, sy;
    if (x0 < x1) 
        sx = 1;
    else 
        sx = -1;
    if (y0 < y1)
        sy = 1;
    else
        sy = -1;
    int err = dx - dy;
    while (x0 != x1 || y0 != y1)
    {
        mlx_pixel_put(mlx, win, x0, y0, color);
        int e2 = 2 * err;
        if (e2 > -dy)
        {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y0 += sy;
        }
    }
}

// direction vector is equal to the letter parsed from map file
void init_direction_vector(t_hold *hold)
{
    // if letter N:
    hold->x_look = PLAYER_POSITION_X;
    hold->y_look = PLAYER_POSITION_Y - LINE_LEN;
}

int main(void)
{
    write(1 ,"les gooooo\n", 11);
    t_hold hold;
    
    if (!init_hold(&hold) || !create_window(&hold))
        return (MLX_ERROR);

    // init_direction_vector(&hold);
    // printf("x: %d\ny: %d\nx_look: %d\ny_look: %d\n\n", hold.x, hold.y, hold.x_look, hold.y_look);
    // draw_line(hold.mlx, hold.mlx_win, hold.x, hold.y, hold.x_look, hold.y_look, 0xbfefff);
    hold.angle =0.5;
    mlx_key_hook(hold.mlx_win, key_hook, &hold);
    mlx_loop_hook(hold.mlx, update_dot_position, &hold);
    mlx_loop(hold.mlx);
}




//! NEXT:
// - create 2d map
// - key also works if pressed
// - sidewide walk with angles


//! GENERAL:
// - optim Makefile 
//      -> .o files in object folder
//      -> libmlx.dylib autom in root of CUB