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

// map(i,j) -- map(i, j + 1)
// |               |
// map(i + 1, j) -- map(i + 1, j + 1)

//pixel_bufferへの書き込み
//各行について隣接する点をワイヤーで接続
//各列について隣接する点をワイヤーで接続

void draw_map(t_img *img)
{
    connect_row(*img);
    connect_column(*img);
}

void connect_row(t_img img)
{
    size_t i;
    size_t j;

    i = 0;
    j = 0;
    while (i < img.height)
    {
        while (j < img.width - 1)
        {
            draw_line(i, j, i, j + 1);
            j++;
        }
        i++;
    }
}

void connect_column(t_img img)
{
    size_t i;
    size_t j;

    i = 0;
    j = 0;
    while (j < img.width)
    {
        while (i < img.height - 1)
        {
            draw_line(i, j, i + 1, j);
            i++;
        }
        j++;
    }
}
