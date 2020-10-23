#include "../cub3d.h"

int		ft_full_window(t_mlx *mlx)
{
	//ft_draw_sky(mlx);
	ft_draw_map(mlx);
	//ft_dist_and_dot_wall(mlx);
	ft_print_line(mlx);

	my_mlx_pixel_put(&mlx->img, mlx->spr.sp_left_x * mlx->pl.delta_x,
					 mlx->spr.sp_left_y * mlx->pl.delta_y, 0xFFFFFF);

	my_mlx_pixel_put(&mlx->img, mlx->spr.sp_right_x * mlx->pl.delta_x,
					 mlx->spr.sp_right_y * mlx->pl.delta_y, 0xFF00FF);



	//my_mlx_pixel_put(&mlx->img, sp_x1 * mlx->pl.delta_x,
					 //sp_y1 * mlx->pl.delta_y, 0xFFFFFFFF);
	my_mlx_pixel_put(&mlx->img, mlx->pl.pl_x * mlx->pl.delta_x,
					 mlx->pl.pl_y * mlx->pl.delta_y, 0x00FF00);
	my_mlx_pixel_put(&mlx->img, (mlx->pl.pl_x + mlx->pl.trend_x) * mlx->pl.delta_x,
					 (mlx->pl.pl_y  + mlx->pl.trend_y )* mlx->pl.delta_y, 0x00FF00);

	//mlx->img.addr = mlx_get_data_addr(mlx->img.img, &mlx->img.bits_per_pixel,
									 // &mlx->img.line_length, &mlx->img.endian);
	//my_mlx_pixel_put(&mlx->img, mlx->pl.pl_x * mlx->pl.delta_x,
					// mlx->pl.pl_y * mlx->pl.delta_y, 0xFFFFFFFF);
	//my_mlx_pixel_put(&mlx->img, (mlx->pl.pl_x + mlx->pl.cam_x * 0.5) * mlx->pl.delta_x,
					// (mlx->pl.pl_y + mlx->pl.cam_y * 0.5) * mlx->pl.delta_y, 0x00FF00);
	//my_mlx_pixel_put(&mlx->img, (mlx->pl.pl_x - mlx->pl.cam_x * 0.5) * mlx->pl.delta_x,
					// (mlx->pl.pl_y - mlx->pl.cam_y * 0.5) * mlx->pl.delta_y, 0x00FF00);






	//mlx_do_sync(mlx->mlx_ptr);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img_ptr, 0, 0);

	//mlx_destroy_image(mlx->mlx_ptr, mlx->img.img_ptr);
	//mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, mlx->x_win , mlx->y_win);


	return (0);
}