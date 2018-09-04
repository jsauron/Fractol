/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 15:28:48 by jsauron           #+#    #+#             */
/*   Updated: 2018/09/04 15:28:56 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	err_malloc(void)
{
	ft_putstr(C_RED"Malloc failled\n"C_NONE);
	exit(1);
}

void	arg_invalid(void)
{
	ft_putstr(C_GREEN"./fdf <julia> || <mandelbrot> || <buddha>\n"C_NONE);
	exit(1);
}

void	image_err(void)
{
	ft_putstr(C_RED"Image failled\n"C_NONE);
	exit(1);
}
