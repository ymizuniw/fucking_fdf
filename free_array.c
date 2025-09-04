#include "fdf.h"

void	free_points_array(t_point **p)
{
	size_t	k;

	k = 0;
	while (p[k])
		free(p[k++]);
	free(p);
}

void	free_char_ptr_array(char **s)
{
	size_t	k;

	k = 0;
	while (s[k])
		free(s[k++]);
	free(s);
}
