#ifndef SO_LONG_H
#define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <mlx.h>

typedef struct s_data
{
	void		*mlx_ptr; // MLX pointer
	void		*win_ptr; // MLX window pointer
	void		*textures[5]; // MLX image pointers (on the stack)
	t_map		*map; // Map pointer (contains map details - preferably kept on the stack)
}	t_data;

#endif
