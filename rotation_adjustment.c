・1e-8 
>>非常に小さい値。回転量が非常に小さい場合、回転を実際に適用しない。返り値は恒等変換行列。
・Rodrigues
>>ロドリゲスの回転。あるベクトルkを軸にベクトル空間を回転写像する。
・the meaning of getting sqrtf(....)
>> 正規化。ロドリゲスの回転は、回転軸方向の単位ベクトルに関して行われるため、軸ベクトルの長さで割って大きさを1に調整する。
・Rv
>>三次元世界の軸における回転。方向キーによる回転を、等角投影しているため、三次元座標空間における回転とユーザー視点の回転が直感的に一致するようにするためにいくつか行列による変換が必要になる。
・Uv
>>ユーザー視点の総回転。
・R_world = B^-1 x R_view x B
>>R_world :オブジェクト世界の回転行列。B :等角回転行列。R_view :ユーザ視点での回転行列。
>>操作順 :Bの逆行列(等角戻し)→R_view行列(オブジェクト回転)->B行列(等角ずらし)
・U = R_world x U
>>ユーザによる回転量の保存。
・Proj = B x U

・Up/Down :画面x軸
・Left/Right :画面y軸

参考
「金沢工業大学、ロドリゲスの回転公式」
https://w3e.kanazawa-it.ac.jp/math/physics/category/physical_math/linear_algebra/henkan-tex.cgi?target=/math/physics/category/physical_math/linear_algebra/rodrigues_rotation_matrix.html

typedef struct s_mat3
{
    float m[3][3]; 
} t_mat3;

typedef struct s_vec3
{
     float x, y, z; 
} t_vec3;

t_mat3 mat3_identity(void);
t_mat3 mat3_mul(t_mat3 A, t_mat3 B);
t_mat3 mat3_transpose(t_mat3 A);
t_mat3 mat3_rot_axis(t_vec3 axis_unit, float angle);

t_mat3 mat3_transpose(t_mat3 a)
{
    t_mat3 ta;
    size_t i;
    size_t j;

    i = 0;
    j = 0;
    while (i < 3)
    {
        j = 0;
        while (j < 3)
        {
            ta[i][j] = a[j][i];
            j++;
        }
        i++;
    }
}

t_mat3 mat3_identity(void)
{
    t_mat3 iden;

    size_t i;
    size_t j;

    i = 0;
    j = 0;
    while (i < 3)
    {
        j = 0;
        while (j < 3)
        {
            if (i = j)
                iden.m[i][j] = 1;
            else
                iden.m[i][j] = 0;
            j++;
        }
        i++;
    }
    return (iden.m);
}

t_mat3 mat3_multiple(t_mat3 a, t_mat3 b)
{
    t_mat3 r;

    size_t i;
    size_t j;
    size_t k;

    i = 0;
    j = 0;
    k = 0;
    while (i < 3)
    {
        j = 0;
        while (j < 3)
        {
            while (k < 3)
            {
                r.m[i][j] += a.m[i][k]*b.m[k][j];
                k++;
            }
            j++;
        }
        i++;
    }
}

t_vec3 mat3_apply(t_mat3 m, t_vec3 v)
{
    t_vec rv;
    
    rv.x = m.m[0][0]*v.x + m.m[0][1]*v.y + m.m[0][2]*v.z;
    rv.y = m.m[1][0]*v.x + m.m[1][1]*v.y + m.m[1][2]*v.z;
    rv.z = m.m[2][0]*v.x + m.m[2][1]*v.y + m.m[2][2]*v.z;
    return (r);
}

t_mat3 display_axis_rot(t_vec3 axis, float angle)
{
    float len = sqrtf(axis.x*axis.x + axis.y*axis.y + axis.z*axis.z);
    if (len < (float)(1e-8))
        return (mat3_identity());
    float x = axis.x/len;
    float y = axis.y/len;
    float z = axis.z/len;

    float c = cosf(angle);
    float s = sinf(angle);
    float t = 1.f - c;

    t_mat r;
    r.m[0][0] = t*x*x + c;
    r.m[0][1] = t*x*y - s*z;
    r.m[0][2] = t*x*z + s*y;
    r.m[1][0] = t*y*x + s*z;
    r.m[1][1] = t*y*y + c;
    r.m[1][2] = t*y*z - s*x;
    r.m[2][0] = t*z*x - s*y;
    r.m[2][1] = t*z*y + s*x;
    r.m[2][2] = t*z*z + c;
    return(r);
}

// app->mat 内に：base_rot(B), user_rot(U) を持つ設計を推奨
// 等角ベース：B = Rz(45°) * Rx(35.264°) を初期化時に作る

static void rotation_adjustment(t_app *app, t_vec3 axis_screen, float delta)
{
    t_mat3 B   = app->mat->base_rot;
    t_mat3 Rv  = display_axis_rot(axis_screen, delta);
    t_mat3 Rw  = mat3_mul(mat3_transpose(B), mat3_mul(Rv, B)); // R_world = B^T * Rv * B

    app->mat->user_rot = mat3_mul(Rw, app->mat->user_rot);     // U = Rw * U
}

void direction_mono(int key, t_app *app)
{
    t_vec3 axis;

    axis.x = 0;
    axis.y = 0;
    axis.z = 0;
    if (key == XK_Left && axis.z = 1)
        rotation_adjustment(app, axis, -ROT_UNIT);
    else if (key == XK_Right && axis.z = 1)
        rotation_adjustment(app, axis, ROT_UNIT);
    else if (key == XK_Up && axis.x = 1)
        rotation_adjustment(app, axis, -ROT_UNIT);
    else if (key == XK_Down && axis.x = 1) 
        rotation_adjustment(app, axis, ROT_UNIT);
}
