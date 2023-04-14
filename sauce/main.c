# include "../inc/cub3d.h"
# include "../libft/libft.h"

int32_t	destroy_window(t_hold *hold)
{
	mlx_destroy_window(hold->mlx, hold->mlx_win);
	exit(0);
}

int update_dot_position(t_hold *hold)
{
    mlx_clear_window(hold->mlx, hold->mlx_win);
    mlx_put_image_to_window(hold->mlx, hold->mlx_win, hold->img_ptr, hold->x, hold->y);
    // hold->x += 1;
    // hold->y += 10;
    // draw_line(hold->mlx, hold->mlx_win, hold->x, hold->y, hold->x+200, hold->y+200, 0xffdab9);
    // draw_line_of_view_of_player(hold);
    // put_cross(hold, 200, 200);
    // put_cross(hold, hold->x, hold->y);
    // put_cross(hold, hold->next_x, hold->next_y);
    draw_looking_direction(hold);
    // hold->prev_x = hold->x;
    // hold->prev_y = hold->y;
    return (0);
}

int32_t create_window(t_hold *hold)
{
    hold->mlx_win = mlx_new_window(hold->mlx, 1000, 700, "WINDOW_NAME");
    if (!hold->mlx_win)
	{
		free(hold->mlx_win);
		return (0);
	}
    hold->img_ptr = mlx_xpm_file_to_image(hold->mlx, "invader.xpm", &hold->x, &hold->y);
    return (1);
}

int key_hook(int keycode, t_hold *hold)
{
    if (keycode == ESCAPE)
        exit(0);
    if (keycode == LEFT)
    {
        hold->x -= 10;
    hold->next_x = hold->x-40;
    hold->next_y = hold->y;
    }
    else if (keycode == RIGHT)
    {
        hold->x += 10;
    hold->next_x = hold->x +40;
    hold->next_y = hold->y;
    }
    else if (keycode == DOWN)
    {
        hold->y += 10;
    hold->next_y = hold->y +40;
    hold->next_x = hold->x;
    }
    else if (keycode == UP)
    {
        hold->y -= 10;
    hold->next_y = hold->y -40;
    hold->next_x = hold->x;
    }
    return (0);
}

int32_t init_hold(t_hold *hold)
{
    hold->x = 20;
    hold->y = 22;
    hold->next_x = 0;
    hold->next_y = 0;
    hold->mlx = mlx_init();
    if (!hold->mlx)
		return (0);
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

int main(void)
{
    write(1 ,"les gooooo\n", 11);
    t_hold hold;
    
    if (!init_hold(&hold) || !create_window(&hold))
        return (MLX_ERROR);
    // pars_map(&hold);
    // draw_grit(&hold);
    mlx_key_hook(hold.mlx_win, key_hook, &hold);
    mlx_loop_hook(hold.mlx, update_dot_position, &hold);

    put_cross(&hold, 200, 200);
        // draw_line_of_view_of_player(&hold);
    // put_cross(&hold, hold.x, hold.y);
    mlx_loop(hold.mlx);
}




//! NEXT:
// - create 2d map
// - key also works if pressed


//! GENERAL:
// - optim Makefile 
//      -> .o files in object folder
//      -> libmlx.dylib autom in root of CUB