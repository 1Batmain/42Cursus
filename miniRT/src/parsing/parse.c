/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <bduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 11:45:17 by bduval            #+#    #+#             */
/*   Updated: 2025/05/16 19:53:28 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	turntable(char **line, t_scene *scene)
{
	static char	unique;

	if (!line || !*line || !ft_strncmp(*line, "\n", 1))
		return (0);
	if (!ft_strcmp(*line, "A"))
		return (parse_amb_light(line, scene, &unique));
	else if (!ft_strcmp(*line, "C"))
		return (parse_cam(line, scene, &unique));
	else if (!ft_strcmp(*line, "L"))
		return (parse_light(line, scene, &unique));
	else if (!ft_strcmp(*line, "sp"))
		return (parse_sphere(line, scene));
	else if (!ft_strcmp(*line, "pl"))
		return (parse_plane(line, scene));
	else if (!ft_strcmp(*line, "cy"))
		return (parse_cylinder(line, scene));
	else
		return (PERROR2(*line, "is not a valid identifier"));
	return (0);
}

static int	read_and_orient(char *path, t_all *all)
{
	int		fd;
	char	*line;
	char	**split;
	int		err;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (PERROR2("Can't find the file", path));
	line = (char *)1;
	err = 0;
	while (line && !err)
	{
		line = get_next_line(fd);
		if (line && *line)
		{
			split = NULL;
			if (split_set(&split, line, SPLIT))
				return (error("split_spaces()"));
			err = turntable(split, all->scene);
			free_strs(split);
		}
		free(line);
	}
	close(fd);
	return (err);
}

int	parse_map(int ac, char **av, t_all *all)
{
	if (ac != 2 || ft_strlen(av[1]) < 3
		|| ft_strncmp(&av[1][ft_strlen(av[1]) - 3], ".rt", 3))
		return (PERROR(ERROR_ARGUMENTS));
	all->scene = ft_calloc(1, sizeof(t_scene));
	if (!all->scene)
		return (ERROR("allocating scene"));
	if (read_and_orient(av[1], all))
		return (-1);
	return (0);
}
