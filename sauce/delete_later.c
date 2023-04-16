#include "../inc/cub3d.h"

void put_cross(t_hold *hold,int x, int y)
{
	int save_x;
	int save_y;
	int minus_len;
	int len;
	
	save_x = x;
	save_y = y;
	len = 4;
	len++;
	minus_len = len * (-1);
	x += len;
	y -= len;
	while (len - 1 > minus_len)
	{
		x -= 1;
		y += 1;
		mlx_pixel_put(hold->mlx, hold->mlx_win, x, y, 0xb0e0e6);
		mlx_pixel_put(hold->mlx, hold->mlx_win, x, y - 2 + (len * 2), 0xb0e0e6);
		len--;
	}
	// middle point
	mlx_pixel_put(hold->mlx, hold->mlx_win, save_x, save_y, 0XFF0000);
}

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

void draw_looking_direction(t_hold *hold)
{
    // draw_line(hold->mlx, hold->mlx_win, 10, 10, 100, 100, 0xbebebe);
    // printf("x: %d\ny: %d\nnext_x: %d\nnext_y: %d\n\n", hold->x, hold->y, hold->next_x, hold->next_y);
    draw_line(hold->mlx, hold->mlx_win, hold->x, hold->y, (hold->x_look), (hold->y_look), 0xbebebe);
    // put_cross(hold, hold->x_look, hold->y_look);
    put_cross(hold, hold->x, hold->y);
    // hold->prev_x = hold->x;
    // hold->prev_y = hold->y;
}

void put_info_on_window(t_hold *hold)
{
    char str[20];
    sprintf(str, "%d", hold->x); 
    mlx_string_put(hold->mlx, hold->mlx_win, 10, 750, 0xeeeed1, "x: ");
    mlx_string_put(hold->mlx, hold->mlx_win, 30, 750, 0xeeeed1, str);
    sprintf(str, "%d", hold->y); 
    mlx_string_put(hold->mlx, hold->mlx_win, 10, 770, 0xeeeed1, "y: ");
    mlx_string_put(hold->mlx, hold->mlx_win, 30, 770, 0xeeeed1, str);
    sprintf(str, "%d", hold->x_look); 
    mlx_string_put(hold->mlx, hold->mlx_win, 80, 750, 0xeec900, "x_look: ");
    mlx_string_put(hold->mlx, hold->mlx_win, 150, 750, 0xeec900, str);
    sprintf(str, "%d", hold->y_look); 
    mlx_string_put(hold->mlx, hold->mlx_win, 80, 770, 0xeec900, "y_look: ");
    mlx_string_put(hold->mlx, hold->mlx_win, 150, 770, 0xeec900, str);
    sprintf(str, "%f", hold->angle); 
    mlx_string_put(hold->mlx, hold->mlx_win, 10, 730, 0xff82ab, "angle: ");
    mlx_string_put(hold->mlx, hold->mlx_win, 75, 730, 0xff82ab, str);
}