/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 21:25:31 by jsauron           #+#    #+#             */
/*   Updated: 2018/04/14 23:00:44 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	while (dest[j] && j < n)
		j++;
	while (src[i] && (i + j + 1) < n)
	{
		dest[i + j] = src[i];
		i++;
	}
	if (j != n)
		dest[i + j] = '\0';
	return (j + ft_strlen(src));
}
