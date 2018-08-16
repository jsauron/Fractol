#include "mlx.h"

int main()
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "hellowindow");
	mlx_loop(mlx_ptr);
	mlx_pixel_put (mlx_ptr, win_ptr, 300, 300, 50 );
}
