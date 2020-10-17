#include "../cub3d.h"
void 	ft_check_wall(t_mlx *mlx, float x, float tr)
{
	if ((int)(mlx->pl.player_y + (mlx->pl.trend_x * sin(tr) + mlx->pl.trend_y * cos(tr)) * (x + 0.0005))
		< (int)(mlx->pl.player_y + (mlx->pl.trend_x * sin(tr) + mlx->pl.trend_y * cos(tr)) * (x))
		&&
		mlx->prm->map_array
		[(int)(mlx->pl.player_y + (mlx->pl.trend_x * sin(tr) + mlx->pl.trend_y * cos(tr)) * (x + 0.0005))]
		[(int)(mlx->pl.player_x + (mlx->pl.trend_x * cos(tr) - mlx->pl.trend_y * sin(tr)) * (x))]
		== '1'
			)
		mlx->pl.color = 0xffffff; // черный

	if (
			((int)(mlx->pl.player_x + (mlx->pl.trend_x * cos(tr) - mlx->pl.trend_y * sin(tr)) * (x + 0.0005))
			 > (int)(mlx->pl.player_x + (mlx->pl.trend_x * cos(tr) - mlx->pl.trend_y * sin(tr)) * (x))
			 &&
			 mlx->prm->map_array
			 [(int)(mlx->pl.player_y + (mlx->pl.trend_x * sin(tr) + mlx->pl.trend_y * cos(tr)) * (x))]
			 [(int)(mlx->pl.player_x + (mlx->pl.trend_x * cos(tr) - mlx->pl.trend_y * sin(tr)) * (x + 0.0005))]
			 == '1'
			))
		mlx->pl.color = 0x009900; //зеленый
	if (
			((int)(mlx->pl.player_x + (mlx->pl.trend_x * cos(tr) - mlx->pl.trend_y * sin(tr)) * (x + 0.0005))
			 < (int)(mlx->pl.player_x + (mlx->pl.trend_x * cos(tr) - mlx->pl.trend_y * sin(tr)) * (x))
			 &&
			 mlx->prm->map_array
			 [(int)(mlx->pl.player_y + (mlx->pl.trend_x * sin(tr) + mlx->pl.trend_y * cos(tr)) * (x))]
			 [(int)(mlx->pl.player_x + (mlx->pl.trend_x * cos(tr) - mlx->pl.trend_y * sin(tr)) * (x + 0.0005))]
			 == '1'
			)
			)
		mlx->pl.color = 0x000099; //синий
	if (
			((int)(mlx->pl.player_y + (mlx->pl.trend_x * sin(tr) + mlx->pl.trend_y * cos(tr)) * (x + 0.0005))
			 > (int)(mlx->pl.player_y + (mlx->pl.trend_x * sin(tr) + mlx->pl.trend_y * cos(tr)) * (x))
			 &&
			 mlx->prm->map_array
			 [(int)(mlx->pl.player_y + (mlx->pl.trend_x * sin(tr) + mlx->pl.trend_y * cos(tr)) * (x + 0.0005))]
			 [(int)(mlx->pl.player_x + (mlx->pl.trend_x * cos(tr) - mlx->pl.trend_y * sin(tr)) * (x))]
			 == '1'
			)
			)
		mlx->pl.color = 0x999999; //серый
}
void 	ft_verline(t_mlx *mlx, float tr, int drawStart, int drawEnd)
{
	int new_tr = tr * mlx->x_win;
	while (drawStart < drawEnd)
	{
		my_mlx_pixel_put(&mlx->img, new_tr, drawStart, mlx->pl.color);
		drawStart++;
	}
}

int 	ft_print_line(t_mlx *mlx, float perpWallDist, float tr)
{
	int new_tr;
	int line_height;
	int draw_start;
	int draw_end;

	new_tr = tr * mlx->x_win;
	// Рассчитываем высоту линии для рисования на экране
	if (perpWallDist == 0)
		perpWallDist = 0.0001;
	line_height =  (int)(mlx->y_win / perpWallDist);

	// вычисляем самый низкий и самый высокий пиксели для заполнения текущей полосы
	draw_start = -line_height / 2 + mlx->y_win / 2;
	if (draw_start < 0 )
		draw_start = 0;
	draw_end = line_height / 2 + mlx->y_win / 2;
	if (draw_end >= mlx->y_win)
		draw_end = mlx->y_win - 1;
	while (draw_start <= draw_end)
	{
		mlx->pl.color++;
		my_mlx_pixel_put(&mlx->img, new_tr, draw_start, mlx->pl.color);
		draw_start++;
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
		while (dlt > 0.00009)
		{
			if (ft_strchr("0NSWE", mlx->prm->map_array
				[(int)(mlx->pl.player_y + mlx->pl.yray_trd * (x + dlt))]
				[(int)(mlx->pl.player_x + mlx->pl.xray_trd * (x + dlt))]) &&
				(ft_strchr("0NSWE", mlx->prm->map_array
				[(int)(mlx->pl.player_y + mlx->pl.yray_trd * (x))]
				[(int)(mlx->pl.player_x + mlx->pl.xray_trd * (x + dlt))]) &&
				ft_strchr("0NSWE", mlx->prm->map_array
				[(int)(mlx->pl.player_y + mlx->pl.yray_trd * (x + dlt))]
				[(int)(mlx->pl.player_x + mlx->pl.xray_trd * (x))])))
				x += dlt;
			else
				dlt = dlt / 10;
		}

		ft_check_wall(mlx, x, tr);
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





