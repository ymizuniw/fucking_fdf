#include "includes/fdf.h"

// //大きさが１の一次独立なn個のベクトルによって成り立つ。
// //|U_i| = 1 (i = 1,2...n)
// //U_i・U_j = 0 (i = 0)

// //why use
// // 一次独立な二つのベクトルb,c について、内積b・cを考える。
// // 正規直交基底であるならば、積に出てくる異なる基底ベクトルの内積が０、
// //　同じ基底ベクトルの内積は1になる。

// //how to use
// あるベクトルa1がある。
// 向きa1大きさ1 :u1 = a1 / det(a1);
// a1 に平行でないベクトルa2がある。
// a1と直交し、a2と交わるベクトルu2を考える。
// なす角をthetaとし、
// a2からa1への正射影ベクトルの長さ : |a2|cos(theta)・|u1| = a2・u1
// u2' = a2 - (a2・u1)・u1
// u2 = u2' / det(u2')

// u1, u2で張られる平面sがある。
// a1,a2に平行でないベクトルa3はこの平面の外にある。
// a3からsへの正射影は、
// 実数t,pを用いて、s*u1 + p*u2の和で表せる。

// u1方向の長さ :a3・u1
// u2方向の長さ :a3・u2
// 正射影u1方向への正射影 :(a3・u1)u1
// 正射影u2方向への正射影 :(a3・u2)u2

// u3' = a3 - (a3・u1)u1 - (a3・u2)u2

// u3 = u3' / det(u3')

// 以下同様に、
// uk' = ak - (ak・u1)u1 -(ak・u2)u2 - .... -(ak・u_k-1)u_k-1
// uk = uk' / det(u'k)
// をnまで行う。

static t_v3 init_v3(t_v3 v)
{
    v.x = 0;
    v.y = 0;
    v.z = 0;
    return (v);
}

t_v3 scl(t_v3 v, float s)
{
    v.x *= s;
    v.y *= s;
    v.z *= s;
    return (v);
}

t_v3 sub(t_v3 a, t_v3 b)
{
    t_v3 s;

    s.x = a.x - b.x;
    s.y = a.y - b.y;
    s.z = a.z - b.z;
    return (s);
}

//a x b = aybz - azby, azbx - axbz, axby - aybx;

t_v3 cross(t_v3 a, t_v3 b)
{
    t_v3 c;
    c.x = a.y*b.z - a.z*b.y;
    c.y = a.z*b.x - a.x*b.z;
    c.z = a.x*b.y - a.y*b.x;
    return (c);
}

t_v3 nrm(t_v3 v)
{
    float l2;

    l2 = dot(v,v);
    if (l2 <= 1e-8f)
        return (0);
    float inv;
    inv = 1.0f/sqrtf(l2);
    return (scl(v, inv));
}

void orthonormalization(t_mat3 *r)
{
    t_v3 a1;
    t_v3 a2;
    t_v3 proj;
    t_v3 u2_tmp;

    a1.x = r->m[0][0];
    a1.y = r->m[1][0];
    a1.z = r->m[2][0];

    a2.x = r->m[0][1];
    a2.y = r->m[1][1];
    a2.z = r->m[2][1];

    t_v3 u1;
    t_v3 u2;
    t_v3 u3;
    t_v3 u1_x_u2;

    u1 = nrm(a1);
    proj = scl(u1, dot(a2,u1));
    u2_tmp = sub(a2, proj);//a2->projのベクトル。
    u2 = nrm(u2_tmp);
    u3 = cross(u1, u2);
    
    r->m[0][0] = u1.x;
    r->m[1][0] = u1.y;
    r->m[2][0] = u1.z;
    r->m[0][1] = u2.x;
    r->m[1][1] = u2.y;
    r->m[2][1] = u2.z;
    r->m[0][2] = u3.x;
    r->m[1][2] = u3.y;
    r->m[2][2] = u3.z;
}
