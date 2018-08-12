/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 20:07:31 by jsauron           #+#    #+#             */
/*   Updated: 2018/04/13 01:56:37 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *str, const char *ss, size_t len)
{
	size_t		i;
	size_t		j;
	size_t		c;

	i = 0;
	if (ss[0] == '\0')
		return ((char *)str);
	while (str[i])
	{
		j = i;
		c = 0;
		while (str[j++] == ss[c++] && j <= len)
		{
			if (ss[c] == '\0')
				return ((char *)&str[i]);
		}
		i++;
	}
	return (NULL);
}
