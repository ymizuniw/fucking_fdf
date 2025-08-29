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

重要なのは、このアルゴリズム内においては、各判定式に於いてdx1 = 1が守られることである。生じる増加量は常に、直線の情報として与えられている固定数の(dy/dx) * 1である。よって、まず err_unit = dy/dxと定義する。両辺に2dxを掛けて、2dx * err_unit = 2dyとなり、err_unit = 2dyと再定義する。

err_unit = 2dyは、毎回のループでerr として蓄積される。このerrが無変換時の0.5を超える時にy++;という処理を入れる。
この相当する正数の値が分かっていない気がする。
⇛等式変換に従い、この正数はdxであると分かる。このdxは、ループ内のsの増加量のことではなく、ループに入る前に求めた(x1 - x0)のことである。

判定式：2dy > dx
このとき、err1 = 2dy - dxとおくと、
判定式:err1 > 0
と表される。
									終


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
