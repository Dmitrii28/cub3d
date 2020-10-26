#include "../cub3d.h"
void	ft_clear_close_game(t_mlx *mlx)
{
	//exit(ft_clear_close(mlx->prm));
}

int 	ft_start_win_and_xpm_to_img(t_mlx *mlx)
{
	if ((mlx->prm.exit = ft_xpm_to_img(mlx)))
		return (mlx->prm.exit);
	mlx_get_screen_size(mlx->mlx_ptr, &mlx->x_win, &mlx->y_win);
	printf("---------------------------------------------------x (ширина) %d y (высота) %d \n", mlx->x_win, mlx->y_win);
	printf("---------------- --------------x (длинна) %d y (строки) %d \n", ft_strlen(mlx->prm.map_arr[0]), mlx->prm.str_n);
	if (mlx->x_win > mlx->prm.x_win)
		mlx->x_win = mlx->prm.x_win;
	if (mlx->y_win > mlx->prm.y_win)
		mlx->y_win = mlx->prm.y_win;
	if (!mlx->prm.screenshot)
	{
		if (!(mlx->win_ptr =
			mlx_new_window(mlx->mlx_ptr, mlx->x_win , mlx->y_win, "cub3D")))
			return (250);
	}
	if (!(mlx->img.img_ptr =
		mlx_new_image(mlx->mlx_ptr, mlx->x_win , mlx->y_win)))
		return (251);
	if (!(mlx->img.addr = mlx_get_data_addr(mlx->img.img_ptr,
		&mlx->img.bits_per_pixel, &mlx->img.line_len, &mlx->img.endian)))
		return (252);
	return (0);
}
void        my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char    *dst;
	dst = img->addr + (y * img->line_len + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int 	ft_base(t_mlx *mlx)
{////////////////////выходим от сюде не через ретерн а другую функцию
	mlx->win_ptr = NULL;
	if (!(mlx->mlx_ptr = mlx_init()))
		return (200); ////// ошибка инициализации mlx
	ft_game_first_param(mlx);
	if ((mlx->prm.exit = ft_start_win_and_xpm_to_img(mlx)))
		ft_clear_close_game(mlx);
	if (mlx->prm.screenshot)
		ft_screenshot(mlx);
	mlx_hook(mlx->win_ptr, 17, 1L << 17, ft_clear_close, mlx);
	mlx_hook(mlx->win_ptr, 2, 1L << 0, ft_key_on, mlx);
	mlx_hook(mlx->win_ptr, 3, 1L << 1, ft_key_off, mlx);
	mlx_loop_hook(mlx->mlx_ptr, ft_key_scan, mlx);
	mlx_loop(mlx->mlx_ptr);
}