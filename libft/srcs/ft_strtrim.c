/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 07:05:38 by jsauron           #+#    #+#             */
/*   Updated: 2018/04/16 21:50:52 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t		a;
	size_t		z;

	if (!s)
		return (NULL);
	a = 0;
	while ((s[a]) && (s[a] == ' ' || s[a] == '\n' || s[a] == '\t'))
		a++;
	if (!s[a])
		return (ft_strnew(0));
	z = a;
	while (s[z])
		z++;
	z--;
	while ((s[z]) && (s[z] == ' ' || s[z] == '\n' || s[z] == '\t'))
		z--;
	return (ft_strsub(s, a, z - a + 1));
}
