/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 15:53:45 by jsauron           #+#    #+#             */
/*   Updated: 2018/09/06 17:14:33 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int long	rgb(int r, int g, int b)
{
	int long	c;

	c = r * 65536 + g * 256 + b;
	return (c);
}

void		get_center(t_env *e)
{
	e->center_x = (e->ftl.img_x) / 2;
	e->center_y = (e->ftl.img_y) / 2;
	printf("center x = %d\n", e->center_x);
	printf("center y = %d\n", e->center_y);
}

void		get_number(t_env *e, char **av)
{
	if (ft_strcmp(av[1], "mandelbrot") == 0)
		e->number = 1;
	if (ft_strcmp(av[1], "julia") == 0)
		e->number = 2;
	if (ft_strcmp(av[1], "buddha") == 0)
		e->number = 3;
}

void		change_color(t_env *e)
{
	e->c++;
	init_matrice(e);
	clear_img(e);
	draw(e, &e->ftl, &e->image);
}

/*void	get_color(t_env *e)
  {
  static int c;

  if (c > 3)
  c = 0;
  if (c == 0)
  e->color = rgb(0, 204, 203);
  else if (c == 1)
  e->color = rgb(e->ftl.it_max * 255 / 50, 0, 0);
  else if (c == 2)
  e->color = rgb(231, 62, 1);
  else if (c == 3)
  e->color = rgb(253, 63, 146);
//else if (c == 4)
//	e->color = rgb(0, 0 , i * 255 / 50);
c++;
}*/

int			get_color(t_env *e, int i)
{
	int color;

	color = WHITE;
	if (e->c > 5)
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
	return (color);
}

int		unicorn_color(t_env *e, int i)
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

	c++;;
	c = (c > 7) ? 0 : c;
	//if (p.color >= 0)
		index =  (i * 255/50) * 7 / e->ftl.it_max ;
	//else
	//	index = c + p.color * 7 / map->z_min;
	if (index > 7)
		index -= 8;
	return (color[index]);
}
