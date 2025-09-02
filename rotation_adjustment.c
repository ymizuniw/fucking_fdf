#include "includes/fdf.h"

// ・1e-8
// >>非常に小さい値。回転量が非常に小さい場合、回転を実際に適用しない。返り値は恒等変換行列。
// ・Rodrigues
// >>ロドリゲスの回転。あるベクトルkを軸にベクトル空間を回転写像する。
// ・the meaning of getting sqrtf(....)
// >> 正規化。ロドリゲスの回転は、回転軸方向の単位ベクトルに関して行われるため、軸ベクトルの長さで割って大きさを1に調整する。
// ・Rv
// >>三次元世界の軸における回転。方向キーによる回転を、等角投影しているため、三次元座標空間における回転とユーザー視点の回転が直感的に一致するようにするためにいくつか行列による変換が必要になる。
// ・Uv
// >>ユーザー視点の総回転。
// ・R_world = B^-1 x R_view x B
// >>R_world :オブジェクト世界の回転行列。B :等角回転行列。R_view :ユーザ視点での回転行列。
// >>操作順 :Bの逆行列(等角戻し)→R_view行列(オブジェクト回転)->B行列(等角ずらし)
// ・U = R_world x U
// >>ユーザによる回転量の保存。
// ・Proj = B x U

// ・Up/Down :画面x軸
// ・Left/Right :画面y軸

// 参考
// 「金沢工業大学、ロドリゲスの回転公式」
// https://w3e.kanazawa-it.ac.jp/math/physics/category/physical_math/linear_algebra/henkan-tex.cgi?target=/math/physics/category/physical_math/linear_algebra/rodrigues_rotation_matrix.html

t_mat3	mat3_identity(void);
t_mat3	mat3_multiple(t_mat3 A, t_mat3 B);
t_mat3	mat3_transpose(t_mat3 A);
t_mat3	mat3_rot_axis(t_vec3 axis_unit, float angle);

t_mat3	mat3_transpose(t_mat3 a)
{
	t_mat3	ta;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			ta.m[i][j] = a.m[j][i];
			j++;
		}
		i++;
	}
	return (ta);
}

t_mat3	mat3_identity(void)
{
	t_mat3	iden;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			if (i == j)
				iden.m[i][j] = 1;
			else
				iden.m[i][j] = 0;
			j++;
		}
		i++;
	}
	return (iden);
}

t_mat3	mat3_multiple(t_mat3 a, t_mat3 b)
{
	t_mat3	r;
	size_t	i;
	size_t	j;
	size_t	k;

    ft_bzero(&r, sizeof(t_mat3));
	i = 0;
	j = 0;
	k = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			k = 0;
			while (k < 3)
			{
				r.m[i][j] += a.m[i][k] * b.m[k][j];
				k++;
			}
			j++;
		}
		i++;
	}
	return (r);
}

t_vec3	mat3_apply(t_mat3 m, t_vec3 v)
{
	t_vec3	rv;

	rv.x = m.m[0][0] * v.x + m.m[0][1] * v.y + m.m[0][2] * v.z;
	rv.y = m.m[1][0] * v.x + m.m[1][1] * v.y + m.m[1][2] * v.z;
	rv.z = m.m[2][0] * v.x + m.m[2][1] * v.y + m.m[2][2] * v.z;
	return (rv);
}

t_mat3	display_axis_rot(t_vec3 axis, float angle)
{
	float	len;
	float	x;
	float	y;
	float	z;
	float	c;
	float	s;
	float	t;
	t_mat3	r;

	len = sqrtf(axis.x * axis.x + axis.y * axis.y + axis.z * axis.z);
	if (len < (float)(1e-8))
		return (mat3_identity());
	x = axis.x / len;
	y = axis.y / len;
	z = axis.z / len;
	c = cosf(angle);
	s = sinf(angle);
	t = 1.f - c;
	r.m[0][0] = t * x * x + c;
	r.m[0][1] = t * x * y - s * z;
	r.m[0][2] = t * x * z + s * y;
	r.m[1][0] = t * y * x + s * z;
	r.m[1][1] = t * y * y + c;
	r.m[1][2] = t * y * z - s * x;
	r.m[2][0] = t * z * x - s * y;
	r.m[2][1] = t * z * y + s * x;
	r.m[2][2] = t * z * z + c;
	return (r);
}

// app->mat 内に：base_rot(B), user_rot(U) を持つ設計を推奨
// 等角ベース：B = Rz(45°) * Rx(35.264°) を初期化時に作る

void	rotation_adjustment(t_app *app, t_vec3 axis_screen, float delta)
{
	t_mat3	rv;
	t_mat3	rw;
    t_mat3  base;

	base = app->mat->usr;
	rv = display_axis_rot(axis_screen, delta);
	rw = mat3_multiple(mat3_transpose(base), mat3_multiple(rv, base));
	app->mat->usr = mat3_multiple(rw, app->mat->usr);
	orthonormalize(&app->mat->usr);
}
