#include "../inc/cub3d.h"
#define mapWidth 24
#define mapHeight 24
#define screenWidth 640
#define screenHeight 480

int worldMap[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void draw_field(t_hold *hold, float x1, float y1, float x2, float y2, int colour)
{
    int i = 0;
    while(i < 30)
    {
        draw_line(hold, x1, y1+i, x2, y2+i, colour);
        i++;
    }
}

void draw_hc_map(t_hold *hold)
{
    int i = 1;
    int k = 1;
    int m = 30;

    while(i<mapHeight+1)
    {
        while(k<mapWidth+1)
        {
            if(worldMap[i-1][k-1] == 0)
                draw_field(hold, k*m, i*m, k*m+LINE_LEN, i*m, 0xcd4f39);
            else
                draw_field(hold, k*m, i*m, k*m+LINE_LEN, i*m, 0xab82ff);
            k++;
        }
        k=1;
        i++;
    }
}

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
		my_mlx_pixel_put(hold, x, y, 0xb0e0e6);
		my_mlx_pixel_put(hold, x, y - 2 + (len * 2), 0xb0e0e6);
		len--;
	}
	// middle point
	my_mlx_pixel_put(hold, save_x, save_y, 0XFF0000);
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
            my_mlx_pixel_put(hold, i, x, 0xfffafa);
            if (x % factor ==0)
            {
                while (++p < WIDHT)
                    my_mlx_pixel_put(hold, p, x, 0xfffafa);
                p = -1;
            }
        }
        x = 0;
        i+= factor;
    }
}

void draw_looking_direction(t_hold *hold)
{
    draw_line(hold, hold->x, hold->y, (hold->x_look), (hold->y_look), 0xbebebe);
    put_cross(hold, hold->x, hold->y);
}

void put_info_on_window(t_hold *hold)
{
    char str[20];
    sprintf(str, "%f", hold->x); 
    mlx_string_put(hold->mlx, hold->mlx_win, 10, 750, 0xeeeed1, "x: ");
    mlx_string_put(hold->mlx, hold->mlx_win, 30, 750, 0xeeeed1, str);
    sprintf(str, "%f", hold->y); 
    mlx_string_put(hold->mlx, hold->mlx_win, 10, 770, 0xeeeed1, "y: ");
    mlx_string_put(hold->mlx, hold->mlx_win, 30, 770, 0xeeeed1, str);
    sprintf(str, "%f", hold->x_look); 
    mlx_string_put(hold->mlx, hold->mlx_win, 130, 750, 0xeec900, "x_look: ");
    mlx_string_put(hold->mlx, hold->mlx_win, 200, 750, 0xeec900, str);
    sprintf(str, "%f", hold->y_look); 
    mlx_string_put(hold->mlx, hold->mlx_win, 130, 770, 0xeec900, "y_look: ");
    mlx_string_put(hold->mlx, hold->mlx_win, 200, 770, 0xeec900, str);
    sprintf(str, "%f", hold->angle); 
    mlx_string_put(hold->mlx, hold->mlx_win, 10, 730, 0xff82ab, "angle: ");
    mlx_string_put(hold->mlx, hold->mlx_win, 75, 730, 0xff82ab, str);
}