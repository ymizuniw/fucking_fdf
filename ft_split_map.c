#include "includes/fdf.h"

static size_t	count_elem(char *s)
{
	size_t	i;
	size_t	j;
	size_t	count;

	i = 0;
	j = 0;
	count = 0;
	while (s[i] && s[i] != '\n')
	{
		if (ft_isdigit(s[i]) != 1)
			return (0);
		while (ft_isdigit((unsigned char)s[i]))
			i++;
		count++;
		if (s[i] == ' ')
		{
			i++;
			if (ft_isdigit(s[i]) != 1)
				return (0);
		}
		else if ((s[i] != '\0') && (s[i] != '\n'))
				return (0);
	}
	return (count);
}

// why cast to long?
static int	get_num(char *s, size_t start, size_t end)
{
	long	res;

	res = 0;
	while (end > start)
	{
		res = res * 10 + s[start] - '0';
		start++;
	}
	return ((int)res);
}

static int element_validation(t_split_map *smap, char *s, size_t count)
{
	if (smap->j < count)
	{
		if (s[smap->i] != ' ')
			return (-1);
		smap->i++;
	}
	else
	{
		if (!(s[smap->i] == '\n' || s[smap->i] == '\0'))
			return (-1);
	}
	return (1);
}

static void init_s_smap(t_split_map *smap)
{
	smap->i = 0;
	smap->j = 0;
	smap->start = 0;
	smap->end = 0;
}

static int	*split_map(int *res, char *s, size_t count)
{
	t_split_map smap;

	init_s_smap(&smap);
	while (smap.j < count)
	{
		if (s[smap.i] == ' ')
			smap.i++;
		smap.start = smap.i;
		while (ft_isdigit(s[smap.i]))
			smap.i++;
		smap.end = smap.i;
		res[smap.j] = get_num(s, smap.start, smap.end);
		smap.j++;
		if (element_validation(&smap, s, count) < 0)
			return (NULL);
	}
	res[count] = INT_MIN;
	return (res);
}

int	*ft_split_map(char *s)
{
	size_t	count;
	int		*res;

	count = 0;
	count = count_elem(s);
	res = malloc(sizeof(int) * (count + 1));
	if (!res)
		return (NULL);
	res = split_map(res, s, count);
	return (res);
}
