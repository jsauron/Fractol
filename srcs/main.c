/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 00:27:19 by jsauron           #+#    #+#             */
/*   Updated: 2018/08/06 04:16:15 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		main(int ac, char **av)
{
	t_env	e;

	check_fractal(ac, av, &e);
	init_fractal(&e);
	init_win(&e);
	init_img(&e);
	draw(&e, &e.ftl, &e.point, &e.image);
	mlx_hook(e.win, 2, 0, key, &e);
	mlx_hook(e.win, 6, 0, motion_notify, &e);
	mlx_hook(e.win, 4, 1L<<2 , button_press, &e);
	mlx_hook(e.win, 17, 0, destroy_notify, &e);
	mlx_loop(e.mlx);
}
