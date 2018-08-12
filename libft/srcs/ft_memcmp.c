/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 03:28:18 by jsauron           #+#    #+#             */
/*   Updated: 2018/04/16 17:38:11 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *d1;
	const unsigned char *d2;

	if (n == 0)
		return (0);
	d1 = (const unsigned char *)s1;
	d2 = (const unsigned char *)s2;
	while (--n && *d1 == *d2)
	{
		d1++;
		d2++;
	}
	return (*d1 - *d2);
}
