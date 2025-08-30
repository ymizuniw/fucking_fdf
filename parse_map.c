// #include "fdf.h"

// //parse given map to int double array.
// //the width and height should be set to a structure.
// void initialize_map_info(t_map_info *map_info)
// {
//  map_info->width = 0;
//  map_info->height = 0;
// }

// void w_parse_map(char *map_file, char **map_orig, t_map_info *map_info)
// {
//  map_orig = parse_map(map_file, map_info);
//  if (!map_orig)
//  {
//      ft_putstr_fd("Error: Failed to parse map.\n", 2);
//      exit(EXIT_FAILURE);
//  }
// }

// int  **parse_map(char *map, t_map_info *map_info)
// {
//  int     fd;
//  t_list  *map_list;
//  char    *line;
//  int     **parsed_map;
//  size_t  i;
//  char    **row;
//  t_list  *cur;
//  size_t  j;

//  fd = wopen(map);
//  map_list = NULL;
//  while (true)
//  {
//      line = get_next_line(fd);
//      if (!line)
//          break ;
//      ft_lstadd_back(&map_list, ft_lstnew(line));
//  }
//  map_info->height = ft_lstsize(map_list);
//  map_info->width = 0;
//  if (map_list)
//      map_info->width = ft_count_word((char *)map_list->content, ' ');
//  parsed_map = ft_calloc(map_info->height + 1, sizeof(int *));
//  if (!parsed_map)
//      return (NULL);
//  i = 0;
//  cur = map_list;
//  while (cur)
//  {
//      row = ft_split((char *)cur->content, ' ');
//      parsed_map[i] = ft_calloc(map_info->width + 1, sizeof(int));
//      j = 0;
//      while (j < map_info->width)
//          parsed_map[i][j] = ft_atoi(row[j++]);
//      free_double_array(row);
//      cur = cur->next;
//      i++;
//  }
//  ft_lstclear(&map_list, free);
//  return (parsed_map);
// }

// size_t   ft_count_word(char *s, char delim)
// {
//  char    *tmp;
//  size_t  count;

//  tmp = s;
//  count = 0;
//  while (*tmp)
//  {
//      while (*tmp == delim)
//          tmp++;
//      if (*tmp && *tmp != delim)
//          count++;
//      while (*tmp && *tmp != delim)
//          tmp++;
//  }
//  return (count);
// }

// void free_double_array(char **row)
// {
//  size_t  i;

//  i = 0;
//  while (row[i])
//      free(row[i++]);
//  if (row)
//      free(row);
// }

typedef struct s_parse_list
{
   int             *int_array;
   struct s_parse  *next;
} t_parse_list;

int add_int_array(t_parse_list *head, int *int_array)
{
   t_parse_list *new;
  
   if (!head || !int_array)
       return (-1);
   new = malloc(sizeof(t_parse_list));
   if (!new)
       return (-1);
   while (head && head->next)
       head = head->next;
   new->int_array = int_array;
   new->next = NULL;
   head->next = new;
   return (0);
}

t_parse_list *alloc_head(void)
{
   t_parse_list *head;

   head = malloc(sizeof(t_parse_list));
   if (head == NULL)
       return (NULL);
   head->int_array = NULL;
   head->next = NULL;
   return (head);
}

t_parse_list *get_int_array_list(t_parse_list *head)
{
   char    *line;
   int     *int_array;

   while (1)
   {
       line = get_next_line();
       if (NULL)
           break ;
       //split line in to int array
       int_array = split_line(line);
       if (add_int_array(head, int_array) < 0)
           return (-1);
   }
   return (head);
}

size_t count_elems(int *int_array)
{
   size_t count;

   count = 0;
   while (int_array[count])
       count++;
   return (count);
}

size_t lst_size(t_parse_list *head)
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

//if this return -1, calling side will free app and exit.
int alloc_map_3d(t_app *app, t_parse_list *head)
{
   //width
   app->map->width = count_elems(head->int_array);
   //height
   app->map->height = lst_size(head);
   //set map 3d
   app->map->map_3d = malloc(sizeof(t_map_3d) * (app->map->width * app->map->width));
   if (!app->map->map_3d)
       return (free_map(), -1);
}

void set_map_3d(t_app *app, int *int_array)
{
   //parse map blue print
   size_t y = 0;
   size_t i = 0;
   size_t line_len = 0;

   y = 0;
   //line1
   while (y < app->map->height)
   {
       i = 0;
       while (i < app->map->width && int_array[i])
           app->map->map_3d[y + i] = int_array[i++];
       y++;
   }
}
