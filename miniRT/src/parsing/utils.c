/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <bduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 07:19:18 by bduval            #+#    #+#             */
/*   Updated: 2025/05/17 09:44:39 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_get_color(int *dest, char **param)
{
	int		i;
	char	*color;

	color = (char *)dest;
	i = 3;
	while (i >= 0)
	{
		if (param[i])
			color[i] = ft_atoi(param[i]);
		else
			color[i] = 0;
		i--;
	}
	return (0);
}

static int	integer_part_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len] && str[len] != '.')
		len++;
	return (len);
}

int	is_normalized(double n)
{
	if(n < -1 || n > 1)
		return (0);
	return (1);
}

//TODO THIS IS NOT WORKING WELL
int	ft_is_double(const char *str)
{
	int	i;
	int	one_dot;
	int	len;

	while (*str == '-' || *str == '+')
		str++;
	len = integer_part_strlen(str);
	if (len > 309)
		return (0);
	i = 0;
	one_dot = 0;
	while (str[i] && str[i] != '.')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		if (len == 309 && i < 20 && str[i] > STR_DOUBLE_MAX_20_FIRST[i])
			return (0);
		i++;
		if (!one_dot && str[i] == '.' && ++i)
			one_dot = 1;
		else if (one_dot && str[i] == '.')
			return (0);
	}
	return (1);
}

int	ft_is_char(const char *str)
{
	int	len;
	int	i;

	len = ft_strlen(str);
	if (len > 3)
		return (0);
	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		if (len == 3 && str[i] > STR_CHAR_MAX[i])
			return (0);
		i++;
	}
	return (1);
}
