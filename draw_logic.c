#include "includes/fdf.h"



map_2d

//run on the map_2d and set two points to connect with wire for put_pixel function.

o -- o -- o -- o -- o -- o 
|    |    |    |    |    |
o -- o -- o -- o -- o -- o 
|    |    |    |    |    |
o -- o -- o -- o -- o -- o 
|    |    |    |    |    |
o -- o -- o -- o -- o -- o 

map[0,0] -- map[0,1]
|               |
map[1,0] -- map[1,1]

map(i,j) -- map(i, j + 1)
|               |
map(i + 1, j) -- map(i + 1, j + 1)

while (i < width)
{
    draw_line(i, j, i++, );
    
}

//各行について隣接する点をワイヤーで接続
//各列につい