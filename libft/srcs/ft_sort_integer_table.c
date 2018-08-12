/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_integer_table.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 14:08:04 by jsauron           #+#    #+#             */
/*   Updated: 2018/04/11 14:09:05 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sort_integer_table(int *tab, int size)
{
	int i;
	int x;
	int tmp;

	x = 0;
	while (x <= size + 1)
	{
		i = 1;
		while (i <= size)
		{
			if (tab[i - 1] > tab[i] && (i - 1) < i)
			{
				tmp = tab[i - 1];
				tab[i - 1] = tab[i];
				tab[i] = tmp;
			}
			i++;
		}
		x++;
	}
	return ;
}
