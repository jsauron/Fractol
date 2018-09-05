
#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx_macos/mlx.h"
# include "../libft/includes/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <pthread.h>
# include "threadpool.h"

/*
**       Colors text
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
**       Colors decimal
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

# define BETA 0.1


/*
**      Keys
*/

# define ESC 53
# define COLOR 257
# define CLIK 1
# define ZOOM_PLUS 69
# define ZOOM_LESS 78
# define MOVE_UP 126
# define MOVE_DOWN 125
# define MOVE_RIGHT 124
# define MOVE_LEFT 123
# define ROT_X 7
# define ROT_Y 16
# define ROT_Z 6
# define CHANGE_F 36
# define COLOR 257


typedef	struct		s_matrice
{
	double		x_a;
	double		x_b;
	double		x_c;
	double		y_a;
	double		y_b;
	double		y_c;
        double          z_a;
        double          z_b;
        double          z_c;

}			t_matrice;

typedef struct		s_coord
{
	int	x;
	int	y;

}			t_coord;

typedef struct		s_point
{
	double		x;
	double		y;
	double		z;

}			t_point;

typedef struct		s_line
{
	t_point		*point;

}			t_line;

typedef struct		s_complex
{
        double          c_r;
        double          c_i;
        double          z_r;
        double          z_i;
	
}			t_complex;

typedef struct           s_fractal
{
	double          x1;
        double          x2;
        double          y1;
        double          y2;
	int		it_max;
	int		img_x;
	int		img_y;
	int		zoom_x;
	int		zoom_y;
	int		mouse_x;
	int		mouse_y;
}                       t_fractal;

typedef struct  s_img
{
        void           		*img;
        int                     size_l;
        int                     bpp;
        int                     bppx;
        int                     endian;
        int                     x;
        int                     y;
        int                     *data;

}                               t_img;

typedef	struct		s_arg
{
	void		*e;
	t_fractal	*ftl;
	int		x;
	int		y;
	t_complex	cmp;

}			t_arg;

typedef volatile _Atomic int t_atom;

typedef	struct		s_env
{
	void		*mlx;
	void		*win;
	char		*name;
	t_fractal	ftl;
	int		number;
	t_img		image;
	t_matrice	m;
	t_line		*line;
	int		center_y;
	int		center_x;
	t_threadpool	*pool;
	t_arg		*arg;
	int		color;
	int		c;
	t_atom	 atom;

}			t_env;



/*
**	init.c
*/

void	init(t_env *e);
void	check_fractal(int ac, char **av, t_env *e);
void	init_win(t_env *e);
void	init_img(t_env *e);
void	init_matrice(t_env *e);

/*
**      init_fractal.c
*/

void	init_point(t_env *e, t_fractal *ftl);
void	init_arg(t_env *e, t_fractal *ftl);
void	init_fractal(t_env *e);
void    init_fractal_2(t_env *e, t_fractal *ftl, t_complex *cmp, t_point *p);

/*
**      image.c
*/

void    set_pixel_img(t_env *e, int x, int y, int color);
void    clear_img(t_env *e);

/*
**      julia.c
*/

void    init_julia(t_fractal *ftl);
void    init_julia_2(t_fractal *ftl, t_complex *cmp, t_point p);

/*
**      mandelbrot.c
*/

void    init_mandel(t_fractal *ftl);
void    init_mandel_2(t_fractal *ftl, t_complex *cmp, t_point p);

/*
**      buddha.c
*/
void    init_buddhabrot(t_fractal *ftl);
void    init_buddhabrot_2(t_fractal *ftl, t_complex *cmp, t_point p);
void    draw_buddha(t_env *e, t_fractal *ftl, t_img *image);
void    add_pix_buddha(t_env *e, t_coord *coord, int x, int y, int i);


/*
**      drawing.c
*/

void    calc_all_points(t_env *e,t_fractal *ftl);
void    draw(t_env *e, t_fractal *ftl, t_img *image);
void    calc_fractal(void *arguments);
void    calc_fractal_2(t_env *e, t_coord *coord, int x, int y);

/*
**      draw_3D.c
*/

void    bresenham_tab(int *tab, t_point p1, t_point p2);
void    draw_pixel(t_env *e, t_point p1, t_point p2, int color);
void    draw_line(t_env *e, t_point p1, int x, int y);

/*
**      matrice.c
*/

void    calc_matrice(t_env *e, t_matrice *m, t_point *p);
void    rot_x(t_env *e);
void    rot_y(t_env *e);
void    rot_z(t_env *e);

/*
**	hook.c
*/

int	key(int key, t_env *e);
int	motion_notify(int x, int y, t_env *e);
int	button_press(int key, int x, int y, t_env *e);
int	destroy_notify(t_env *e);
void	exit_win(t_env *e);

/*
**      event.c
*/
void    key_move(t_env *e, int key);
void    move(t_env *e, t_fractal *ftl, float move_x, float move_y);
void    rot(t_env *e, int key);
void    zoom(t_env *e, int x, int y, float zoom);
void    change_fractal(t_env *e);

/*
**	image.c
*/
void	set_pixel_img(t_env *e, int x, int y, int color);
void	clear_img(t_env *e);

/*
**      tools.c
*/

int long	rgb(int r, int g, int b);
void    get_number(t_env *e, char **av);
void		get_center(t_env *e);
void	change_color(t_env *e);
int	get_color(t_env *e, int i);

/*
**      error.c
*/

void    err_malloc(void);
void    arg_invalid(void);
void    image_err(void);

#endif
