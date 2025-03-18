/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <bduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:25:32 by bduval            #+#    #+#             */
/*   Updated: 2024/11/16 16:11:46 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char src)
{
	char	*new;

	if (!src)
		return (NULL);
	new = malloc(2);
	if (!new)
		return (NULL);
	new[0] = src;
	new[1] = '\0';
	return (new);
}
