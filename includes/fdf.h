#ifndef FDF_H
# define FDF_H

# include "../libft/includes/ft_printf.h"
# include "../libft/includes/get_next_line.h"
# include "../libft/includes/libft.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <mlx.h>

# define KEYPRESS 2
# define KEYRELEASE 3
# define KEYPRESSMASK (1L << 0)
# define KEYRELEASEMASK (1L << 1)

// // key codes
// # define XK_Escape 0xFF1B
// # define XK_Left 0xFF51    /* Move left, left arrow */
// # define XK_Up 0xFF52      /* Move up, up arrow */
// # define XK_Right 0xFF53   /* Move right, right arrow */
// # define XK_Down 0xFF54    /* Move down, down arrow */
// # define XK_Shift_L 0xFFE1 /* Left shift */
// # define XK_Shift_R 0xFFE2 /* Right shift */

// the fixed angle for isometric projection
# define PI 3.14159265358979323846
# define COS30 0.86602540378f
# define SIN30 0.5f
# define PAN_UNIT 0.5f
# define ROT_UNIT 0.5f
# define SCALE_UNIT 1.1f
# define WIN_MAX 1000000
# define SCALE_LIM 0.9f

# define MALLOC_FAILURE "fatal! malloc failed."

// vector and matrix info structure
// z = map_3d[y][x];
typedef struct s_map_3d
{
	float				x;
	float				y;
	float				z;
	int					color;
}						t_map_3d;

typedef struct s_map_2d
{
	float				x;
	float				y;
	int					color;
}						t_map_2d;

typedef struct s_matrix
{
	float				theta_x;
	float				theta_y;
	float				theta_z;
	float				scale;
	float				pan_x;
	float				pan_y;
}						t_matrix;

typedef struct s_map
{
	size_t				map_size;
	int					color;
	size_t				height;
	size_t				width;
	t_map_2d			*map_2d;
	t_map_3d			*map_3d;
}						t_map;

// draw_line struct
typedef struct s_draw_line
{
	int					dx;
	int					dy;
	int					x;
	int					y;
	int					sign_x;
	int					sign_y;
}						t_draw_line;

// img info struct. img_ptr is set by mlx_new_image,
// bpp, size_line, and endian are set by mlx_get_data_addr internally.
// Therefore, params of mlx_get_data_addr should be passed by address.
typedef struct s_img
{
	void				*img_ptr;
	char				*data_addr;
	int					bits_per_pixel;
	int					size_line;
	int					endian;
	int					img_width;
	int					img_height;
}						t_img;

typedef struct s_option
{
	int					shift_on;
}						t_option;

// app info struct
typedef struct s_app
{
	void				*mlx_ptr;
	void				*win_ptr;
	t_option			*option;
	int					win_width;
	int					win_height;
	t_map				*map;
	t_matrix			*mat;
	t_img				*img;
}						t_app;

typedef struct s_split_map
{
	size_t				i;
	size_t				j;
	size_t				start;
	size_t				end;
}						t_split_map;

typedef struct s_parse_list
{
	int					*int_array;
	struct s_parse_list	*next;
}						t_parse_list;

// initial setup
void					alloc_app_content(t_app *app);

// parse map functions
void					alloc_maps(t_app *app, t_parse_list *head);
int						*ft_split_map(char *s);
t_parse_list			*get_int_array_list(t_parse_list *head, int fd);

// mlx entry point
void					mlx_app_work(t_app *app);

// key event
int						key_pressed(int key, t_app *a);
void					direction_shift(int key, t_app *app);
void					direction_mono(int key, t_app *app);
void					plus_minus_scale(int key, t_app *app);
int						key_released(int key, t_app *app);
int						expose_hook(void *param);

void					free_map(t_app *app);

// parse and set map
void					prepare_map(char *argv, t_app *app);
void					parse_map(const char *map_path, t_app *app);
void					convert_map(t_app *app);

// rotation matrix and isometric proj functions
t_map_2d				convert_points(t_map_3d ptr, t_matrix *mat);

// free resources and exit
void					free_app(t_app *app, const char *msg);
void					free_all_rscs(t_app *app, const char *msg);
void					free_all_rscs_exit(t_app *app, int status);
void					destroy_app(t_app *app);
void					perror_exit(char *msg);

// draw map
void					draw_map(t_app *app);
void					draw_line(t_img *img, t_map_2d *start, t_map_2d *end);
void					refresh(t_app *app);

// others
int						wopen(const char *path);
void					wclose(int fd);

#endif
