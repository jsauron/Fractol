/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 15:59:33 by jsauron           #+#    #+#             */
/*   Updated: 2018/08/03 00:22:11 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE  5

# include "libft.h"
# include <stdio.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct	s_buff
{
	char		buffer[BUFF_SIZE];
	int			pos;
	int			len;
}				t_buff;

int				get_next_line(const int fd, char **line);
void			*ft_memdup(void *str, int len);
void			*ft_memjoin(void *mem1, void *mem2, int mem1_len, int mem2_len);
int				ft_return(t_buff s, char **line, int line_len);
int				get_next_line(int fd, char **lines);

#endif
