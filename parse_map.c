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

void alloc_maps(t_app *app, t_parse_list *head)
{
    head = head->next;
    if (head == NULL)
        free_and_exit();
   //width
   app->map->width = get_map_width(head->int_array);
   //height
   app->map->height = get_map_height(head);
   app->map->map_size = app->map->width * app->map->height;
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

int wopen(const char *path)
{
    int fd;

    fd = open(path, O_RDONLY);
    if (fd < 0)
        perror_exit();
    return (fd);
}

void wclose(int fd)
{
    if (close(fd) < 0)
        perror_exit("close");
}

//assure that head is non-null ptr
t_parse_list *alloc_head()
{
    t_parse_list *head;

    head = malloc(sizeof(t_parse_list));
    if (head == NULL)
        return (NULL);
    head->int_array = NULL;
    head->next = NULL;
    return (head);
}

void parse_map(const char *map_path, t_app *app)
{
    int fd;
    fd = wopen(map_path);

    t_parse_list *head;
    
    head = alloc_head();
    if (!head)
        close_free_exit();
    if (get_int_array_list(head, fd) < 0)
        close_free_exit();
    wclose(fd);
    alloc_maps(app, head);
    set_map_3d(app, head);
}

static void centering_screen(t_map_2d *ptr, t_app *app)
{
    ptr->x += (float)(app->img->img_width * 0.5f) + app->mat->pan_x;
    ptr->y += (float)(app->img->img_height * 0.5f) + app->mat->pan_y;
}

//convert 3d vector to 2d
void	convert_map(t_app *app)
{
	size_t	i;

	i = 0;
	while (i < app->map->map_size)
	{
		app->map->map_2d[i] = convert_points(app->map->map_3d[i], app->map->mat);
        centering_screen(&app->map->map_2d[i], app);
		app->map->map_2d[i].color = app->map->color;
		i++;
	}
}

void	prepare_map(char *argv, t_app *app)
{
    parse_map((const char *)argv, app);
    convert_map(app);
}
