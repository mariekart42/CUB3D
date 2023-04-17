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

    }
    draw_looking_direction(hold);
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


int32_t key_hook(int keycode, t_hold *hold)
{
    float store_x_look;

    if (keycode == ESCAPE)
        exit(0);
    if (keycode == A)
    {
        hold->x -= LINE_LEN;
        hold->x_look -= LINE_LEN;
        hold->go = true;
    }
    else if (keycode == D)
    {
        hold->x += LINE_LEN;
        hold->x_look += LINE_LEN;
        hold->go = true;

    }
    else if (keycode == S)
    {
        hold->y += LINE_LEN;
        hold->y_look += LINE_LEN;
        hold->go = true;

    }
    else if (keycode == W)
    {
        float tmp_x;
        float tmp_y;
        tmp_x = hold->x_look-hold->x;
        tmp_y = hold->y_look-hold->y;
        hold->y = hold->y_look;
        hold->x = hold->x_look;
        hold->x_look = 2*tmp_x;
        hold->y_look = -2*tmp_y;
        // hold->y_look -= LINE_LEN;
        hold->go = true;

    }
    if (keycode == LEFT)
    {
        store_x_look = hold->x_look;
    //x2 = x0 + (x1 - x0)*cos(θ) + (y1 - y0)*sin(θ)
        hold->x_look = hold->x + (hold->x_look - hold->x) * cos(hold->angle) + (hold->y_look - hold->y) * sin(hold->angle);
    //y2 = y0 + (y1 - y0)*cos(θ) - (x1 - x0)*sin(θ)
        hold->y_look =hold->y + (hold->y_look - hold->y) * cos(hold->angle) - (store_x_look - hold->x) * sin(hold->angle);
        hold->go = false;
    }
    if (keycode == RIGHT)
    {
        store_x_look = hold->x_look;
    //x2 = x0 + (x1 - x0)*cos(θ) + (y1 - y0)*sin(θ)
        hold->x_look = hold->x + (hold->x_look - hold->x) * cos(2*M_PI+hold->angle) + (hold->y_look - hold->y) * sin(2*M_PI-hold->angle);
    //y2 = y0 + (y1 - y0)*cos(θ) - (x1 - x0)*sin(θ)
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


//! GENERAL:
// - optim Makefile 
//      -> .o files in object folder
//      -> libmlx.dylib autom in root of CUB