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
	mlx->game.delta_x = (float)mlx->x_win / ft_strlen(mlx->prm->map_array[0]) / 3;

	//mlx->game.delta_x = mlx->game.delta_x / 2;
	mlx->game.delta_y = (float)mlx->y_win / mlx->prm->str_n / 3 ;

	printf("delta_x %f  \n", mlx->game.delta_x);
	printf("delta y %f  \n", mlx->game.delta_y);
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
	float x,  y, color;
	int col, str;

	x = 0;
	y = 0;
	col = str = 0;
	color = 0x00cccccc;
	//mlx->img.img = mlx_new_image(mlx->mlx_ptr, mlx->x_win, mlx->y_win);
	while (mlx->prm->map_array[str][col] != '\0')
	{
		while (x < (col + 1) * mlx->game.delta_x)
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
				while (y < (str + 1) * mlx->game.delta_y)
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
	//printf("x %d y %d \n", mlx->prm->play_x, mlx->prm->play_y);
	//mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img, 0, 0);


}
void 	ft_test(t_mlx *mlx)
{
	float posX = mlx->game.player_x, posY = mlx->game.player_y;  // начальная позиция x и y
	float dirX = mlx->game.trend_x, dirY = mlx->game.trend_y; // начальный вектор направления
	float planeX = 0, planeY = 0.66; // 2d raycaster версия плоскости камеры
	float time = 0; // время текущего кадра
	float oldTime = 0; // время предыдущего кадра

}
void 	ft_verline(t_mlx *mlx, float tr, int drawStart, int drawEnd)
{
	int new_tr = tr * mlx->x_win;
	printf(" new_tr %d tr %f\n", new_tr, tr);
	printf("  mlx->x_win %d  \n",  mlx->x_win);
	while (drawStart < drawEnd)
	{
		my_mlx_pixel_put(&mlx->img, new_tr, drawStart, mlx->game.color);
		drawStart++;
	}
}
int 	ft_print_line(t_mlx *mlx, float perpWallDist, float tr)
{

	int h = mlx->y_win;
	// Рассчитываем высоту линии для рисования на экране
	if (perpWallDist == 0)
		perpWallDist = 1;
	int lineHeight =  (int)(h / perpWallDist);

	// вычисляем самый низкий и самый высокий пиксели для заполнения текущей полосы
	int drawStart = -lineHeight / 2 + h / 2;
	if (drawStart < 0 )
		drawStart = 0;
	int drawEnd = lineHeight / 2 + h / 2;
	if (drawEnd >= h)
		drawEnd = h - 1;
	ft_verline(mlx, tr, drawStart, drawEnd);
	return 0;
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
void 	ft_check_wall(t_mlx *mlx, float x, float tr)
{
	mlx->game.color = 0xfcfcfc;
	if ((int)(mlx->game.player_y + (mlx->game.trend_x * sin(tr) + mlx->game.trend_y * cos(tr)) * (x + 0.04))
	> (int)(mlx->game.player_y + (mlx->game.trend_x * sin(tr) + mlx->game.trend_y * cos(tr)) * (x)))
		mlx->game.color = 0x999999;

	if ((int)(mlx->game.player_x + (mlx->game.trend_x * cos(tr) - mlx->game.trend_y * sin(tr)) * (x + 0.04))
	> (int)(mlx->game.player_x + (mlx->game.trend_x * cos(tr) - mlx->game.trend_y * sin(tr)) * (x)))
	{
		if (mlx->game.trend_x - mlx->game.trend_y > 0)
			mlx->game.color = 0x009900;
		else
			mlx->game.color = 0x000099;
	}

	/*
	[(int)(mlx->game.player_y + (mlx->game.trend_x * sin(tr) + mlx->game.trend_y * cos(tr)) * (x + 0.05))]
	[(int)(mlx->game.player_x + (mlx->game.trend_x * cos(tr) - mlx->game.trend_y * sin(tr)) * (x + 0.05))])
*/
	 }


void	ft_put_player(t_mlx *mlx)
{




	my_mlx_pixel_put(&mlx->img, mlx->game.player_x * mlx->game.delta_x,
				  mlx->game.player_y * mlx->game.delta_y, 0xFFFFFFFF);
	float x, y;
	x = 0;

	while (x < 10000)
	{
		if (ft_strchr("0NSWE",
		mlx->prm->map_array
		[(int)(mlx->game.player_y + mlx->game.trend_y * x)]
		[(int)(mlx->game.player_x + mlx->game.trend_x * x)])

		&& mlx->prm->map_array
		[(int)(mlx->game.player_y + mlx->game.trend_y * x)]
		[(int)(mlx->game.player_x + mlx->game.trend_x * x)] != ' '
		)
			x += 0.01;
		else
			break ;
	}



	//dist = sqrt(   pow(  (t_x +1  - mlx->game.player_x + 1), 2)  + pow((t_y + 1 - mlx->game.player_y + 1), 2));

	/*
	 * printf(" x %f ", x);
	printf(" t_x %f ", t_x);
	printf(" player_x %f ", mlx->game.player_x);
	printf(" t_y %f ", t_y);
	printf(" player_y %f \n", mlx->game.player_y);
*/
	x = x - 0.1;
	y = x;
	while (x > 0.1)
	{
		my_mlx_pixel_put(&mlx->img,
		(mlx->game.player_x + mlx->game.trend_x * x) * mlx->game.delta_x,
		(mlx->game.player_y + mlx->game.trend_y * x) * mlx->game.delta_y, 0x00cc9999);
	x = x - 0.01;
	}
	x = 0;
	float tr;
	tr = -0.5;
	float two_tr;
	float temp_x = 100;
	int chek = 0;

		while (tr <= 0.5)
		{
			 while (x < 10000)
			{
				if (ft_strchr("0NSWE",
				mlx->prm->map_array
				[(int)(mlx->game.player_y + (mlx->game.trend_x * sin(tr) + mlx->game.trend_y * cos(tr)) * (x + 0.05))]
				[(int)(mlx->game.player_x + (mlx->game.trend_x * cos(tr) - mlx->game.trend_y * sin(tr)) * (x + 0.05))])
				&& (
						ft_strchr("0NSWE",
								  mlx->prm->map_array
								  [(int)(mlx->game.player_y + (mlx->game.trend_x * sin(tr) + mlx->game.trend_y * cos(tr)) * (x))]
								  [(int)(mlx->game.player_x + (mlx->game.trend_x * cos(tr) - mlx->game.trend_y * sin(tr)) * (x + 0.05))])
				||
						ft_strchr("0NSWE",
								  mlx->prm->map_array
								  [(int)(mlx->game.player_y + (mlx->game.trend_x * sin(tr) + mlx->game.trend_y * cos(tr)) * (x + 0.05))]
								  [(int)(mlx->game.player_x + (mlx->game.trend_x * cos(tr) - mlx->game.trend_y * sin(tr)) * (x))])

					   )
			)
					x += 0.05;

				else
					break;


			}
			x -= 0.05;
			while (x < 10000)
			{
				if (chek == 0 && ft_strchr("0NSWE",
							  mlx->prm->map_array
							  [(int)(mlx->game.player_y + (mlx->game.trend_x * sin(tr) + mlx->game.trend_y * cos(tr)) * (x + 0.005))]
							  [(int)(mlx->game.player_x + (mlx->game.trend_x * cos(tr) - mlx->game.trend_y * sin(tr)) * (x + 0.005))])

			 && (
				 ft_strchr("0NSWE",
					   mlx->prm->map_array
						   [(int)(mlx->game.player_y + (mlx->game.trend_x * sin(tr) + mlx->game.trend_y * cos(tr)) * (x))]
						   [(int)(mlx->game.player_x + (mlx->game.trend_x * cos(tr) - mlx->game.trend_y * sin(tr)) * (x + 0.005))])
				 ||
				 ft_strchr("0NSWE",
						   mlx->prm->map_array
						   [(int)(mlx->game.player_y + (mlx->game.trend_x * sin(tr) + mlx->game.trend_y * cos(tr)) * (x + 0.005))]
						   [(int)(mlx->game.player_x + (mlx->game.trend_x * cos(tr) - mlx->game.trend_y * sin(tr)) * (x))])

		 )



			 )
					x += 0.005;

				else
					break;
			}
			ft_check_wall(mlx, x, tr);
			//x -= 0.005;
			temp_x = x;
			float t_x, t_y;
			t_x = mlx->game.player_x + mlx->game.trend_x * x;
			t_y = mlx->game.player_y + mlx->game.trend_y * x;
			float dist;
			dist = sqrt(pow((mlx->game.player_x - t_x), 2) + pow((mlx->game.player_y - t_y), 2));
			//printf("tr 1 %f\n", tr);
			//printf("tr 2 %f\n", abs(tr));
			//printf("dist 1 %f\n", dist);
			two_tr = tr + 0.5;
			dist = dist * cos(tr);

			//printf("dist 2 %f\n", dist);
			//printf("cos 2 %f\n", cos( tr));
ft_print_line(mlx, dist, two_tr);



			 while (x > 0.0)
			{
				my_mlx_pixel_put(&mlx->img,
				 (mlx->game.player_x + (mlx->game.trend_x * cos(tr) - mlx->game.trend_y * sin(tr)) * x) * mlx->game.delta_x,
				 (mlx->game.player_y + (mlx->game.trend_x * sin(tr) + mlx->game.trend_y * cos(tr)) * x) * mlx->game.delta_y, 0x00cc9999);
			x = x - 0.1;
			}
			 x = 0;
			//printf("  tr %f\n", tr);
			//printf("  tr %f\n", 1.f / 500);
	 		tr += (1.f / mlx->x_win);

		}


	my_mlx_pixel_put(&mlx->img, (mlx->game.player_x + mlx->game.vision_x + mlx->game.trend_x * 0.7) * mlx->game.delta_x,
					 (mlx->game.player_y + mlx->game.vision_y + mlx->game.trend_y * 0.7) * mlx->game.delta_y, 0x00cc0000);
/*

	my_mlx_pixel_put(&mlx->img, (mlx->game.player_x + mlx->game.vision_x) * mlx->game.delta_x,
					 (mlx->game.player_y + mlx->game.vision_y) * mlx->game.delta_y, 0x00cc0000);
					 */
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
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, mlx.x_win , mlx.y_win, "Hello world!");
	mlx.img.img = mlx_new_image(mlx.mlx_ptr, mlx.x_win , mlx.y_win);
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