#include "fdf.h"

// parse given map to int double array.
//the width and height should be set to a structure.
typedef struct s_map_info
{
	size_t	height;
	size_t	width;
} t_map_info;

int	**parse_map(char *map)
{
	int		fd;
	t_list	*map_list;
	char	*line;
	int		**parsed_map;
	size_t	i;
	char	**row;
	t_list	*cur;
	size_t	j;
	t_map_info map_info;

	fd = wopen(map);
	map_list = NULL;
	while (true)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		ft_lstadd_back(&map_list, ft_lstnew(line));
	}
	map_info->height = ft_lstsize(map_list);
	map_info->width = 0;
	if (map_list)
		map_info->width = ft_count_word((char *)map_list->content, ' ');
	parsed_map = ft_calloc(map_info->height + 1, sizeof(int *));
	if (!parsed_map)
		return (NULL);
	i = 0;
	cur = map_list;
	while (cur)
	{
		row = ft_split((char *)cur->content, ' ');
		parsed_map[i] = ft_calloc(map_info->width + 1, sizeof(int));
		j = 0;
		while (j < width)
			parsed_map[i][j] = ft_atoi(row[j++]);
		free_double_array(row);
		cur = cur->next;
		i++;
	}
	ft_lstclear(&map_list, free);
	return (parsed_map);
}

size_t	ft_count_word(char *s, char delim)
{
	char	*tmp;
	size_t	count;

	tmp = s;
	count = 0;
	while (*tmp)
	{
		while (*tmp == delim)
			tmp++;
		if (*tmp && *tmp != delim)
			count++;
		while (*tmp && *tmp != delim)
			tmp++;
	}
	return (count);
}

void	free_double_array(char **row)
{
	size_t	i;

	i = 0;
	while (row[i])
		free(row[i++]);
	if (row)
		free(row);
}