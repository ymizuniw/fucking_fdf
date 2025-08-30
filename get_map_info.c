#include <includes/fdf.h>

		static t_list *lst_alloc(int fd)
		{
			t_list *new;
			new = malloc(sizeof(t_list));
			if (!new)
			{
				close (fd);
				ft_putstr_fd("list malloc failed\n", 2);
				return (NULL);	
			}
			return (new);
		}

		static void set_list(t_list *head, t_app *app, int fd)
		{
			t_list *tail;
			char *line;

			while (1)
			{
				line = get_next_line(fd);
				if (line == NULL)
					break ;
				if (app->map->height == 0)
					cur->line = line;
				else
				{
					tail = lst_alloc(fd);
					if (tail == NULL)
						free_map_exit(app);
					tail->line = line;
					cur->next = tail;
				}
				app->map->height++;
			}
		}

	t_list *get_map_info(t_app *app, int fd)
	{
		char *line;
		t_list *head;
		t_list *cur;
		size_t count;

		head = malloc(sizeof(t_list));
		if (!head)
		{
			close (fd);
			ft_putstr_fd("list malloc failed\n", 2);
			return (-1);
		}
		set_list(head, app, fd);
		return (head);
	}
