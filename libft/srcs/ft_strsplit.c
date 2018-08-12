/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 01:12:36 by jsauron           #+#    #+#             */
/*   Updated: 2018/04/16 21:26:02 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**matrice;
	int		word;
	int		i;
	int		k;

	if (!s ||
		!(matrice = (char **)malloc(sizeof(*matrice) * (ft_count(s, c) + 1))))
		return (NULL);
	word = 0;
	i = 0;
	while (word < ft_count(s, c))
	{
		k = 0;
		if (!(matrice[word] = ft_strnew((s_word(&s[i], c) + 1))))
			return (NULL);
		while (s[i] == c)
			i++;
		while (s[i] && s[i] != c)
			matrice[word][k++] = s[i++];
		matrice[word][k] = '\0';
		word++;
	}
	matrice[word] = 0;
	return (matrice);
}
