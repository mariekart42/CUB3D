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

void init_put_line(t_hold *hold, double want_x, double want_y)
{
    hold->put_line->x[0] = hold->x;
    hold->put_line->y[0] = hold->y;
    hold->put_line->x[1] = want_x;
    hold->put_line->y[1] = want_y;
}

void draw_line_of_view_of_player(t_hold *hold)
{
    printf("curr x: %d\ncurr y: %d\n", hold->x, hold->y);
    init_put_line(hold, 124, 44);
    put_line(hold);
    // sleep(4);
    // exit(0);
}