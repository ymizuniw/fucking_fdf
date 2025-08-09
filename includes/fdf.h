#ifndef FDF_H
# define FDF_H

# include "../libft/includes/libft.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <mlx.h>

//parse map
typedef struct s_map_info
{
	size_t	height;
	size_t	width;
} t_map_info;

void	initialize_map_info(t_map_info *map_info);
void	free_double_array(char **row);
int		**parse_map(char *map, t_map_info *map_info);

//draw_line struct
typedef struct s_draw_line
{
	int dx;
	int dy;
	int x;
	int y;
	int sign_x;
	int sign_y;
	int err;
} t_draw_line;

//img info struct. img_ptr is set by mlx_new_image,
//bpp, size_line, and endian are set by mlx_get_data_addr internally.
//Therefore, params of mlx_get_data_addr should be passed by address.
typedef struct s_img
{
	void	*img_ptr;
	char	*data_addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		img_width;
	int		img_height;
}			t_img;

// app info struct
typedef struct s_app
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		win_width;
	int		win_height;
	t_img	*img;
}			t_app;

void		put_pixel(t_img *img, int x, int y, int color);
void		draw_line(t_img *img, t_map_2d *start, t_map_2d *end);
void		draw_scene(t_app *app);
void		draw_map(t_img *img, t_map_2d *map_2d);

// the fixed angle for isometric projection
# define COS30 0.86602540378f
# define SIN30 0.5f
// vector and matrix info structure
// z = map_3d[y][x];
typedef struct s_map_3d
{
	float	x;
	float	y;
	float	z;
	int		color;
}			t_map_3d;

typedef struct s_map_2d
{
	float	x;
	float	y;
	int	color;
}			t_map_2d;

//t_matrix keeps the accumulated quantity of rotation and scale.
//so, the type should be defined as t_matrix *var;

//rotation max and min angle are set? 2 pi -> 0 pi loop should be set for each axis.
typedef struct s_matrix
{
	float	theta_x;
	float	theta_y;
	float	theta_z;
	float	scale;
}			t_matrix;

// rotation matrix and isometric proj functions
t_map_2d		convert_object(t_map_3d p, t_matrix *mat);
void		rotate_x(t_map_3d *p, float t);
void		rotate_y(t_map_3d *p, float t);
void		rotate_z(t_map_3d *p, float t);
void		project_iso(t_map_3d p);

#endif
