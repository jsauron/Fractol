/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 05:23:29 by jsauron           #+#    #+#             */
/*   Updated: 2018/04/16 22:06:29 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*d;
	unsigned	i;

	if (!s)
		return (NULL);
	i = 0;
	if (!(d = (char *)malloc(len + 1)))
		return (NULL);
	while (i < len)
		d[i++] = s[start++];
	d[i] = '\0';
	return (d);
}
