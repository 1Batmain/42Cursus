/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <bduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:55:10 by bduval            #+#    #+#             */
/*   Updated: 2025/05/08 10:41:10 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_get_lengths(t_atrib *a, size_t *len, size_t *len_pad)
{
	*len = ft_special_strlen(a->content);
	*len += ft_special_strlen(a->signing);
	if (a->is_char)
		*len = 1;
	*len_pad = 0;
	if (a->right_padding > *len && ++(a->right_on))
		*len_pad = a->right_padding - *len;
	else if (a->left_padding > *len && ++(a->left_on))
		*len_pad = a->left_padding - *len;
	else if (a->zero_padding > *len && ++(a->zero_on))
		*len_pad = a->zero_padding - *len;
}

size_t	ft_print_buff(char err, t_atrib *a)
{
	size_t	len;
	size_t	len_pad;

	if (err)
		return (0);
	ft_get_lengths(a, &len, &len_pad);
	if (len_pad)
	{
		if (!(ft_init_buf(&(a->padding), len_pad + 1)))
			return (0);
		if (a->zero_on)
			ft_memset(a->padding, '0', len_pad);
		else
			ft_memset(a->padding, ' ', len_pad);
	}
	ft_put_atrib(a);
	return (len + len_pad);
}

size_t	ft_print_arg(const char **c, va_list args, t_atrib *atrib)
{
	if (**c == '%' && (*c)++)
		return (ft_putchar('%'));
	else if (**c == 'c' && (*c)++)
		return (ft_print_buff(ft_tobuffchar(va_arg(args, int), atrib), atrib));
	else if (**c == 's' && (*c)++)
		return (ft_print_buff(ft_tobuffstr(va_arg(args, char *), atrib), \
					atrib));
	else if (**c == 'p' && (*c)++)
		return (ft_print_buff(ft_tobuffnbp(va_arg(args, void *), atrib), \
					atrib));
	else if (**c == 'd' && (*c)++)
		return (ft_print_buff(ft_tobuffnbd(va_arg(args, int), atrib), atrib));
	else if (**c == 'i' && (*c)++)
		return (ft_print_buff(ft_tobuffnbd(va_arg(args, int), atrib), atrib));
	else if (**c == 'u' && (*c)++)
		return (ft_print_buff(ft_tobuffnbu(va_arg(args, unsigned), atrib), \
					atrib));
	else if (**c == 'x' && (*c)++)
		return (ft_print_buff(ft_tobuffnbx(va_arg(args, unsigned), atrib, 1), \
					atrib));
	else if (**c == 'X' && (*c)++)
		return (ft_print_buff(ft_tobuffnbx(va_arg(args, unsigned), atrib, 0), \
					atrib));
	return (0);
}

void	get_value(const char **s, t_atrib *atrib)
{
	while (**s && !is_specifier(**s))
	{
		if (**s == '-' && (*s)++)
			atrib->right_padding = ft_special_atoi(s);
		if (**s == '0' && (*s)++)
			atrib->zero_padding = ft_special_atoi(s);
		if (is_digit(**s))
			atrib->left_padding = ft_special_atoi(s);
		if (**s == '.' && (*s)++ && ++(atrib->precision_on))
			atrib->precision = ft_special_atoi(s);
		if (**s == '#')
			atrib->sharp = 1;
		if (**s == ' ' && !atrib->sign)
			atrib->space = 1;
		if (**s == '+')
		{
			atrib->space = 0;
			atrib->sign = 1;
		}
		if (is_digit(**s))
			while (is_digit(*(*s)))
				(*s)++;
		else if (!is_specifier(**s))
			(*s)++;
	}
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	size_t	cnt;
	t_atrib	atrib;

	va_start(args, s);
	cnt = 0;
	if (!s)
		return (-1);
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			ft_initatrib(&atrib);
			ft_get_atrib(&s, &atrib);
			cnt += ft_print_arg(&s, args, &atrib);
		}
		else
		{
			cnt += ft_putchar(*s);
			s++;
		}
	}
	return (cnt);
}
