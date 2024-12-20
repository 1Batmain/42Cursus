#include "fdf.h"

int	count_words(char *line)
{
	int	tem;
	int	words;

	tem = 0;
	words = 0;
	while (ft_isspace(*line))
		line++;
	while (*line)
	{
		while (!ft_isspace(*line) && *line)
		{
			tem = 1;
			line++;
		}
		while (ft_isspace(*line) || *line == '\n')
			line++;
		if (tem)
		{
			words++;
			tem = 0;
		}
	}
	return (words);
}

int	get_map_dim(char *path, t_map *map)
{
	int	fd;
	char *line;
	
	map->height = 0;
	map->width = 0;
	fd = open(path, O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		if (!map->width)
			map->width = count_words(line);
		map->height++;
	}
	close(fd);
	return (0);
}

int	init_map(t_map *map)
{
	int	**m;
	int	i;

	m = (int **)malloc(sizeof (int *) * map->height * map->width);
	if  (!m)
		return (ft_printf("Erreur malloc map\n"));
	i = 0;
	while (i < map->height * map->width)
	{
		m[i] = (int *)malloc(sizeof(int) * 3);
		if (!m[i])
		{
			while (i--)
				free(m[i]);
			free(m);
			return (ft_printf("Erreur malloc map[i]\n"));
		}
		i++;
	}
	map->map = m;
	return (0);
}

int	extract_values(char *line, int y, t_map *map)
{
	int	x;
	int p;

	x = 0;
	p = y * map->width;
	while (x < map->width)
	{
		map->map[p + x][0] = x;
		map->map[p + x][1] = y;
		map->map[p + x][2] = ft_atoi(line);
		ft_printf("(%d, %d, %d)\n", map->map[p + x][0], map->map[p + x][1],	map->map[p + x][2]);
		x++;
		while (!ft_isspace(*line) && *line)
			line++;
		while (ft_isspace(*line) || *line == '\n')
			line++;
	}
	return (0);
}

int	fill_map(char  *path, t_map *map)
{
	int		fd;
	int		y;
	char	*line;

	fd = open(path, O_RDONLY);
	y = 0;
	while ((line =  get_next_line(fd)))
		extract_values(line, y++, map);
	close(fd);
	return (0);
}

int	extract_map(char *path, t_map *map)
{
	if (!get_map_dim(path, map))
		if (!init_map(map) && !fill_map(path, map))
			return (0);
	return (1);
}
