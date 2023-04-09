# include "../inc/cub3d.h"

int	keyboard_hook(int key)
{
	if (key == ESCAPE)
		exit(0);
	return (0);
}

int32_t	destroy_window(t_hold *hold)
{
	mlx_destroy_window(hold->mlx, hold->mlx_win);
	exit(0);
}

int32_t create_window(t_hold *hold)
{
    hold->mlx = mlx_init();
    if (!hold->mlx)
		return (0);
    hold->mlx_win = mlx_new_window(hold->mlx, WIDHT, HIGHT, WINDOW_NAME);
    if (!hold->mlx_win)
	{
		free(hold->mlx_win);
		return (0);
	}
    mlx_key_hook(hold->mlx_win, keyboard_hook, hold);
    mlx_hook(hold->mlx_win, 17, 0, destroy_window, hold);
    return (1);
}

int main(void)
{
    t_hold hold;
    write(1 ,"les gooooo\n", 11);

    if (!create_window(&hold))
        return (MLX_ERROR);
    mlx_loop(hold.mlx);

}





//! NEXT:
// - draw grit


//! GENERAL:
// - optim Makefile 
//      -> .o files in object folder
//      -> libmlx.dylib autom in root of CUB