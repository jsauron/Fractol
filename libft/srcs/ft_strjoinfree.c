/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 20:20:02 by jsauron           #+#    #+#             */
/*   Updated: 2018/05/28 20:42:29 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinfree(char *s1, char *s2, int i)
{
	char *str;

	str = ft_strjoin(s1, s2);
	if (i == 1)
		free(s1);
	if (i == 2)
		free(s2);
	if (i == 3)
	{
		free(s1);
		free(s2);
	}
	return (str);
}
