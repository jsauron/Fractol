/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 17:05:34 by jsauron           #+#    #+#             */
/*   Updated: 2018/07/05 19:29:49 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void			*ft_memdup(void *str, int len)
{
	void		*retour;

	if (!len)
		return (0);
	if (!(retour = malloc(len)))
		return (NULL);
	ft_memcpy(retour, str, len);
	return (retour);
}

void			*ft_memjoin(void *mem1, void *mem2, int mem1_len, int mem2_len)
{
	void		*retour;

	if (!mem1)
		return (ft_memdup(mem2, mem2_len));
	if (!(retour = malloc(mem1_len + mem2_len)))
		return (NULL);
	ft_memcpy(retour, mem1, mem1_len);
	ft_memcpy(retour + mem1_len, mem2, mem2_len);
	free(mem1);
	return (retour);
}

int				ft_return(t_buff s, char **line, int line_len)
{
	if (*line && !s.len)
	{
		(*line)[line_len] = '\0';
		return (1);
	}
	return (s.len);
}

int				ft_newline(char **line, char *start, int line_len, char *eol)
{
	if (!(*line = ft_memjoin(*line, start, line_len,
					eol + 1 - start)))
		return (-1);
	(*line)[eol - start + line_len] = '\0';
	return (1);
}

int				get_next_line(int fd, char **line)
{
	char			*eol;
	static t_buff	s;
	char			*start;
	int				line_len;

	if (fd < 0 || !line)
		return (-1);
	*line = NULL;
	line_len = 0;
	while (1)
	{
		if (s.len > s.pos && (start = s.buffer + s.pos))
		{
			if ((eol = ft_memchr(start, '\n', (s.len - s.pos))))
			{
				s.pos = eol - s.buffer + 1;
				return (ft_newline(line, start, line_len, eol));
			}
			*line = ft_memjoin(*line, start, line_len, s.len - s.pos);
			line_len += (s.len - s.pos);
		}
		s.pos = 0;
		if (0 >= (s.len = read(fd, s.buffer, BUFF_SIZE)))
			return (ft_return(s, line, line_len));
	}
}
