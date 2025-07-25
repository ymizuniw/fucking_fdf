#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "../libft/includes/libft.h"

typedef struct s_img
{
	void *img_ptr;
	char *data_addr;
	int bits_per_pixel;
	int size_line;
	int endian;
	int width;
	int height;
} t_img;

typedef struct s_app
{
	void *mlx_ptr;
	void *win_ptr;
	int width;
	int height;
	t_img *img; // Image structure for rendering
} t_app;

void put_pixel(t_img *img, int x, int y, int color);

void draw_scene(t_app *app);

#endif
