
#include "../includes/fractol.h"

void		key(int key, t_env *e)
{
	if (key == K_ESC)
		exit_win(e);
}
