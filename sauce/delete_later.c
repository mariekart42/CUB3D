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
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0},
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
    int len = x2-x1;
    while(i < len)
    {
        draw_line(hold, x1, y1+i, x2, y2+i, colour);
        i++;
    }
}

void draw_hc_map(t_hold *hold)
{
    int i = 1;
    int k = 1;
    int m = 40;

    while(i<mapHeight+1)
    {
        while(k<mapWidth+1)
        {
            if(worldMap[i-1][k-1] == 1)
                draw_field(hold, k*m, i*m, k*m+LINE_LEN, i*m, 0xb03060);
            else if(worldMap[i-1][k-1] == 0)
                draw_field(hold, k*m, i*m, k*m+LINE_LEN, i*m, 0);
            else
                draw_field(hold, k*m, i*m, k*m+LINE_LEN, i*m, 0xab82ff);
            k++;
        }
        k=1;
        i++;
    }
}

// void draw_my_map(t_hold *hold)
// {
//     int32_t x = 0;
//     int32_t y = 0;
//     int32_t mx = 50;
//     int32_t my = 50;
//     int start_x = 100;
//     int start_y = 50;

//     while (hold->cub->map[y])
//     {
//         while(hold->cub->map[x])
//         {
//             if(hold->cub->map[y][x] == 49)
//                 draw_field(hold, (x*mx)+start_x, (y*my)+start_y, (x*mx)+start_x, (y*my)+start_y, 0xf0f8ff);
//             else
//                 draw_field(hold, (x*mx)+start_x, (y*my)+start_y, (x*mx)+start_x, (y*my)+start_y, 0xdeb887);
//             x++;
//         }
//         // mx=50;
//         x=0;
//         y++;
//     }
// }

void draw_my_map2(t_hold *hold)
{
    int32_t i = 0;
    int32_t x = 0;
    int32_t y = 0;
    // int32_t x_val = 200;
    int bigger = 40;
    int32_t y_val = 100;
    while(hold->cub->map[y])
    {
        while(hold->cub->map[y][x])
        {
            while(i<bigger)
            {
                draw_line(hold, x*bigger+100, y_val+i, x*bigger+bigger+100, y_val+i, 0xd3d3d3);
                i++;
            }
                draw_line(hold, x*bigger+100, y_val+i-1, x*bigger+100, y_val+i-1-bigger, 0x5cacee);
                draw_line(hold, x*bigger+100, y_val+i-1, x*bigger+100+bigger, y_val+i-1, 0x5cacee);
            // x_val+=10;
            i=0;
            x++;
        }
printf("[y: %d]  x: %d\n", y, x);
        y_val+=bigger;
        x=0;
        y++;
    }
    // exit(0);
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
		my_mlx_pixel_put(hold, x, y, 0x8db6cd);
		my_mlx_pixel_put(hold, x, y - 2 + (len * 2), 0x8db6cd);
		len--;
	}
	// middle point
	my_mlx_pixel_put(hold, save_x, save_y, 0XFF0000);
}

// void draw_grit(t_hold *hold)
// {
//     int32_t i = 0;
//     int32_t p = -1;
//     int32_t x = -1;
//     int32_t factor = 50;

//     while (i < WIDHT)
//     {
//         while (++x < HIGHT)
//         {
//             my_mlx_pixel_put(hold, i, x, 0xfffafa);
//             if (x % factor ==0)
//             {
//                 while (++p < WIDHT)
//                     my_mlx_pixel_put(hold, p, x, 0xfffafa);
//                 p = -1;
//             }
//         }
//         x = 0;
//         i+= factor;
//     }
// }

void draw_looking_direction(t_hold *hold)
{
    draw_line(hold, hold->x, hold->y, (hold->x_look), (hold->y_look), 0xbebebe);
    // put_cross(hold, hold->x, hold->y);
}

void put_info_on_window(t_hold *hold)
{
    char str[20];
    sprintf(str, "%f", hold->x); 
    mlx_string_put(hold->mlx, hold->mlx_win, 10, 950, 0xeeeed1, "x: ");
    mlx_string_put(hold->mlx, hold->mlx_win, 30, 950, 0xeeeed1, str);
    sprintf(str, "%f", hold->y); 
    mlx_string_put(hold->mlx, hold->mlx_win, 10, 970, 0xeeeed1, "y: ");
    mlx_string_put(hold->mlx, hold->mlx_win, 30, 970, 0xeeeed1, str);
    sprintf(str, "%f", hold->x_look); 
    mlx_string_put(hold->mlx, hold->mlx_win, 130, 950, 0xeec900, "x_look: ");
    mlx_string_put(hold->mlx, hold->mlx_win, 200, 950, 0xeec900, str);
    sprintf(str, "%f", hold->y_look); 
    mlx_string_put(hold->mlx, hold->mlx_win, 130, 970, 0xeec900, "y_look: ");
    mlx_string_put(hold->mlx, hold->mlx_win, 200, 970, 0xeec900, str);
    sprintf(str, "%f", hold->angle); 
    mlx_string_put(hold->mlx, hold->mlx_win, 10, 930, 0xff82ab, "angle: ");
    mlx_string_put(hold->mlx, hold->mlx_win, 75, 930, 0xff82ab, str);
}
