#include "../cub3d.h"
void	ft_exit_game(t_mlx *mlx)
{
	exit(ft_exit(mlx->prm));
}

int 	ft_start_win_and_xpm_to_img(t_mlx *mlx)
{
	float 	dlt;
	int 	error;

	//error = 0;
if ((error = ft_xpm_to_img(mlx)))
	return (error);

	//printf("------------------------------- mlx %x\n", mlx->mlx_ptr);
	mlx_get_screen_size(mlx->mlx_ptr, &mlx->x_win, &mlx->y_win);
	printf("---------------------------------------------------x (ширина) %d y (высота) %d \n", mlx->x_win, mlx->y_win);
	printf("---------------- --------------x (длинна) %d y (строки) %d \n", ft_strlen(mlx->prm->map_array[0]), mlx->prm->str_n);
	if (mlx->x_win > mlx->prm->x_win)
		mlx->x_win = mlx->prm->x_win;
	if (mlx->y_win > mlx->prm->y_win)
		mlx->y_win = mlx->prm->y_win;
	printf("x-win %d  y-win %d \n", mlx->x_win, mlx->y_win);
	mlx->pl.delta_x = (float)mlx->x_win / ft_strlen(mlx->prm->map_array[0]) / 3;

	//mlx->pl.delta_x = mlx->pl.delta_x / 2;
	mlx->pl.delta_y = (float)mlx->y_win / mlx->prm->str_n / 3 ;

	printf("delta_x %f  \n", mlx->pl.delta_x);
	printf("delta y %f  \n", mlx->pl.delta_y);
	return (0);
}
void        my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char    *dst;
	dst = img->addr + (y * img->line_len + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
void 	ft_draw_map(t_mlx *mlx)
{
	float x,  y, color;
	int col, str;

	x = 0;
	y = 0;
	col = str = 0;
	color = 0x00cccccc;
	//mlx->img.img = mlx_new_image(mlx->mlx_ptr, mlx->x_win, mlx->y_win);
	while (mlx->prm->map_array[str][col] != '\0')
	{
		while (x < (col + 1) * mlx->pl.delta_x)
		{
			str = 0;
			while (mlx->prm->map_array[str])
			{
				if (mlx->prm->map_array[str][col] == '1')
					color = 0x000000cc;
				else if (mlx->prm->map_array[str][col] == '0')
					color = 0x0000cc00;
				else if (mlx->prm->map_array[str][col] == ' ')
					color = 0x00cc0000;
				else if (mlx->prm->map_array[str][col] == '2')
					color = 0x00454311;
				else
					color = 0x00003333;
				while (y < (str + 1) * mlx->pl.delta_y)
				{
					my_mlx_pixel_put(&mlx->img, x, y, color);
					y++;


				}
				str++;
			}
			y = 0;
			x++;
		}
		col++;
		str = 0;
	}

}
void 	ft_test(t_mlx *mlx)
{
	float posX = mlx->pl.player_x, posY = mlx->pl.player_y;  // начальная позиция x и y
	float dirX = mlx->pl.trend_x, dirY = mlx->pl.trend_y; // начальный вектор направления
	float planeX = 0, planeY = 0.66; // 2d raycaster версия плоскости камеры
	float time = 0; // время текущего кадра
	float oldTime = 0; // время предыдущего кадра

}

void		ft_draw_sky(t_mlx *mlx)
{
	int y, x;
	x = y = 0;

	while (x < mlx->x_win)
	{
		while (y < mlx->y_win / 2)
		{
			my_mlx_pixel_put(&mlx->img, x, y, 0x123321);
			y++;
		}
		while (y < mlx->y_win)
		{
			my_mlx_pixel_put(&mlx->img, x, y, 0xcccccc);
			y++;
		}
		y = 0;
		x++;
	}
}


void 	ft_base(t_data *prm)
{
	t_mlx	mlx;
	mlx.prm  = prm;

	mlx.win_ptr = NULL;
	if (!(mlx.mlx_ptr = mlx_init()))
		return (200); ////// ошибка инициализации mlx
	if (ft_game_first_param(&mlx))
		ft_exit_game(&mlx);

	if ((mlx.exit = ft_start_win_and_xpm_to_img(&mlx)))
		ft_exit_game(&mlx);
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, mlx.x_win , mlx.y_win, "Hello world!");
		//ошибка создания окна
	mlx.img.img_ptr = mlx_new_image(mlx.mlx_ptr, mlx.x_win , mlx.y_win);
	//ошибка создания изображения
	mlx.img.addr = mlx_get_data_addr(mlx.img.img_ptr, &mlx.img.bits_per_pixel,
									 &mlx.img.line_len, &mlx.img.endian);
	//ошибка взятия адреса изображения

	printf("------------------------------- mlx %s\n", mlx.mlx_ptr);



	mlx_hook(mlx.win_ptr, 2, 1L << 0, ft_key_on, &mlx);
	mlx_hook(mlx.win_ptr, 3, 1L << 1, ft_key_off, &mlx);
	mlx_loop_hook(mlx.mlx_ptr, ft_key_scan, &mlx);

	printf("------------------------------- pl %f\n", mlx.pl.player_x);



	mlx_loop(mlx.mlx_ptr);




}