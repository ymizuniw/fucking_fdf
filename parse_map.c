#include "fdf.h"

void set_map_3d(t_app *app, t_parse_list *head)
{
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

void close_free_exit(int fd, t_app *app, t_parse_list *head, const char *msg)
{
    wclose(fd);
    free_parse_list(head);
	free_all_rscs(app, msg);
    perror_exit("fatal! parse_map failed.");
}

void parse_map(const char *map_path, t_app *app)
{
    int fd;
    fd = wopen(map_path);

    t_parse_list *head;
    
    head = alloc_head();
    if (!head)
        close_free_exit(fd, app, head, "malloc head failed\n");
    if (!get_int_array_list(head, fd))
        close_free_exit(fd, app, head, "get_int_array_list failed\n");
    wclose(fd);
    alloc_maps(app, head);
    set_map_3d(app, head);
    free_parse_list(head);
}
