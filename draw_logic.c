#include "includes/fdf.h"

//run on the map_2d and set two points to connect with wire for put_pixel function.

// o -- o -- o -- o -- o -- o 
// |    |    |    |    |    |
// o -- o -- o -- o -- o -- o 
// |    |    |    |    |    |
// o -- o -- o -- o -- o -- o 
// |    |    |    |    |    |
// o -- o -- o -- o -- o -- o 

// map[0,0] -- map[0,1]
// |               |
// map[1,0] -- map[1,1]

// map(y,x) -- map(y, x + 1)
// |               |
// map(y + 1, x) -- map(y + 1, x + 1)

//pixel_bufferへの書き込み
//各行について隣接する点をワイヤーで接続
//各列について隣接する点をワイヤーで接続

static void connect_row(t_img *img, t_map_2d *map_2d)
{
    size_t y;
    size_t x;

    y = 0;
    x = 0;
    while (y < img->img_height)
    {
        while (x < img->img_width - 1)
        {
            draw_line(img, &map_2d[y * img->img_width + x], &map_2d[y * img->img_width + x + 1]);
            x++;
        }
        y++;
    }
}

static void connect_column(t_img *img, t_map_2d *map_2d)
{
    size_t y;
    size_t x;
    size_t i;

    y = 0;
    x = 0;
    i = 0;
    while (x < img->img_width)
    {
        while (y < img->img_height - 1)
        {
            draw_line(img, &map_2d[y * img->img_width + x], &map_2d[(y + 1) * img->img_width + x]);
            y++;
        }
        x++;
    }
}

void draw_map(t_img *img, t_map_2d *map_2d)
{
    connect_row(img, map_2d);
    connect_column(img, map_2d);
}