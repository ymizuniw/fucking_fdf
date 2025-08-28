#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// void hello(void)
// {
//     printf ("Hello, World!\n");
// }

// int main(void)
// {
//     void (*f_ptr)(void) = hello;
//     f_ptr();
// }

// void greet(const char *name)
// {
//     printf("Hello, %s!\n", name);
// }

// int main(void)
// {
//    void (*fp)(const char *) = greet;
//    fp("Malice");
// }

// int add(int a, int b)
// {
//     return (a + b);
// }

// int main(int argc, char **argv)
// {
//     int (*fp)(int, int) = add;
//     int a = argv[1][0] - '0';
//     int b = argv[2][0] - '0';
//     printf("%d\n", add(a, b));
// }

// void f1(void){ printf ("F1\n"); }
// void f2(void){ printf ("F2\n"); }
// void f3(void){ printf ("F3\n"); }

// int main(void)
// {
//     void (*fps[3])(void);
//     fps[0] = f1;
//     fps[1] = f2;
//     fps[2] = f3;
//     for (int i = 0; i < 3; i++)
//         fps[i]();
// }

// void close(){printf("close\n");}
// void pan_left(){printf("pan_left\n");}
// void pan_right(){printf("pan_right\n");}
// void pan_up(){printf("pan_up\n");}
// void pan_down(){printf("pan_down\n");}
// void rotate_x(){printf("rotate_x\n");}
// void rotate_y(){pritnf("rotate_y\n");}
// void rotate_z(){printf("rotate_z\n");}

// int main(void)
// {
//     void (*actions[8])(void);
//     actions[0] = close;
//     actions[1] = pan_left;
//     actions[2] = pan_right;
//     actions[3] = pan_up;
//     actions[4] = pan_down;
//     actions[5] = rotate_x;
//     actions[6] = rotate_y;
//     actions[7] = rotate_z;
// }

// //a < b
// int cmp_asc(const void *a, const void *b)
// {
//     return (*(int *)a - *(int *)b);
// }
// //a > b
// int cmp_desc(const void *a, const void *b)
// {
//     return (*(int *)b - *(int *)a);
// }

// int main(void)
// {
//     int arr[] = {2,0,9,3};
//     size_t len = sizeof(arr) / sizeof(arr[0]);
//     qsort(arr, len, sizeof(int), cmp_asc);
//     for (int i = 0; i < len; i++)
//         printf("%d ", arr[i]);
// }

// void    for_each(int *arr, int len, void (*f)(int))
// {
//     for (int i = 0; i < len; i++)
//         f(arr[i]);
// }

// void print_val(int x){ printf("%d\n", x); }

// int main(void)
// {
//     int nums[] = {20, 40, 90};
//     for_each(nums, 3, print_val);
// }

// typedef struct s_app{
//     int x, y;
//     void (*on_move)(struct s_app *, int, int);
// } t_app;

// void    move(t_app *app, int dx, int dy)
// {
//     app->x += dx;
//     app->y += dy;
//     printf("Moved to (%d, %d)\n", app->x, app->y);
// }

// int main(void)
// {
//     t_app app = {0, 0, move};
//     app.on_move(&app, 5, 3);
// }

// #include <stdarg.h>

// void log_msg(const char *fmt, ...)
// {
//     va_list ap;
//     va_start(ap, fmt);
//     vprintf(fmt, ap);
//     va_end(ap);
// }

// int main(void)
// {
//     void (*logger)(const char *, ...) = log_msg;
//     logger("Value: %d, %s\nTest: %d, %s\n", 42, "Hello", 24, "Coding");
// }

typedef int (*math_f)(int, int);

int add(int a, int b){ return a+b; }
int sub(int a, int b){ return a-b; }

math_f get_op(char op)
{
    if (op == '+')
        return add;
    if (op == '-')
        return sub;
    return NULL;
}

int main(void)
{
    math_f f = get_op('+');
    if (f)
        printf("%d\n", f(3,4));
}
