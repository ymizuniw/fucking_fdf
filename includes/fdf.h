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

// pixel info struct
typedef struct s_pixel
{
	int		x;
	int		y;
	int		z;
	int		color;
}			t_pixel;

// img info struct
typedef struct s_img
{
	void	*img_ptr;
	char	*data_addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		width;
	int		height;
}			t_img;

// app info struct
typedef struct s_app
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		x_size;
	int		y_size;
	t_img	*img;
}			t_app;

void		put_pixel(t_img *img, int x, int y, int color);
void		draw_line(t_img *img, int x0, int y0, int x1, int y1, int color);
void		draw_scene(t_app *app);

// the fixed angle for isometric projection
# define COS30 0.86602540378f
# define SIN30 0.5f
// vector and matrix info structure
// z = map_3d[y][x];
typedef struct s_vec_3
{
	float	x;
	float	y;
	float	z;
}			t_vec_3;

typedef struct s_vec_2
{
	float	x;
	float	y;
}			t_vec_2;

//t_matrix keeps the accumulated quantity of rotation and scale.
//so, the type should be defined as t_matrix *var;
typedef struct s_matrix
{
	float	theta_x;
	float	theta_y;
	float	theta_z;
	float	scale;
}			t_matrix;

// rotation matrix and isometric proj functions
t_vec_2		convert_object(t_vec_3 p, t_matrix *mat);
void		rotate_x(t_vec_3 *p, float t);
void		rotate_y(t_vec_3 *p, float t);
void		rotate_z(t_vec_3 *p, float t);
void		project_iso(t_vec_3 p);

#endif