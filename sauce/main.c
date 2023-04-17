# include "../inc/cub3d.h"
# include "../libft/libft.h"

int32_t	destroy_window(t_hold *hold)
{
	mlx_destroy_window(hold->mlx, hold->mlx_win);
	exit(0);
}

int32_t create_window(t_hold *hold)
{
    hold->mlx_win = mlx_new_window(hold->mlx, 1000, 800, WINDOW_NAME);
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