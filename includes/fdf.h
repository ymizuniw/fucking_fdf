#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "../libft/includes/libft.h"

typedef struct s_pixel
{
	int x;
	int y;
	int z;
	int color;
} t_pixel;

//Create a new node, and then connect new to tail of the current list.
typedef struct s_pixel_buffer
{
	t_pixel pixel;
	struct s_pixel_buffer *next;
} t_pixel_buffer;

//the list structure that have pixel_buffer as nodes.
typedef struct s_pixel_list
{
	t_pixel_buffer *head;
	t_pixel_buffer *tail;
	size_t			size;
}	t_pixel_list;

//function ptr for put_pixel to be set in s_img.
typedef void (*t_put_pixel)(t_img *img, int x, int y, int color);

//structure for containing img
typedef struct s_img
{
	void *img_ptr;
	char *data_addr;
	int bits_per_pixel;
	int size_line;
	int endian;
	int width;
	int height;
	t_put_pixel put_pixel; // function pointer of put_pixel
} t_img;

//structure for containing application information
typedef struct s_app
{
	void *mlx_ptr;
	void *win_ptr;
	int x_size;
	int y_size;
	t_img *img; // Image structure for rendering
} t_app;

void put_pixel(t_img *img, int x, int y, int color);
void draw_scene(t_app *app);

#endif