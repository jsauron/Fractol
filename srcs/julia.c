#include "../includes/fractol.h"

void    init_julia(t_fractal *ftl)
{
        ftl->x1 = -1;
        ftl->x2 = 1;
        ftl->y1 = -1.2;
        ftl->y2 = 1.2;
        ftl->img_x = 700;
        ftl->img_y = 800;
        ftl->zoom_x = ftl->img_x / (ftl->x2 - ftl->x1);
        ftl->zoom_y = ftl->img_y / (ftl->y2 - ftl->y1);
        ftl->it_max = 150;
}

void    init_julia_2(t_fractal *ftl, t_complex *cmp, t_point p)
{
        cmp->z_r = (float)p.x / ftl->zoom_x + ftl->x1;
        cmp->z_i = (float)p.y / ftl->zoom_y + ftl->y1;
        cmp->c_r = 0.285;
        cmp->c_i = 0.01;
}
