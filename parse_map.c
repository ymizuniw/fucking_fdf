#include "fdf.h"

size_t get_map_width(int *int_array)
{
   size_t count;

   count = 0;
   while (int_array[count])
       count++;
   return (count);
}

size_t get_map_height(t_parse_list *head)
{
   size_t size;

   size = 0;
   while (head)
   {
       size++;
       if (head->next)
           head = head->next;
       else
           break ;    
   }
   return (size);
}

//get the vertical and horizontal length of the map, and malloc() the map_3d.

// Resources delt with here is : char **orig_map, t_parse_list *head, t_app *app.
// If error has occurred, release them correctly.

void alloc_maps(t_app *app, t_parse_list *head, char **orig_map)
{
   //width
   app->map->width = get_map_width(head->int_array);
   //height
   app->map->height = get_map_height(head);
   app->map->map_size = app->map->width + app->map->height;
   //set map 3d
   app->map->map_3d = malloc(sizeof(t_map_3d) * (app->map->map_size));
   if (!app->map->map_3d)
        free_and_exit();
    app->map->map_2d = malloc(sizeof(t_map_2d) * (app->map->map_size));
}

//set
void set_map_3d(t_app *app, t_parse_list *head)
{
   //map_3d : 
   size_t y;
   size_t x;

   y = 0;
   while (app->map->height > y && head)
   {
        x = 0;
        while (app->map->width > x)
        {
            app->map->map_3d[y*app->map->width + x] = head->int_array[x];
            x++;
        }
        head = head->next;
   }
}

int wopen(const char *path)
{
    int fd;

    fd = open(path, O_RDONLY);
    if (fd < 0)
        perror_exit();
    return (fd);
}

//assure that head is non-null ptr
t_parse_list *alloc_head(char *map_orig)
{
    t_parse_list *head;

    head = malloc(sizeof(t_parse_list));
    if (head == NULL)
        free_exit(map_orig);
    head->int_array = NULL;
    head->next = NULL;
    return (head);
}

void parse_map(const char *map_path, t_app *app)
{
    int fd;
    char **map_orig = ft_split_map(map);
    if (map_orig == NULL)
        free_close_and_exit();
    fd = wopen(map_path);

    t_parse_list *head;
    
    head = alloc_head(map_orig);
    get_int_array_list(head, fd);
    alloc_map_3d(app, head, map_orig);
    set_map_3d(app, head);
}

//convert 3d vector to 2d
void	convert_map(t_app *app)
{
	size_t	i;

	i = 0;
	while (i < app->map->map_size)
	{
		app->map->map_2d[i] = convert_points(app->map->map_3d[i], app->map->mat);
		app->map->map_2d[i].color = app->map->color;
		i++;
	}
}

void	prepare_map(char *argv, t_app *app)
{
    parse_map((const char *)argv, app);
    convert_map(app);
}
