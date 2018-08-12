/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 23:43:29 by jsauron           #+#    #+#             */
/*   Updated: 2018/04/14 19:39:46 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;

	if (s != NULL || n != 0)
	{
		p = (unsigned char *)s;
		while (n > 0)
		{
			p[n - 1] = (unsigned char)c;
			n--;
		}
		return (s);
	}
	return (NULL);
}
