/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 15:41:56 by jsauron           #+#    #+#             */
/*   Updated: 2018/09/16 16:04:38 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int			get_color(t_env *e, int i)
{
	int		color;

	color = WHITE;
	if (e->c > 8)
		e->c = 0;
	if (e->c == 0)
		color = rgb(i * 255 / 8, 0, 0);
	else if (e->c == 1)
		color = unicorn_color(e, i);
	else if (e->c == 2)
		color = rgb(0, 0, i * 255 / 4);
	else if (e->c == 3)
		color = rgb(i * 255 / 50, 0, 0);
	else if (e->c == 4)
		color = rgb(0, i * 255 / 50, 0);
	else if (e->c == 5)
		color = rgb(0, 0, i * 255 / 50);
	else if (e->c == 6)
		color = rgb(0, i * 255 / 8, 0);
	else if (e->c == 7)
		color = rgb(127.5 * (cos(i) + 1),
				127.5 * (sin(i) + 1), 127.5 * (1 - cos(i)));
	else if (e->c == 8)
		color = palette_1(e, i);
	return (color);
}

int			buddha_color(t_env *e, int i)
{
	int		color;

	color = WHITE;
	if (e->c > 2)
		e->c = 0;
	else if (e->c == 0)
		color = rgb(i * 255 / 50, 0, 0);
	else if (e->c == 1)
		color = rgb(0, i * 255 / 50, 0);
	else if (e->c == 2)
		color = rgb(0, 0, i * 255 / 50);
	return (color);
}

int			palette_1(t_env *e, int i)
{
	int		mapping[17];
	int		n;

	if (i < e->ftl.it_max && i > 0)
	{
		n = i % 16;
		mapping[0] = rgb(66, 30, 15);
		mapping[1] = rgb(25, 7, 26);
		mapping[2] = rgb(9, 1, 47);
		mapping[3] = rgb(4, 4, 73);
		mapping[4] = rgb(0, 7, 100);
		mapping[5] = rgb(12, 44, 138);
		mapping[6] = rgb(24, 82, 177);
		mapping[7] = rgb(57, 125, 209);
		mapping[8] = rgb(134, 181, 229);
		mapping[9] = rgb(211, 236, 248);
		mapping[10] = rgb(241, 233, 191);
		mapping[11] = rgb(248, 201, 95);
		mapping[12] = rgb(255, 170, 0);
		mapping[13] = rgb(204, 128, 0);
		mapping[14] = rgb(153, 87, 0);
		mapping[15] = rgb(106, 52, 3);
		return (mapping[n]);
	}
	return (BLACK);
}

int			unicorn_color(t_env *e, int i)
{
	int			index;
	static int	c;
	const int	color[8] = {
		BLUE,
		PINK,
		CYAN,
		WHITE,
		YELLOW,
		PINK,
		CYAN,
		WHITE,
	};

	c++;
	c = (c > 7) ? 0 : c;
	index = (i * 255 / 50) * 7 / e->ftl.it_max;
	if (index > 7)
		index -= 8;
	return (color[index]);
}
