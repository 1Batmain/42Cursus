/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <bduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 11:45:17 by bduval            #+#    #+#             */
/*   Updated: 2025/05/11 12:42:50 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	turntable(char **line, t_scene *scene)
{
	static char	unique;

	if (!ft_strncmp(*line, "A", 1))
		return (parse_amb_light(line, scene, &unique));
	else if (!ft_strncmp(*line, "C", 1))
		return (parse_cam(line, scene, &unique));
	else if (!ft_strncmp(*line, "L", 1))
		return (parse_light(line, scene, &unique));
	else if (!ft_strncmp(*line, "sp", 2))
		return (parse_object(line, scene));
	else if (!ft_strncmp(*line, "pl", 2))
		return (parse_object(line, scene));
	else if (!ft_strncmp(*line, "cy", 2))
		return (parse_object(line, scene));
	else
		return (print_error2(*line, "is not a valid identifier"));
	return (0);
}

static int	read_and_orient(char *path, t_all *all)
{
	int		fd;
	char	*line;
	char 	**split;
	int		err;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (error("Opening the map"));
	line = (char *)1;
	err = 0;
	while (line && !err)
	{
		line = get_next_line(fd);
		if (line && *line)
		{
			split = NULL;
			if (split_set(&split, line, SPACES))
				return (error("split_spaces()"));
			err = turntable(split, &all->scene);
			free_strs(split);
		}
		free(line);
	}
	close(fd);
	return (err);
}

int	parse_map(int ac, char **av, t_all *all)
{
	(void)all;
	if (ac != 2 || ft_strlen(av[1]) < 3
		|| ft_strncmp(&av[1][ft_strlen(av[1]) - 3], ".rt", 3))
		return (print_error(ERROR_ARGUMENTS));
	if (read_and_orient(av[1], all))
		return (-1);

	return (0);
}
