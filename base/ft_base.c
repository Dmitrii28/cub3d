#include "../cub3d.h"
void	ft_exit_game(t_mlx *mlx)
{
	exit(ft_exit(mlx->prm));
}

int 	ft_window_start(t_mlx *mlx)
{
	float 	dlt;


	//printf("------------------------------- mlx %x\n", mlx->mlx_ptr);
	mlx_get_screen_size(mlx->mlx_ptr, &mlx->x_win, &mlx->y_win);
	printf("---------------------------------------------------x (ширина) %d y (высота) %d \n", mlx->x_win, mlx->y_win);
	printf("---------------- --------------x (длинна) %d y (строки) %d \n", ft_strlen(mlx->prm->map_array[0]), mlx->prm->str_n);
	if (mlx->x_win > mlx->prm->x_win)
		mlx->x_win = mlx->prm->x_win;
	if (mlx->y_win > mlx->prm->y_win)
		mlx->y_win = mlx->prm->y_win;
	printf("x-win %d  y-win %d \n", mlx->x_win, mlx->y_win);
	mlx->game.delta = (float)mlx->x_win / ft_strlen(mlx->prm->map_array[0]) ;
	dlt = (float)mlx->y_win / mlx->prm->str_n ;
	printf("dlt %f  \n", dlt);
	mlx->game.delta = (mlx->game.delta > dlt ? dlt : mlx->game.delta);

	//mlx->game.player_x = mlx->prm->play_x * mlx->game.delta * 2;
	//mlx->game.player_y = mlx->prm->play_y * mlx->game.delta * 2;

	printf("delta %f  \n", mlx->game.delta);
	return (0);
}
void        my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char    *dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
void 	ft_draw_map(t_mlx *mlx)
{

	float x, temp_x, y, temp_y, color, smesh, smesh2;
int col, str ;
	x = temp_x = 0;
	y = temp_y = 0;
	col = str = 0;
	color = 0x00cccccc;


	//mlx->img.img = mlx_new_image(mlx->mlx_ptr, mlx->x_win, mlx->y_win);

	while (mlx->prm->map_array[str][col] != '\0')
	{

		while (x < temp_x + mlx->game.delta)
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
				while (y < temp_y + mlx->game.delta)
				{
					my_mlx_pixel_put(&mlx->img, x, y, color);
					y++;
				}
				temp_y = y;
				str++;
			}
			y = 0;
			temp_y = 0;
			x++;
		}
		temp_x = x;
		col++;
		str = 0;
	}

	//printf("x %d y %d \n", mlx->prm->play_x, mlx->prm->play_y);

	//mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img, 0, 0);

}
void	ft_put_player(t_mlx *mlx)
{
	//if (mlx->key.w = 1)
		//mlx->game.player_x += mlx->game.delta * 0.5;
	//mlx->game.player_y += ;


	my_mlx_pixel_put(&mlx->img, mlx->game.player_x * mlx->game.delta,
				  mlx->game.player_y * mlx->game.delta, 0xFFFFFFFF);

	float x, y;
	x = 0;
	while (x < 10000)
	{
		if (ft_strchr("0NSWE", mlx->prm->map_array[(int) (mlx->game.player_y + mlx->game.trend_y * x)]
		[(int) (mlx->game.player_x + mlx->game.trend_x * x)])
		&& mlx->prm->map_array[(int) (mlx->game.player_y + mlx->game.trend_y * x)]
		[(int) (mlx->game.player_x + mlx->game.trend_x * x)] != ' '

		)
			x += 0.1;
		else
			break ;
	}

	x = x - 0.1;
	y = x;
	while (x > 0.1)
	{
		my_mlx_pixel_put(&mlx->img, (mlx->game.player_x + mlx->game.trend_x * x) * mlx->game.delta,
						 (mlx->game.player_y + mlx->game.trend_y * x) * mlx->game.delta, 0x00cc9999);
	x = x - 0.01;
	}
	x = y;
	float tr;
	tr = 0.0;

		while (tr < 0.5)
		{

	 while (x < 10000)
	{
		if (ft_strchr("0NSWE", mlx->prm->map_array[(int) ((mlx->game.player_y + (mlx->game.trend_x * sin(tr) +
													mlx->game.trend_y * cos(tr)) * x) * mlx->game.delta)]
		[(int) ((mlx->game.player_x + (mlx->game.trend_x * cos(tr) -
	mlx->game.trend_y * sin(tr)) * x) * mlx->game.delta)])
		&& mlx->prm->map_array[(int) (mlx->game.player_y + mlx->game.trend_y * x)]
		[(int) (mlx->game.player_x + mlx->game.trend_x * x)] != ' '

		)
			x += 0.1;
		else
			break ;
	}



			 while (x > 0.1)
			{
				my_mlx_pixel_put(&mlx->img, (mlx->game.player_x + (mlx->game.trend_x * cos(tr) -
				mlx->game.trend_y * sin(tr)) * x) * mlx->game.delta,
							 (mlx->game.player_y + (mlx->game.trend_x * sin(tr) +
													mlx->game.trend_y * cos(tr)) * x) * mlx->game.delta, 0x00cc9999);
			x = x - 0.01;
			}
			 x = 0.1;
	 		tr += 0.01;
		}










	my_mlx_pixel_put(&mlx->img, (mlx->game.player_x + mlx->game.vision_x) * mlx->game.delta,
					 (mlx->game.player_y + mlx->game.vision_y ) * mlx->game.delta, 0x00cc0000);


	my_mlx_pixel_put(&mlx->img, (mlx->game.player_x + mlx->game.vision_x) * mlx->game.delta,
					 (mlx->game.player_y + mlx->game.vision_y) * mlx->game.delta, 0x00cc0000);
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



	if ((mlx.exit = ft_window_start(&mlx)))
		ft_exit_game(&mlx);
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, mlx.x_win, mlx.y_win, "Hello world!");
	mlx.img.img = mlx_new_image(mlx.mlx_ptr, mlx.x_win, mlx.y_win);
	mlx.img.addr = mlx_get_data_addr(mlx.img.img, &mlx.img.bits_per_pixel,
									 &mlx.img.line_length, &mlx.img.endian);

	printf("------------------------------- mlx %s\n", mlx.mlx_ptr);
	//ft_draw_map(&mlx);
	//ft_put_player(&mlx);


	mlx_hook(mlx.win_ptr, 2, 1L << 0, ft_key_on, &mlx);
	mlx_hook(mlx.win_ptr, 3, 1L << 1, ft_key_off, &mlx);
	mlx_loop_hook(mlx.mlx_ptr, ft_key_scan, &mlx);

	printf("------------------------------- pl %f\n", mlx.game.player_x);



	mlx_loop(mlx.mlx_ptr);




}