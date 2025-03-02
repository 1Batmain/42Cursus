#include "fdf.h"

unsigned int	value(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	if (c >= 'a' && c <= 'f')
		return (10 + c - 'a');
	if (c >= 'A' && c <= 'F')
		return (10 + c - 'A');
	return (0);
}

unsigned int	ft_atoifromhex(char *data)
{
	unsigned int	nbr;
	int				i;

	i = 0;
	nbr = 0;
	while (data[i])
	{
		nbr += value(data[i]);
		if (data[i + 1])
			nbr *= 16;
		i++;
	}
	return (nbr);
}

void	extract_values_to(t_map *map, char *data, int x, int y)
{
	map->point[x + y * map->width].x = x;
	map->point[x + y * map->width].y = y;
	map->point[x + y * map->width].z = (double)ft_atoi(data);
	if (map->point[x + y * map->width].z > map->depth)
		map->depth = ABS(map->point[x + y * map->width].z);
	while (is_digit(*data))
		data++;
	if (*data == ',')
	{
		data += 3;
		map->point[x + y * map->width].color = ft_atoifromhex(data);
	}
	else
		map->point[x + y * map->width].color = 0xFFFFFF;
	return ;
}

t_point	*add_points(t_point **og, int og_len, int add_len)
{
	t_point	*temp;
	int		i;

	temp = (t_point *)malloc((og_len + add_len) * sizeof(t_point));
	if (!temp)
		return (ft_printf("Erreur Malloc t_point\n"), NULL);
	ft_bzero(temp, og_len + add_len * sizeof(t_point));
	i = 0;
	while (i < og_len)
	{
		temp[i].x = (*og)[i].x;
		temp[i].y = (*og)[i].y;
		temp[i].z = (*og)[i].z;
		temp[i].color = (*og)[i].color;
		i++;
	}
	*og = temp;
	return (temp);
}

int	update(t_map *map, char *line)
{
	static int	y;
	int			x;
	char		**split;

	split = ft_split((const char *)line, ' ');
	x = -1;
	while (split[++x])
		;
	if (!map->width)
		map->width = x;
	else
		x = map->width;
	if (!add_points(&map->point, y * x, x))
		return (1);
	x = -1;
	while (split[++x])
	{
		extract_values_to(map, split[x], x, y);
		free(split[x]);
	}
	free(split);
	y++;
	map->height = y;
	return (0);
}

int	extract_map(char *path, t_map *map)
{
	char	*line;
	int		fd;

	map->width = 0;
	map->height = 0;
	map->depth = 0;
	fd = open(path, O_RDONLY);
	if (fd > 0)
	{
		line = get_next_line(fd);
		while (line)
		{
			if (update(map, line))
				return (free(line), 1);
			free(line);
			line = get_next_line(fd);
		}
		free(line);
	}
	return (0);
}
