#include "../cub3d.h"

int		ft_full_window(t_mlx *mlx)
{
	ft_draw_sky(mlx);
	ft_draw_map(mlx);
	ft_dist_and_dot_wall(mlx);


	//mlx->img.addr = mlx_get_data_addr(mlx->img.img, &mlx->img.bits_per_pixel,
									 // &mlx->img.line_length, &mlx->img.endian);

	//mlx_do_sync(mlx->mlx_ptr);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img_ptr, 0, 0);
	//mlx_destroy_image(mlx->mlx_ptr, mlx->img.img_ptr);
	//mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, mlx->x_win , mlx->y_win);


	return (0);
}