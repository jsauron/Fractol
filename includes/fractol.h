
#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx_macos/mlx.h"
# include "../libft/includes/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <sys/stat.h>

/*
**       Color text
*/

# define C_NONE         "\033[0m"
# define C_BOLD         "\033[1m"
# define C_BLACK        "\033[30m"
# define C_RED          "\033[31m"
# define C_GREEN        "\033[32m"
# define C_BROWN        "\033[33m"
# define C_BLUE         "\033[34m"
# define C_MAGENTA      "\033[35m"
# define C_CYAN         "\033[36m"
# define C_GRAY         "\033[37m"

/*
**       Color RGB
*/

# define BLUE 43263
# define RED 16711680
# define GREEN 65280
# define YELLOW 16776960
# define PINK 16754943
# define WHITE 16514043
# define CYAN 6881279
# define BLACK 0

/*
**	Params
*/

# define WIN_L 500
# define WIN_H 500

# define K_ESC 53
# define K_COLOR 257
# define K_CLIK 1
# define K_UP 5
# define K_DOWN 4

typedef struct		s_point
{
	int		x;
	int		y;

}			t_point;

typedef struct           s_fractal
{
	int		i;
	double		tmp;
	int		it_max;
	double		c_r;
	double		c_i;
	double		z_r;
	double		z_i;
	double		x1;
	double		x2;
	double		y1;
	double		y2;
	int		zoom;
	int		color;
	int		it_red;
	int		it_green;
	int		it_blue;
	int		img_x;
	int		img_y;
	int		**pxl_red;
	int		**pxl_green;
	int		**pxl_blue;
	int		***pxl_tmp;
	int		it_max_red;
	int		it_max_green;
	int		it_max_blue;
	int		zoom_x;
	int		zoom_y;		
}                       t_fractal;

typedef struct  s_img
{
        void            *img;
        int                     size_l;
        int                     bpp;
        int                     bppx;
        int                     endian;
        int                     x;
        int                     y;
        int                     *data;
}                               t_img;

typedef	struct		s_env
{
	void		*mlx;
	void		*win;
	char		*name;
	t_fractal	ftl;
	t_point		point;
	int		number;
	int		color1;
	int		color2;
	t_img		image;
}			t_env;

/*
**	init.c
*/

void	check_fractal(int ac, char **av, t_env *e);
void	get_number(t_env *e, char **av);
void	init_fractal(t_env *e);
void	init_win(t_env *e);
void	init_img(t_env *e);
void	exit_win(t_env *e);

/*
**	error.c
*/

void	err_malloc(void);
void	arg_invalid(void);
void	image_err(void);

/*
**	mandelbrot.c
*/

void	init_mendel(t_env *e, t_fractal *fractal, t_point *point, t_img *image);
void	calc_fractal(t_env *e, t_fractal *fractal, t_point *point, t_img *image);
void    init_mendel_2(t_env *e, t_fractal *fractal, t_point *point, t_img *image);
/*
**      mandelbrot.c
*/

void	init_julia(t_env *e, t_fractal *fractal, t_point *point, t_img *image);
void    init_julia_2(t_env *e, t_fractal *fractal, t_point *point, t_img *image);
/*
**	drawing.c
*/
void    draw_fractal(t_env *e);


/*
**      fractol.c
*/

void	draw(t_env *e, t_fractal *ftl, t_point *point, t_img *image);
void    init_mendel_2(t_env *e, t_fractal *ftl, t_point *point, t_img *image);
void	init_buddhabrot(t_env *e, t_fractal *ftl, t_point *point, t_img *image);
/*
**	hook.c
*/

int	key(int key, t_env *e);
int	motion_notify(int x, int y, t_env *e);
int	button_press(int key, int x, int y, t_env *e);
int	destroy_notify(t_env *e);

/*
**	image.c
*/
int long	rgb(int r, int g, int b);
void	set_pxl_tab(t_fractal *ftl);
void	set_pixel_img(t_env *e, int x, int y, int color);
void	clear_img(t_env *e);
void	get_color(t_env *e);
void	change_color(t_env *e);

#endif
