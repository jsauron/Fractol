/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 08:29:44 by jsauron           #+#    #+#             */
/*   Updated: 2018/04/16 17:55:14 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	size_t			size;
	size_t			neg;
	char			*str;
	unsigned int	tmp;

	neg = 0;
	size = 1;
	tmp = ((n < 0) ? -(unsigned int)n : (unsigned int)n);
	if (n < 0)
		neg = 1;
	while ((tmp /= 10))
		size++;
	str = ft_strnew((neg + size));
	if (str == NULL)
		return (NULL);
	if (neg == 1)
		str[0] = '-';
	while (size--)
	{
		str[size + neg] = (neg ? n % 10 * -1 : n % 10) + '0';
		n /= 10;
	}
	return (str);
}
