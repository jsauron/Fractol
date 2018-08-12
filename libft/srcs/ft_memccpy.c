/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 02:10:05 by jsauron           #+#    #+#             */
/*   Updated: 2018/04/14 18:50:26 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*d;
	unsigned const char	*s;

	if (dest != NULL || src != NULL)
	{
		d = (unsigned char *)dest;
		s = (unsigned const char *)src;
		while (n--)
		{
			*d = *s;
			if ((*s) == (unsigned char)c)
				return ((void *)(d + 1));
			d++;
			s++;
		}
	}
	return (NULL);
}
