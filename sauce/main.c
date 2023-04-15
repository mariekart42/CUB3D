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
    if (hold->go == true)
    {
        mlx_put_image_to_window(hold->mlx, hold->mlx_win, hold->img_ptr, hold->x_dir - hold->img_width / 2, hold->y_dir - hold->img_height / 2);
        hold->x = hold->x_dir;
        hold->y = hold->y_dir;
    }
    else
        mlx_put_image_to_window(hold->mlx, hold->mlx_win, hold->img_ptr, hold->x - hold->img_width / 2, hold->y - hold->img_height / 2);

    draw_looking_direction(hold);

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
    hold->bits_per_pixel = 8;
    hold->img_ptr = mlx_xpm_file_to_image(hold->mlx, "invader.xpm", &hold->x, &hold->y);
<<<<<<< HEAD
    hold->img_data = mlx_get_data_addr(hold->img_ptr, &hold->bits_per_pixel, &hold->img_width, &hold->img_height);
    
    // if firection is N:
    hold->x_dir = hold->x;
    hold->y_dir = hold->y + LINE_LEN;
    return (1);
}


int32_t key_hook(int keycode, t_hold *hold)
{
    if (keycode == ESCAPE)
        exit(0);
    // hold->pr_x = hold->x;
    // hold->pr_y = hold->y;
        hold->go = false;
    if (keycode == A)
    {
        hold->x_dir -= LINE_LEN;
        hold->go = true;
=======
    // hold->img_data = mlx_get_data_addr(hold->img_ptr, &hold->bits_per_pixel, &hold->img_width, &hold->img_height);
    return (1);
}

// int key_hook(int keycode, t_hold *hold)
// {
//     if (keycode == ESCAPE)
//         exit(0);
//     // hold->pr_x = hold->x;
//     // hold->pr_y = hold->y;
//     if (keycode == A)
//     {
//         hold->x -= cos(hold->angle) * SPEED+STEP_SIZE;
//         hold->y -= sin(hold->angle) * SPEED;
//         // hold->x -= 10;
//     // hold->next_x = hold->x-40;
//     // hold->next_y = hold->y;
//     }
//     else if (keycode == D)
//     {
//         // hold->x += 10;
//     // hold->next_x = hold->x +40;
//     // hold->next_y = hold->y;
//         hold->x += cos(hold->angle) * SPEED+STEP_SIZE;
//         hold->y += sin(hold->angle) * SPEED;
//     }
//     else if (keycode == S)
//     {
//     //     hold->y += 10;
//     // hold->next_y = hold->y +40;
//     // hold->next_x = hold->x;
//         // hold->x += (cos(hold->angle) * SPEED);
//         // hold->y += sin(hold->angle) * SPEED+STEP_SIZE;
//        hold->x += SPEED*cos(hold->angle);
//         hold->y += SPEED+STEP_SIZE*sin(hold->angle);
//     }
//     else if (keycode == W)
//     {
//         hold->x -= SPEED*cos(hold->angle);
//         hold->y -= SPEED+STEP_SIZE*sin(hold->angle);
//     //     hold->y -= 10;
//     // hold->next_y = hold->y -40;
//     // hold->next_x = hold->x;
//     }
//     if (keycode == LEFT)
//     {
//         hold->angle += ROTATION_SPEED;
//     //     // hold->y -= 10;
//     //     // hold->x -= 10;
//     // // hold->next_x = hold->next_x -5;
//     // // hold->next_y = hold->next_y -10;
//     // hold->next_x = hold->next_x *sin(2);
//     // hold->next_y = hold->next_y *cos(2);
//     }
//     if (keycode == RIGHT)
//     {
//         hold->angle -= ROTATION_SPEED;
//         // hold->y -= 10;
//         // hold->x -= 10;
//     // hold->next_x = hold->next_x *sin(2);
//     // hold->next_y = hold->next_y *cos(2);
//     }
//     return (0);
// }


int key_hook(int keycode, t_hold *hold)
{
    if (keycode == ESCAPE)
        exit(0);
    hold->angle = 0.6;
    if (keycode == A)
    {
        // double new_x = hold->x * cos(hold->angle) - hold->y *sin(hold->angle);
        // double new_y = hold->x * sin(hold->angle) + hold->y * cos(hold->angle);
        // put_cross(hold, new_x, new_y);
        // draw_line(hold->mlx, hold->mlx_win, hold->x, hold->y, new_x, new_y, 0xffdab9);
        // hold->x = new_x;
        // hold->y = new_y;
        // hold->x += SPEED-(STEP_SIZE*cos(hold->angle));
        // hold->y += SPEED * sin(hold->angle);
>>>>>>> baaa00c0419f089c06dae4d1cf689271e191521c
    }
    else if (keycode == D)
    {
        hold->x_dir += LINE_LEN;
        hold->go = true;

    }
    else if (keycode == S)
    {
        hold->y_dir += LINE_LEN;
        hold->go = true;

    }
    else if (keycode == W)
    {
        hold->y_dir -= LINE_LEN;
        hold->go = true;

    }
    if (keycode == LEFT)
    {
<<<<<<< HEAD
        // calc angle between x_axis and current line

        hold->x_dir =cos(hold->angle) * LINE_LEN;
        hold->y_dir =sin(hold->angle) * LINE_LEN;
        hold->go = false;ھ 
=======
        hold->dir_x = hold->x * cos(hold->angle) - hold->y *sin(hold->angle);
        hold->dir_y = hold->x * sin(hold->angle) + hold->y * cos(hold->angle);
        // hold->angle += ROTATION_SPEED;
    }
    if (keycode == RIGHT)
    {
        hold->dir_x = hold->x * cos(hold->angle) - hold->y *sin(hold->angle);
        hold->dir_y = hold->x * sin(hold->angle) + hold->y * cos(hold->angle);
        // hold->angle -= ROTATION_SPEED;
>>>>>>> baaa00c0419f089c06dae4d1cf689271e191521c
    }
    // if (keycode == RIGHT)
    // {
    //     hold->x_dir = cos(hold->angle) * LINE_LEN;
    //     hold->y_dir = sin(hold->angle) * LINE_LEN;
    //     hold->go = false;
    // }
    return (0);
}

int32_t init_hold(t_hold *hold)
{
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

// direction vector is equal to the letter parsed from map file
void init_direction_vector(t_hold *hold)
{
    // if letter N:
    hold->x_dir = PLAYER_POSITION_X;
    hold->y_dir = PLAYER_POSITION_Y - LINE_LEN;
}

int main(void)
{
    write(1 ,"les gooooo\n", 11);
    t_hold hold;
    
    if (!init_hold(&hold) || !create_window(&hold))
        return (MLX_ERROR);

    init_direction_vector(&hold);
    hold.angle =0.5;
    // draw_grit(&hold);
    mlx_key_hook(hold.mlx_win, key_hook, &hold);
    mlx_loop_hook(hold.mlx, update_dot_position, &hold);

    // put_cross(&hold, 200, 200);
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