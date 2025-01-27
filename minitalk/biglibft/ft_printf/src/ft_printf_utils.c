/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <bduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:12:47 by bduval            #+#    #+#             */
/*   Updated: 2024/12/02 17:15:19 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_special_strlen(const char *s)
{
	size_t	l;

	if (!s)
		return (0);
	l = 0;
	while (s[l])
		l++;
	return (l);
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

void	ft_putstr(char *bf)
{
	size_t	i;

	if (!bf)
		return ;
	i = 0;
	while (bf[i])
		i++;
	i = write(1, bf, i);
}

void	ft_put_atrib(t_atrib *a)
{
	if (a->left_on)
		ft_putstr(a->padding);
	ft_putstr(a->signing);
	if (a->zero_on)
		ft_putstr(a->padding);
	if (a->is_char)
		ft_putchar(a->c);
	else
		ft_putstr(a->content);
	if (a->right_on)
		ft_putstr(a->padding);
	free(a->padding);
	free(a->content);
}
