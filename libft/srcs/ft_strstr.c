/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 21:53:50 by jsauron           #+#    #+#             */
/*   Updated: 2018/04/09 19:32:59 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *ss)
{
	int i;
	int j;
	int c;

	i = 0;
	if (ss[0] == '\0')
		return ((char *)str);
	while (str[i])
	{
		j = i;
		c = 0;
		while (str[j++] == ss[c++])
		{
			if (ss[c] == '\0')
				return ((char *)&str[i]);
		}
		i++;
	}
	return (NULL);
}
