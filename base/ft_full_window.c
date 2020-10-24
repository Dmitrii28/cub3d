#include "../cub3d.h"

int		ft_full_window(t_mlx *mlx)
{
	//ft_draw_sky(mlx);
	//ft_dist_and_dot_wall(mlx);
	ft_print_line(mlx);




	/*
	my_mlx_pixel_put(&mlx->img, mlx->spr.lft_x * mlx->pl.delta_x,
					 mlx->spr.lft_y * mlx->pl.delta_y, 0xFFFFFF);

	my_mlx_pixel_put(&mlx->img, mlx->spr.right_x * mlx->pl.delta_x,
					 mlx->spr.right_y * mlx->pl.delta_y, 0xFF00FF);




	my_mlx_pixel_put(&mlx->img, mlx->pl.pl_x * mlx->pl.delta_x,
					 mlx->pl.pl_y * mlx->pl.delta_y, 0x00FF00);
	my_mlx_pixel_put(&mlx->img, (mlx->pl.pl_x + mlx->pl.trend_x) * mlx->pl.delta_x,
					 (mlx->pl.pl_y  + mlx->pl.trend_y )* mlx->pl.delta_y, 0x00FF00);

*/


	mlx_do_sync(mlx->mlx_ptr);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img_ptr, 0, 0);




	return (0);
}