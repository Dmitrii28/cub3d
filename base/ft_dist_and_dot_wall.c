#include "../cub3d.h"

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

	int y_delt = mlx->pl.pl_y + mlx->pl.ray_y * (x + dlt);
	int y_crd = mlx->pl.pl_y + mlx->pl.ray_y * x;
	int x_delt = mlx->pl.pl_x + mlx->pl.ray_x * (x + dlt);
	int x_crd = mlx->pl.pl_x + mlx->pl.ray_x * x;



	if (y_delt < y_crd && prm->map_arr[y_delt][x_crd] == '1')
		mlx->wall.side = 1; // белый север
	if (x_delt > x_crd && prm->map_arr[y_crd][x_delt] == '1')
		mlx->wall.side = 2; //зеленый восток
	if (y_delt > y_crd && prm->map_arr[y_delt][x_crd] == '1')
		mlx->wall.side = 3; //серый юг
	if (x_delt < x_crd && prm->map_arr[y_crd][x_delt] == '1')
		mlx->wall.side = 4; //синий запад
	/*
	if ((int)(py + ry * (x + dlt)) < (int)(py + ry * x) &&
		prm->map_arr[(int)(py + ry * (x + dlt))] [(int)(px + rx * x)] == '1')
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
	 */
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

	//printf("mlx->pl.ray_x %f y %f", mlx->pl.ray_x, mlx->pl.ray_y);
	ft_check_wall(mlx, x, dlt * 10, mlx->prm);
	mlx->wall.delta_dist = x;
}

void	ft_dist_and_dot_wall(t_mlx *mlx, int x)
{
	float tr;

	tr = -mlx->radian * 0.5 + mlx->radian / mlx->x_win * x;
	mlx->pl.ray_x = mlx->pl.trend_x * cos(tr) - mlx->pl.trend_y * sin(tr);
	mlx->pl.ray_y = mlx->pl.trend_x * sin(tr) + mlx->pl.trend_y * cos(tr);
	ft_calc_dist(mlx);
	mlx->wall.crd_x = mlx->pl.pl_x + mlx->pl.ray_x * mlx->wall.delta_dist;
	mlx->wall.crd_y = mlx->pl.pl_y + mlx->pl.ray_y * mlx->wall.delta_dist;
	//dist = sqrt(pow((mlx->pl.pl_x - mlx->wall.crd_x), 2) + pow((mlx->pl.pl_y - mlx->wall.crd_y), 2));
	mlx->wall.dist = mlx->wall.delta_dist  * cos(tr);
	mlx->line_height = (int)(mlx->y_win / mlx->wall.dist);
	if (mlx->line_height % 2 != 0)
		mlx->line_height--;
	mlx->draw_start = -mlx->line_height / 2 + mlx->y_win / 2;
	if (mlx->draw_start < 0)
		mlx->draw_start = 0;
	mlx->draw_end = mlx->line_height / 2 + mlx->y_win / 2;
	if (mlx->draw_end >= mlx->y_win)
		mlx->draw_end = mlx->y_win - 1;
}


