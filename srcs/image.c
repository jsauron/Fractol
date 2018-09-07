/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 15:32:40 by jsauron           #+#    #+#             */
/*   Updated: 2018/09/04 15:33:53 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	set_pixel_img(t_env *e, int x, int y, int color)
{
	int i;

	if (x > 0 && x < e->ftl.img_x && y > 0 && y < e->ftl.img_y)
	{
		i = x + y * e->ftl.img_x;
		e->image.data[i] = color;
	}
}

void	clear_img(t_env *e)
{
	ft_bzero(e->image.data, e->ftl.img_x * e->ftl.img_y * 4);
}

void	put_info_in_window(t_env *e)
{
	mlx_string_put(e->mlx, e->win, 20, 20, PINK, " MOVE : < ^ > v ");
	mlx_string_put(e->mlx, e->win, 20, 40, PINK, " ZOOM : + - / CLICK / PAD");
	mlx_string_put(e->mlx, e->win, 20, 60, PINK, " ROTATION : Z");
	mlx_string_put(e->mlx, e->win, 20, 80, PINK, " STOP ROT : SPACE");
	mlx_string_put(e->mlx, e->win, 20, 100, PINK, " COLOR : SHIFT");
	mlx_string_put(e->mlx, e->win, 20, 120, PINK, " RESET : R");
	mlx_string_put(e->mlx, e->win, 20, 140, PINK, " SWITCH : ENTER");
	mlx_string_put(e->mlx, e->win, 20, 160, CYAN, " iteration max : ");
	mlx_string_put(e->mlx, e->win, 180, 160, CYAN,  ft_itoa(e->ftl.it_max));
}
