#include "../inc/cub3d.h"

void draw_grit(t_hold *hold)
{
    int32_t i = 0;
    int32_t p = -1;
    int32_t x = -1;
    int32_t factor = 50;

    while (i < WIDHT)
    {
        while (++x < HIGHT)
        {
            mlx_pixel_put(hold->mlx, hold->mlx_win, i, x, 0xfffafa);
            if (x % factor ==0)
            {
                while (++p < WIDHT)
                    mlx_pixel_put(hold->mlx, hold->mlx_win, p, x, 0xfffafa);
                p = -1;
            }
        }
        x = 0;
        i+= factor;
    }
}