1.parse 3d map
2.set 2d vector (rotation and isometric projection)
3.set pixel buffer ()
4.flush buffer

a.keyevents should delegate operation to rotation matrix function
b.initialize and destrory mlx_ objects, and free all memory allocated variables and structures.
c.gresp the whole structure and usage of mlx unique functions, what are given as argments, how does it work.

---

## // Data Structure

これまでのところ、アプリケーション全体を表す `s_app`、描画対象のデータを格納する `s_img`、
1ピクセルごとの情報を格納する `s_pixel`、および `s_pixel` を連結して連続した描画情報を保持する `s_pixel_buffer` を定義している。
これにより、マップ情報の格納から描画情報の蓄積までを統一的に処理できるかを検証する。

// Img Size

また、このimg はwindow 内において左上から表示されるため、画面の中心に表示されるように初期化するには、
二次元座標への変換後（なぜなら、二次元の画面に描画されるのはこの座標に沿った線である）に全ての成分に画面中心へのオフセットを加算する。その式は、以下のようになる。

offset_x = (window_width - map_width) / 2;
offset_y = (window_height - map_height) / 2;

window_width - map_width = both sides space of the picture below. Deviding this by 2 is the value of one side space.

 --------------
|              |
|    ------    |
|   |      |   |
|    ------    |
|              |
 --------------

proj_x = cur_x + offset_x;
proj_y = cur_x + offset_y;


//pixel_buffer flush event
キーイベントに登録された回転単位の変換が終り次第画面クリアー＞再描画


//Thought about pixel information mermory allocation.
the data structure is maybe like,
img->img_ptr
pixel_color {1, 2, 3, 4, ... , N};
the color unit size is (img->bits_per_pixel / 8).
x++ and everytime y reaches size_line, it will be incremented,
and x is reset to 0.
the reason dst should be casted to *(unsigned int *) is,
the content size is img->bits_per_pixel / 8 (bytes).
bits_per_pixel is usually 4 bytes, but it differ if we use small endian.

//Bresenham's algorithm の解説。
長軸を主軸とすることで、直線の傾きが1未満になる。
傾きに従い、分母が1ピクセル増加したときの分子の増加量を誤差として蓄積する。
蓄積した誤差が分母1として0.5以上であれば、分子を1ピクセル増やし、誤差を分子1ピクセル分だけ調整する。
この際、0.5は小数であり整数を単位とするピクセルを扱うには不適当なので、スケーリングして整数で扱う。
スケーリングは、次のように行う。

ステップバイステップで、傾きの式を調整しながら誤差の変化を見ていく。主軸の交換と符号の管理は入れていない。

0.
delta = dy/dx
閾値：0.5
x += 1
err += dy/dx
if (0.5 <= err)
	y++; err -= 1;

1.
delta * dx = dy
閾値：0.5dx
x += 1
err += dy
if (0.5dx <= err)
	y++; err -= dx;

2.
delta * dx * 2 = 2 * dy
閾値：dx
x += 1
err += 2 * dy
if (dx <= err)
	y++; err -= 2 * dx;

//回転角度のラップ
回転角を（-PI <=　θ　< PI）に収めることをWrap, 正規化と言う。
//if angle is larger than pi, -2pi,
//else if angle is smaller than -pi, +2pi
//therefore, use while loop to increment/decrement to the range of -pi<theta<pi.

int pos = (y * size_line + x * (bits_per_pixel / 8))

この等式は、メモリのオフセットを計算し、xy座標上の特定のピクセルにアクセスするために必要になる。
size_line は、一行あたりのbytesであり、連続するメモリアドレスに於いては、これがy座標分移動するから、
y * size_line = y_place　である。抽象的なイメージを述べておくと、y * size_line は常にrawの先頭を指すポインタのアドレスである。そこからx * bytes_perpixelだけメモリを移動すると、x * memory_ptrとなる。

図式化してみると、

↓列先頭は、(arr + 10 * n)で示される。
arr[1], arr[2], arr[3],,,arr[10]
arr[11], arr[12], arr[13],,,
...

bits_per_pixel / 8　は、１ピクセルあたりのbit数を、byte 単位に変換する式である。
これらから、
pos = y * size_line + x * bytes_per_pixel
によって参照したいピクセルのポインタが得られる。

//mlx_hook, mlx_key_hook, mlx_loop()　の処理の流れ

すべてのイベント処理関数を登録し、その後にloopを開始することで、mlx_loop_end()が呼ばれるか、
プログラムが終了するまでイベントリスナーが開かれた状態になる。



<LINE DRAWING ALGORITYM>
//run on the map_2d and set two points to connect with wire for put_pixel function.

// o -- o -- o -- o -- o -- o 
// |    |    |    |    |    |
// o -- o -- o -- o -- o -- o 
// |    |    |    |    |    |
// o -- o -- o -- o -- o -- o 
// |    |    |    |    |    |
// o -- o -- o -- o -- o -- o 

// map[0,0] -- map[0,1]
// |               |
// map[1,0] -- map[1,1]

// map(y,x) -- map(y, x + 1)
// |               |
// map(y + 1, x) -- map(y + 1, x + 1)

//pixel_bufferへの書き込み
//各行について隣接する点をワイヤーで接続
//各列について隣接する点をワイヤーで接続



<History>
// bool draw_map(t_img *img)
// {
// 	//draw maps
// 	//draw
// 	1. draw_lines
// 	2. draw_line
// 	//proj_3d_to_2d
// 	1. convert<proj> 3d vector to 2d vector
// display and the centre of object coordination is fixed

// //additional features for convert<proj> section.
// 	//another object
// 	1. project one more object with the same condition or light version
// 	//rotation
// 	1. rotation_matrix_multiplication to 3d vector
// 		//keys
// 			:shift click + direction key up/down/left/right
// 	//translation
// 	1. horizontal -> +x
// 	2. virtical -> +y
// 		//keys
// 		:left/right
// 		:up/down
// 	//scale
// 	1. scalar multiplication for 2d vector
// 		//keys
// 		:if it is not complex, straight forward/backward wheel.
// 		:if it is, +/-
// 	//color
// 	1. add some color to "the another object"
// 		:shift + r/g/b
// }




ロドリゲスの回転による回転の再定義。

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
金沢工業大学、ロドリゲスの回転公式」
https://w3e.kanazawa-it.ac.jp/math/physics/category/physical_math/linear_algebra/henkan-tex.cgi?target=/math/physics/category/physical_math/linear_algebra/rodrigues_rotation_matrix.html

正規直交基底についての解説。
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
