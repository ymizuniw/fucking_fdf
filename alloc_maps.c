#include "includes/fdf.h"

//termination should be with -1 or other negative num.
static size_t get_map_width(int *int_array)
{
   size_t count;

   count = 0;
   while (int_array[count] != INT_MIN)
       count++;
   return (count);
}

static size_t get_map_height(t_parse_list *head)
{
   size_t size;

   size = 0;
   while (head)
   {
       size++;
       head = head->next;
   }
   return (size);
}

static void free_and_exit(char *msg, t_app *app)
{
    perror(msg);
    if (app->mat)
		free(app->mat);
	free_map(app);
    exit(EXIT_FAILURE);
}

void alloc_maps(t_app *app, t_parse_list *head)
{
    head = head->next;
    if (head == NULL)
        free_and_exit(MALLOC_FAILURE, app);
   app->map->width = get_map_width(head->int_array);
   app->map->height = get_map_height(head);
   app->map->map_size = app->map->width * app->map->height;
   app->map->map_3d = malloc(sizeof(t_map_3d) * (app->map->map_size));
   if (!app->map->map_3d)
        free_and_exit(MALLOC_FAILURE, app);
    app->map->map_2d = malloc(sizeof(t_map_2d) * (app->map->map_size));
    if (!app->map->map_2d)
        free_and_exit(MALLOC_FAILURE, app);
}
