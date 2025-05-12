/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <bduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:21:14 by bduval            #+#    #+#             */
/*   Updated: 2025/05/11 09:52:45 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "libft.h"
# include "get_next_line.h"
# include "mlx.h"
# include "defines.h"
# include "typedefs.h"

# include <unistd.h>
# include <stdio.h>
# include <X.h>

//mlx
int	set_mlx(t_all *mlx);
int	free_mlx(t_all *mlx);
int	set_mlx_events(t_all *mlx);
int	start_mlx_loop(t_all *all);

//parsing
int	parse_map(int ac, char **av, t_all *all);
int	split_set(char ***dest, const char *line, const char *set);
int	parse_amb_light(char **param, t_scene *scene, char *unique);
int	parse_light(char **param, t_scene *scene, char *unique);
int	parse_cam(char **param, t_scene *scene, char *unique);
int	parse_object(char **param, t_scene *scene);

//error
int	error(char *str);
int	print_error(char *str);
int	print_error2(char *err1, char *err2);

//utils
int	free_strs(char **strs);


#endif
