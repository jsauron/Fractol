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
	printf("0\n");
//	get_color(&e);
	printf("color\n");
	init_fractal(&e);
	init_win(&e);
	printf("1\n");
	init_img(&e);
	printf("2\n");
//	clear_img(&e);
	draw(&e, &e.ftl, &e.point, &e.image);
	printf("3\n");
	mlx_hook(e.win, 2, 0, key, &e);
	mlx_loop(e.mlx);
}
