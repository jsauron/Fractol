/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 02:36:29 by jsauron           #+#    #+#             */
/*   Updated: 2018/08/11 19:00:20 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	check_fractal(int ac, char **av, t_env *e)
{
	if (ac != 2)
		arg_invalid();
	if (ft_strcmp(av[1], "julia") == 0 || ft_strcmp(av[1], "mandelbrot") == 0
	|| ft_strcmp(av[1], "buddha") == 0)
	{
		e->name = av[1];
		get_number(e, av);
	}
	else 
		arg_invalid(); 
}

void	get_number(t_env *e, char **av)
{
	if (ft_strcmp(av[1], "mandelbrot") == 0)
		e->number = 1;	
	if (ft_strcmp(av[1], "julia") == 0)
		e->number = 2;
	if (ft_strcmp(av[1], "buddha") == 0)
		e->number = 3;
}

void	init_win(t_env *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, e->ftl.img_x, e->ftl.img_y, e->name);
}

void	init_img(t_env *e)
{
	e->image.img = mlx_new_image(e->mlx, e->ftl.img_x, e->ftl.img_y);
	e->image.data = (int *)mlx_get_data_addr(e->image.img,
			&e->image.bpp, &e->image.size_l, &e->image.endian);
}

void	exit_win(t_env *e)
{
	mlx_destroy_window(e->mlx, e->win);
	exit(1);
}
