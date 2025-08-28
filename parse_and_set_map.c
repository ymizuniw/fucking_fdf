#include <includes/fdf.h>

//wrapper function of parse_map() 
void	w_parse_map(char *map_file, char **map_orig, t_map_info *map_info)
{
    map_orig = parse_map(map_file, map_info);
    if (!map_orig)
    {
        ft_putstr_fd("Error: Failed to parse map.\n", 2);
        exit(EXIT_FAILURE);
    }
}

static	void	set_map_array(t_map_3d *p_3d, int ***map_orig, int width, int height, int color)
{
	size_t x;
	size_t y;
	size_t i;

	x = 0;
	y = 0;
	i = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			p_3d[i].x = x;
			p_3d[i].y = y;
			p_3d[i].z = (*map_orig)[y][x];
			p_3d[i].color = color;
			i++;
			x++;
		}
		y++;
	}
}

//set 3d map
static t_map_3d	*set_map_3d(int **map_orig, int width, int height, int color)
{
	t_map_3d	*p_3d;

	p_3d = malloc(sizeof(t_map_3d) * width * height);
	if (!p_3d)
		return (NULL);
	set_map_array(p_3d, map_orig, width, height, color);
	return (p_3d);
}

//wrapper function of set_map_3d()
int	w_set_map_3d(int **map_orig, t_map_3d *map_3d, t_map_info *map_info, int color)
{
    map_3d = set_map_3d(map_orig, map_info->width, map_info->height, color);
    if (!map_3d)
    {
        free_map_orig(map_3d);
        return (-1);
    }
    return (0);
}

void set_map_2d();
