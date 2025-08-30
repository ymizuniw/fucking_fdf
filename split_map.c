#include <includes/fdf.h>	
    
    static size_t count_elem(char *s)
	{
		size_t i = 0;
		size_t j = 0;
		size_t count = 0;

		while (s[i])
		{
			if (s[i] == ' ')
				i++;
			if (!s[i])
				break ;
			//why cast to unsigned char			if (!ft_isdigit((unsigned char)s[i]))
				return (0);
			while (ft_isdigit((unsigned char)s[i]))
				i++;
			if (s[i] && s[i] != ' ')
				i++;
			count++;
		}
		return (count);
	}

	//why cast to long?
	static int get_num(char *s, size_t start, size_t end)
	{
		long res;

		res = 0;
		while (end > start)
		{
			res = res * 10 + s[start] - '0';
			start++;
		}
		return ((long)res);
	}

	static int *split_map(int *res, char *s, size_t count)
	{
		size_t i = 0;
		size_t j = 0;
		size_t start = 0;
		size_t end = 0;

		while (j < count)
		{
			if (s[i] == ' ')
				i++;
			start = i;
			while (ft_isdigit(s[i]))
				i++;
			end = i;
			res[j] = get_num(s, start, end);
			j++;
		}
		res[i] = 0;
		return (res);
	}

	int *ft_split_map(char *s)
	{

		size_t count = 0;
		int *res;

		count = count_elem(s)
		res = malloc(sizeof(int) * count);
		if (!res)
			return (NULL);
		res = split_map(res, s, count);
		return (res);
	}
