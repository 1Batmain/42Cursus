/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_atrib_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <bduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:18:07 by bduval            #+#    #+#             */
/*   Updated: 2024/12/02 16:27:37 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_specifier(char c)
{
	if (c == 'c' || c == 's' || c == 'd' || c == 'p' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

int	is_flag(char c)
{
	if (c == '-' || c == '0' || c == '.' || c == '#' || c == ' ' || c == 'u'
		|| c == '+')
		return (1);
	return (0);
}

int	is_digit(char c)
{
	if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5'
		|| c == '6' || c == '7' || c == '8' || c == '9')
		return (1);
	return (0);
}

void	ft_get_atrib(char **s, t_atrib *atrib)
{
	while (!is_specifier(**s) && **s)
	{
		if (is_flag(**s))
			get_value(s, atrib);
		else if (is_digit(**s))
			atrib->left_padding = ft_atoi(s);
	}
}

void	ft_initatrib(t_atrib *s)
{
	s->right_padding = 0;
	s->left_padding = 0;
	s->zero_padding = 0;
	s->right_on = 0;
	s->left_on = 0;
	s->zero_on = 0;
	s->precision = 0;
	s->precision_on = 0;
	s->sign = 0;
	s->space = 0;
	s->sharp = 0;
	s->signing[2] = 0;
	s->signing[1] = 0;
	s->signing[0] = 0;
	s->is_char = 0;
	s->hex = 0;
	s->c = 0;
	s->padding = 0;
	s->content = 0;
}
