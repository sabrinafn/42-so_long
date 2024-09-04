#include "so_long.h"

int	handle_no_event(void *data)
{
	if (data)
		return (0);
	return (0);
}
int	handle_keypress(int keysym, t_data *data)
{
	printf("Key pressed: |%d|\n", keysym);
	if (keysym == XK_Escape)
		mlx_destroy_window(data -> mlx_ptr, data -> win_ptr);
	printf("Key pressed: |%d|\n", keysym);
	return (0);
}
/*
int	handle_keyrelease(int keysym, t_data *data)
{
	printf("Key release: |%d|\n", keysym);
	if (data)
		return (0);
	return (0);
}*/

int render_rect(t_data *data, t_rect rect)
{
    int	i;
    int j;

    if (data->win_ptr == NULL)
        return (1);
    i = rect.y;
    while (i < rect.y + rect.height)
    {
        j = rect.x;
        while (j < rect.x + rect.width)
            mlx_pixel_put(data->mlx_ptr, data->win_ptr, j++, i, rect.color);
        ++i;
	}
	return (0);
}

void	render_background(t_data *data, int color)
{
	int	i;
	int	j;

	if (data -> win_ptr == NULL)
		return ;
	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, j++, i, color);
		i++;
	}
}

int	render(t_data *data)
{
	render_background(data, WHITE_PIXEL);
    render_rect(data, (t_rect){WINDOW_WIDTH - 100, WINDOW_HEIGHT - 100,
            100, 100, GREEN_PIXEL});
    render_rect(data, (t_rect){0, 0, 100, 100, RED_PIXEL});

    return (0);
}

int	main(void)
{
	t_data data;

	// to store the instance of connection (the session)
	//*win_ptr; // to initiate window rendering

	data.mlx_ptr = mlx_init(); // connects with the graphycal system
	if (!data.mlx_ptr)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, 600, 300, "Hello world!");
	if (!data.win_ptr)
		return (free(data.mlx_ptr), 1);

	// HOOKS
	mlx_loop_hook(data.mlx_ptr, &handle_no_event, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	
	render(&data);
	// LOOP for the window
	mlx_loop(data.mlx_ptr); // needed to keep the window open
	
//	mlx_destroy_window(mlx_ptr, win_ptr); // free the resources needed to create the window
	mlx_destroy_display(data.mlx_ptr); // free ptr created if there isn't a window left
	free(data.mlx_ptr);
	return (0);
}
