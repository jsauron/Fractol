/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 15:52:48 by jsauron           #+#    #+#             */
/*   Updated: 2018/05/29 20:49:33 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_realloc(char *ptr, size_t size)
{
	char *ptr2;

	ptr2 = (char *)malloc(sizeof(char) * size + 1);
	ft_strncpy(ptr2, ptr, size);
	ptr2[size] = 0;
	free(ptr);
	return (ptr2);
}
