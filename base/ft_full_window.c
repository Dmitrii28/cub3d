#include "../cub3d.h"

int		ft_full_window(t_mlx *mlx)
{
	ft_draw_sky(mlx);
	ft_draw_map(mlx);
	ft_put_player(mlx);


	//mlx->img.addr = mlx_get_data_addr(mlx->img.img, &mlx->img.bits_per_pixel,
									 // &mlx->img.line_length, &mlx->img.endian);


	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img, 0, 0);


	return (0);
}