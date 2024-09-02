#include "so_long.h"
#include <mlx.h>

int	main(void)
{
	void	*mlx_ptr; // to store the instance of connection (the session)
	void	*win_ptr; // to initiate window rendering

	mlx_ptr = mlx_init(); // connects with the graphycal system
	if (!mlx_ptr)
		return (1);
	win_ptr = mlx_new_window(mlx_ptr, 300, 300, "Hello world!");
	if (!win_ptr)
		return (free(mlx_ptr), 1);
	mlx_destroy_window(mlx_ptr, win_ptr);
	mlx_destroy_display(mlx_ptr);
	//mlx_loop(mlx);	

	free(mlx_ptr);
	return (0);
}
