#include "../cub3d.h"
void 	ft_ft_temp(t_mlx *mlx)
{
	if (mlx->wall.side == 1)
		mlx->wall.color = 0xffffff; // белый
	if (mlx->wall.side == 2)
	 	mlx->wall.color = 0x009900; //зеленый
	if (mlx->wall.side == 3)
	 	mlx->wall.color = 0x000099; //синий
	if (mlx->wall.side == 4)
	 	mlx->wall.color = 0x999999; //серый
	if (mlx->wall.side == 5)
		mlx->wall.color = 0xf1001f; //серый
}


void 	ft_check_wall(t_mlx *mlx, float x, float dlt, t_data *prm)
{
	int	py;
	int px;
	int	ry;
	int rx;

	py = mlx->pl.player_y;
	px = mlx->pl.player_x;
	ry = mlx->pl.yray_trd;
	rx = mlx->pl.xray_trd;
	if ((int)(py + ry * (x + dlt)) < (int)(py + ry * x) &&
		prm->map_arr[(int)(py + ry * (x + dlt))][(int)(px + rx * x)] == '1')
		mlx->wall.side = 1; // черный
	if ((int)(px + rx * (x + dlt)) > (int)(px + rx * x) &&
		prm->map_arr[(int)(py + ry * x)][(int)(px + rx * (x + dlt))] == '1')
		mlx->wall.side = 2; //зеленый
	if ((int)(px + rx * (x + dlt)) < (int)(px + rx * x) &&
		prm->map_arr[(int)(py + ry * (x))][(int)(px + rx * (x + dlt))] == '1')
		mlx->wall.side = 3; //синий
	if ((int)(py + ry * (x + dlt)) > (int)(py + ry * x) &&
		prm->map_arr[(int)(py + ry * (x + dlt))][(int)(px + rx * x)] == '1')
		mlx->wall.side = 4; //серый
	if (prm->map_arr[(int)(py + ry * x)][(int)(px + rx * (x + dlt))] == '2' ||
		prm->map_arr[(int)(py + ry * (x + dlt))][(int)(px + rx * x)] == '2')
		mlx->wall.side = 5; //серый
	ft_ft_temp(mlx);
}

int 	ft_print_line(t_mlx *mlx, float perpWallDist, float tr)
{
	int new_tr;
	int line_height;
	int draw_start;
	int draw_end;

	new_tr = (int)(tr * mlx->x_win);
	// Рассчитываем высоту линии для рисования на экране
	if (perpWallDist > 0)
	{
		line_height = (int)(mlx->y_win / perpWallDist);

		// вычисляем самый низкий и самый высокий пиксели для заполнения текущей полосы
		draw_start = -line_height / 2 + mlx->y_win / 2;
		if (draw_start < 0)
			draw_start = 0;
		draw_end = line_height / 2 + mlx->y_win / 2;
		if (draw_end >= mlx->y_win)
			draw_end = mlx->y_win - 1;
		while (draw_start <= draw_end) {

			my_mlx_pixel_put(&mlx->img, new_tr, draw_start, mlx->wall.color);
			draw_start++;
		}
		//printf("mlx->pl.color %x new_tr %d\n", mlx->pl.color, new_tr);
	}
	return 0;
}


void	ft_dist_and_dot_wall(t_mlx *mlx)
{

	my_mlx_pixel_put(&mlx->img, mlx->pl.player_x * mlx->pl.delta_x,
					 mlx->pl.player_y * mlx->pl.delta_y, 0xFFFFFFFF);
	float x, y;

	x = 0;
	double tr;
	tr = -0.5;
	float dlt;
	float two_tr;

	while (tr <= 0.5)
	{
		mlx->pl.xray_trd = mlx->pl.trend_x * cos(tr) - mlx->pl.trend_y * sin(tr);
		mlx->pl.yray_trd = mlx->pl.trend_x * sin(tr) + mlx->pl.trend_y * cos(tr);
		dlt = 0.95;
		while (dlt >= 0.00095)
		{
			if (ft_strchr("0NSWE", mlx->prm->map_arr
				[(int)(mlx->pl.player_y + mlx->pl.yray_trd * (x + dlt))]
				[(int)(mlx->pl.player_x + mlx->pl.xray_trd * (x + dlt))]) &&
				(ft_strchr("0NSWE", mlx->prm->map_arr
				[(int)(mlx->pl.player_y + mlx->pl.yray_trd * (x))]
				[(int)(mlx->pl.player_x + mlx->pl.xray_trd * (x + dlt))]) &&
				ft_strchr("0NSWE", mlx->prm->map_arr
				[(int)(mlx->pl.player_y + mlx->pl.yray_trd * (x + dlt))]
				[(int)(mlx->pl.player_x + mlx->pl.xray_trd * (x))])))
				x += dlt;
			else
				dlt = dlt / 10;
		}

		ft_check_wall(mlx, x, dlt * 10, mlx->prm);


		my_mlx_pixel_put(&mlx->img, mlx->pl.player_x * mlx->pl.delta_x,
						 mlx->pl.player_y * mlx->pl.delta_y, 0xFFFFFFFF);

		float t_x, t_y;
		t_x = mlx->pl.player_x + mlx->pl.trend_x * x;
		t_y = mlx->pl.player_y + mlx->pl.trend_y * x;
		float dist;
		dist = sqrt(pow((mlx->pl.player_x - t_x), 2) + pow((mlx->pl.player_y - t_y), 2));
		two_tr = tr + 0.5;
		dist = dist * cos(tr);
		ft_print_line(mlx, dist, two_tr);
		while (x > 0.0)
		{
			my_mlx_pixel_put(&mlx->img,
							 (mlx->pl.player_x + (mlx->pl.trend_x * cos(tr) - mlx->pl.trend_y * sin(tr)) * x) * mlx->pl.delta_x,
							 (mlx->pl.player_y + (mlx->pl.trend_x * sin(tr) + mlx->pl.trend_y * cos(tr)) * x) * mlx->pl.delta_y, 0x00cc9999);
			x = x - 0.1;
		}
		x = 0;
		tr += (1.f / mlx->x_win);
	}
	my_mlx_pixel_put(&mlx->img, (mlx->pl.player_x + mlx->pl.vision_x + mlx->pl.trend_x * 0.7) * mlx->pl.delta_x,
					 (mlx->pl.player_y + mlx->pl.vision_y + mlx->pl.trend_y * 0.7) * mlx->pl.delta_y, 0x00cc0000);
}





