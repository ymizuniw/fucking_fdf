#include "includes/fdf.h"


t_3d_vector
{11, 12, 13, ..., 1w}, 
{21, 22, 23, ..., 2w},
...
{h1, h2, h3, ..., hw}

t_2d_vector
{
    i = 0;
    while (i < size_i)
    {
        j = 0;
        while (j < size_j)
            p(i, j++);
        i++;
    }
}


//this function calls convertion proj_3v_2v() and set 2D vector.
void set_pixels(t_pixel pixel, t_3d_vector *map_v3, t_2d_vector *map_v2);
{
    
}



int main(void)
{

}