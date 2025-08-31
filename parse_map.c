#include "fdf.h"

// debug_dump_map.c
#include <stdio.h>
#include "fdf.h"

//termination should be with -1 or other negative num.
static size_t get_map_width(int *int_array)
{
   size_t count;

   count = 0;
   while (int_array[count] != INT_MIN)
       count++;
   return (count);
}

// 1) 行リスト（int配列）を表示して、パース結果を確認
void debug_dump_parsed_list(const t_parse_list *head)
{
    const t_parse_list *cur;
    size_t row = 0;

    if (!head) {
        printf("[PARSE-LIST] head == NULL\n");
        return;
    }
    cur = head->next; // ダミー先頭をスキップ

    printf("[PARSE-LIST] ---- begin ----\n");
    while (cur) {
        size_t w = get_map_width(cur->int_array); // あなたの関数を使用
        printf("row %zu (w=%zu):", row, w);
        for (size_t x = 0; x < w; x++) {
            printf(" %d", cur->int_array[x]);
        }
        printf("\n");
        cur = cur->next;
        row++;
    }
    printf("[PARSE-LIST] ----  end  ----\n");
}

// 2) map_3d を z のグリッドとして表示（元の数値と一致するかを確認しやすい）
void debug_dump_map3d(const t_app *app)
{
    if (!app || !app->map || !app->map->map_3d) {
        printf("[MAP-3D] app/map/map_3d is NULL\n");
        return;
    }

    size_t w = app->map->width;
    size_t h = app->map->height;

    printf("[MAP-3D] size=%zux%zu (total=%zu)\n", w, h, app->map->map_size);
    for (size_t y = 0; y < h; y++) {
        printf("y=%zu:", y);
        for (size_t x = 0; x < w; x++) {
            size_t i = y * w + x;
            // z を整数風に出す（元の int 配列と見比べる用途）
            printf(" %g", app->map->map_3d[i].z);
        }
        printf("\n");
    }
}

// 3) ワンコールで両方を見るためのヘルパ
void debug_show_parsed_map(const t_parse_list *head, const t_app *app)
{
    debug_dump_parsed_list(head);
    debug_dump_map3d(app);
}

//set
void set_map_3d(t_app *app, t_parse_list *head)
{
   //map_3d : 
   size_t y;
   size_t x;

   head = head->next;
   y = 0;
   while (app->map->height > y && head)
   {
        x = 0;
        size_t i;
        while (app->map->width > x)
        {
            i = y * app->map->width + x;            
            app->map->map_3d[i].z = (float)head->int_array[x];
            app->map->map_3d[i].x = (float)x;
            app->map->map_3d[i].y = (float)y;
            x++;
        }
        head = head->next;
        y++;
   }
}

//assure that head is non-null ptr
static t_parse_list *alloc_head(void)
{
    t_parse_list *head;

    head = malloc(sizeof(t_parse_list));
    if (head == NULL)
        return (NULL);
    head->int_array = NULL;
    head->next = NULL;
    return (head);
}

void close_free_exit(int fd, t_app *app, const char *msg)
{
    if (app->mat)
		free(app->mat);
	free_all_rscs(app, msg);
    wclose(fd);
    perror_exit("fatal! parse_map failed.");
}

void parse_map(const char *map_path, t_app *app)
{
    int fd;
    fd = wopen(map_path);

    t_parse_list *head;
    
    head = alloc_head();
    if (!head)
        close_free_exit(fd, app, "malloc head failed\n");
    if (!get_int_array_list(head, fd))
        close_free_exit(fd, app, "get_int_array_list failed\n");
    wclose(fd);
    debug_dump_parsed_list(head);
    alloc_maps(app, head);
    set_map_3d(app, head);
    debug_dump_map3d(app);
}
