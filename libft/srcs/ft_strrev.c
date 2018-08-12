/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 14:10:03 by jsauron           #+#    #+#             */
/*   Updated: 2018/04/11 14:10:30 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	char	strr;
	int		i;
	int		x;

	x = 0;
	i = 0;
	while (str[x] != '\0')
		x++;
	x--;
	while (i < x)
	{
		strr = str[x];
		str[x] = str[i];
		str[i] = strr;
		x--;
		i++;
	}
	return (str);
}
