# include "../inc/cub3d.h"
# include "../libft/libft.h"

int32_t	destroy_window(t_hold *hold)
{
	mlx_destroy_window(hold->mlx, hold->mlx_win);
	exit(0);
}

void	my_mlx_pixel_put(t_hold *hold, int x, int y, int color)
{
	char	*dst;

	if (x < WIDHT && y < HIGHT && x > 0 && y > 0)
	{
		dst = hold->data_addr + (y * hold->size_line + x * (hold->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void init_cub(t_hold *hold, char **argv)
{
    hold->cub = malloc(sizeof(t_cub));
    hold->cub->img = NULL;
    hold->cub->img_2 = NULL;
    hold->cub->img_north = NULL;
    hold->cub->img_east = NULL;
    hold->cub->img_south = NULL;
    hold->cub->img_west = NULL;
    hold->cub->map = NULL;
    hold->cub->floor = NULL;
    hold->cub->path_north = NULL;
    hold->cub->path_east = NULL;
    hold->cub->path_south = NULL;
    hold->cub->path_west = NULL;
    hold->cub->map_rows = 1;
    hold->cub->map_columns = 0;
    hold->cub->player_dir = '\0';
	hold->cub->file_name = ft_strdup(argv[1]);
//wbu mlx and mlx_win
}

// gpt putline
void draw_line(t_hold *hold, int x0, int y0, int x1, int y1, int color)
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
        mlx_pixel_put(hold->mlx, hold->mlx_win, x0, y0, color);
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

// // direction vector is equal to the letter parsed from map file
// void init_direction_vector(t_hold *hold)
// {
//     // if letter N:
//     hold->x_look = PLAYER_POSITION_X;
//     hold->y_look = PLAYER_POSITION_Y - LINE_LEN;
// }

void check_4_general_errors(char **argv, int32_t argc)
{
    if (argc != 2)
		ft_error("Number of arguments must be 2!");
    check_file(argv[1]);
}

void init_structs(t_hold *hold, char **argv)
{
    hold->mlx = NULL;
    hold->x = 100;
    hold->y = 100;
    init_cub(hold, argv);
}


void initialize_mlx(t_hold *hold)
{
    hold->mlx = mlx_init();
    if (!hold->mlx)
		ft_error("Failed to malloc for struct!");
    hold->mlx_win = mlx_new_window(hold->mlx, WIDHT, HIGHT, WINDOW_NAME);
    if (!hold->mlx_win)
	{
		free(hold->mlx_win);
        // later free complete hold
		ft_error("Failed to open mlx window!");
	}
    hold->bits_per_pixel = 8;
    hold->size_line = 0;
    hold->endian = 0;
    hold->player_img_ptr = mlx_xpm_file_to_image(hold->mlx, "invader.xpm", (int*)&hold->x, (int*)&hold->y);
    hold->img_ptr = mlx_new_image(hold->mlx, WIDHT, HIGHT);
    // hold->player_addr = mlx_get_data_addr(hold->player_img_ptr, &hold->bits_per_pixel, &hold->size_line, &hold->endian);
    // hold->bits_per_pixel = 8;
    // hold->size_line = 0;
    // hold->endian = 0;
    hold->data_addr = mlx_get_data_addr(hold->img_ptr, &hold->bits_per_pixel, &hold->size_line, &hold->endian);
    hold->x = PLAYER_POSITION_X;
    hold->y = PLAYER_POSITION_Y;
    hold->x_look = hold->x;
    hold->y_look = hold->y - LINE_LEN;
    // hold->angle = 0.4;
    hold->angle = ROTATION_ANGLE;
    hold->go = false;
}

int main(int argc, char **argv)
{
    t_hold hold;
    (void)argc;
    
    check_4_general_errors(argv, argc);
    init_structs(&hold, argv);
    initialize_mlx(&hold);
    parse(hold.cub);

//mlx_hook(hive->vars->win, 2, 0, &key_hook, hive);
    mlx_hook(hold.mlx_win, 2, 0, key_hook, &hold);
    // mlx_key_hook(hold.mlx_win, key_hook, &hold);//before
    mlx_loop_hook(hold.mlx, update_dot_position, &hold);
    mlx_do_sync(hold.mlx);
    mlx_loop(hold.mlx);
}




//! NEXT:
// - create 2d map
// - key also works if pressed


//! GENERAL:
// - optim Makefile 
//      -> .o files in object folder
//      -> libmlx.dylib autom in root of CUB