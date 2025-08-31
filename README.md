//そもそもコンセプトの理解に問題があった。例として提示されたモデルを見てみると、普通に点と点を繋いでおり、幅のあるオブジェクトを表示できるようにするのはマップ側の役割だ。
なので、処理の流れは簡潔に、

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
