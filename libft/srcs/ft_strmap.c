/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 04:27:47 by jsauron           #+#    #+#             */
/*   Updated: 2018/04/16 21:39:14 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char			*mem;
	unsigned int	i;

	if (s || f)
	{
		if (!(mem = ft_strnew((ft_strlen(s)))))
			return (NULL);
		i = 0;
		while (s[i])
		{
			mem[i] = f(s[i]);
			i++;
		}
		mem[i] = '\0';
		return (mem);
	}
	return (NULL);
}
