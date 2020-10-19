#include "../cub3d.h"
void 	ft_ft_temp(t_mlx *mlx)
{
	if (mlx->wall.side == 1)
		mlx->wall.color = 0xffffff; // белый север
	if (mlx->wall.side == 2)
	 	mlx->wall.color = 0x009900; //зеленый восток
	if (mlx->wall.side == 3)
	 	mlx->wall.color = 0x000099; //синий юг
	if (mlx->wall.side == 4)
	 	mlx->wall.color = 0x999999; //серый запад
	if (mlx->wall.side == 5)
		mlx->wall.color = 0xf1001f; //
}


void 	ft_check_wall(t_mlx *mlx, float x, float dlt, t_data *prm)
{
	float	py;
	float	px;
	float	ry;
	float	rx;

	//////// переделать в инты и заменить все операции точками их 4 штуки тоже


	py = mlx->pl.pl_y;
	px = mlx->pl.pl_x;
	ry = mlx->pl.ray_y;
	rx = mlx->pl.ray_x;
	if ((int)(py + ry * (x + dlt)) < (int)(py + ry * x) &&
		prm->map_arr[(int)(py + ry * (x + dlt))][(int)(px + rx * x)] == '1')
		mlx->wall.side = 1; // белый север
	if ((int)(px + rx * (x + dlt)) > (int)(px + rx * x) &&
		prm->map_arr[(int)(py + ry * x)][(int)(px + rx * (x + dlt))] == '1')
		mlx->wall.side = 2; //зеленый восток
	if ((int)(py + ry * (x + dlt)) > (int)(py + ry * x) &&
		prm->map_arr[(int)(py + ry * (x + dlt))][(int)(px + rx * x)] == '1')
		mlx->wall.side = 3; //серый юг
	if ((int)(px + rx * (x + dlt)) < (int)(px + rx * x) &&
		prm->map_arr[(int)(py + ry * (x))][(int)(px + rx * (x + dlt))] == '1')
		mlx->wall.side = 4; //синий запад
		/*
	if (prm->map_arr[(int)(py + ry * x)][(int)(px + rx * (x + dlt))] == '2' ||
		prm->map_arr[(int)(py + ry * (x + dlt))][(int)(px + rx * x)] == '2')
		mlx->wall.side = 5; //спрайт
		 */
	//ft_ft_temp(mlx);
}









void 	ft_calc_dist(t_mlx *mlx)
{
	float 	dlt;
	float 	x;

	dlt = 0.95;
	x = 0;
	while (dlt >= 0.00095)
	{
		if (ft_strchr("0NSWE2", mlx->prm->map_arr
		[(int)(mlx->pl.pl_y + mlx->pl.ray_y * (x + dlt))]
		[(int)(mlx->pl.pl_x + mlx->pl.ray_x * (x + dlt))]) &&
			(ft_strchr("0NSWE2", mlx->prm->map_arr
			[(int)(mlx->pl.pl_y + mlx->pl.ray_y * (x))]
			[(int)(mlx->pl.pl_x + mlx->pl.ray_x * (x + dlt))]) &&
			 ft_strchr("0NSWE2", mlx->prm->map_arr
			 [(int)(mlx->pl.pl_y + mlx->pl.ray_y * (x + dlt))]
			 [(int)(mlx->pl.pl_x + mlx->pl.ray_x * (x))])))
			x += dlt;
		else
			dlt = dlt / 10;
	}
	ft_check_wall(mlx, x, dlt * 10, mlx->prm);
	mlx->wall.delta_dist = x;
}

void	ft_dist_and_dot_wall(t_mlx *mlx)
{
	double tr;
	float two_tr;
	float dist;

	tr = -0.5;
	while (tr <= 0.5)
	{
		mlx->pl.ray_x = mlx->pl.trend_x * cos(tr) - mlx->pl.trend_y * sin(tr);
		mlx->pl.ray_y = mlx->pl.trend_x * sin(tr) + mlx->pl.trend_y * cos(tr);
		ft_calc_dist(mlx);
		mlx->wall.crd_x = mlx->pl.pl_x + mlx->pl.ray_x * mlx->wall.delta_dist;
		mlx->wall.crd_y = mlx->pl.pl_y + mlx->pl.ray_y * mlx->wall.delta_dist;
		dist = sqrt(pow((mlx->pl.pl_x - mlx->wall.crd_x), 2) + pow((mlx->pl.pl_y - mlx->wall.crd_y), 2));
		two_tr = tr + 0.5;
		dist = dist * cos(tr);
		//printf(" dist %f delta dist %f \n", dist, mlx->wall.delta_dist);
		ft_print_line(mlx, dist, two_tr);


		//printf("vi_x1 %f vi_y1 %f \n", mlx->pl.vision_x * 0.5, mlx->pl.vision_y * 0.5 ) ;

		//mlx->pl.vision_x = mlx->pl.vision_x + (mlx->pl.trend_x * 0.5);
		//mlx->pl.vision_y = mlx->pl.vision_y + (mlx->pl.trend_y * 0.5);
		my_mlx_pixel_put(&mlx->img, mlx->pl.pl_x * mlx->pl.delta_x,
						 mlx->pl.pl_y * mlx->pl.delta_y, 0xFFFFFFFF);

		my_mlx_pixel_put(&mlx->img, (mlx->pl.pl_x + mlx->pl.vision_x * 0.5) * mlx->pl.delta_x,
						 (mlx->pl.pl_y + mlx->pl.vision_y * 0.5) * mlx->pl.delta_y, 0x00FF00);
		my_mlx_pixel_put(&mlx->img, (mlx->pl.pl_x - mlx->pl.vision_x * 0.5) * mlx->pl.delta_x,
						 (mlx->pl.pl_y - mlx->pl.vision_y * 0.5) * mlx->pl.delta_y, 0x00FF00);


		float dist3 = sqrt(pow((mlx->pl.pl_x - (mlx->pl.pl_x + mlx->pl.vision_x * 0.5)), 2) +
					pow((mlx->pl.pl_y - (mlx->pl.pl_y + mlx->pl.vision_y * 0.5)), 2));



		//printf("dist3 %f \npl_x %f pl_y %f \nvi_x %f vi_y %f \n", dist3,
		//	   mlx->pl.pl_x, mlx->pl.pl_y, mlx->pl.vision_x, mlx->pl.vision_y ) ;


		while (mlx->wall.delta_dist > 0.0)
		{
			my_mlx_pixel_put(&mlx->img,
			(mlx->pl.pl_x + mlx->pl.ray_x * mlx->wall.delta_dist) * mlx->pl.delta_x,
			(mlx->pl.pl_y + mlx->pl.ray_y * mlx->wall.delta_dist) * mlx->pl.delta_y, 0x00cc9999);
			mlx->wall.delta_dist = mlx->wall.delta_dist - 0.1;
		}
		tr += (1.f / mlx->x_win);
	}
	ft_draw_srite(mlx);
}


