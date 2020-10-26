#include "../cub3d.h"

static	void 	ft_check_wall(t_mlx *mlx, float x, float dlt, t_param *prm)
{
	int y_delt;
	int y_crd;
	int x_delt;
	int x_crd;

	y_delt = mlx->pl.pl_y + mlx->pl.ray_y * (x + dlt);
	y_crd = mlx->pl.pl_y + mlx->pl.ray_y * x;
	x_delt = mlx->pl.pl_x + mlx->pl.ray_x * (x + dlt);
	x_crd = mlx->pl.pl_x + mlx->pl.ray_x * x;
	if (y_delt < y_crd && prm->map_arr[y_delt][x_crd] == '1')
		mlx->wall.side = 1;
	if (x_delt > x_crd && prm->map_arr[y_crd][x_delt] == '1')
		mlx->wall.side = 2;
	if (y_delt > y_crd && prm->map_arr[y_delt][x_crd] == '1')
		mlx->wall.side = 3;
	if (x_delt < x_crd && prm->map_arr[y_crd][x_delt] == '1')
		mlx->wall.side = 4;
}

static	void 	ft_calc_dist(t_mlx *mlx)
{
	float 	dlt;
	float 	x;

	dlt = 0.9;
	x = 0;
	while (dlt >= 0.0009)
	{
		if (ft_strchr("0NSWE2", mlx->prm.map_arr
			[(int)(mlx->pl.pl_y + mlx->pl.ray_y * (x + dlt))]
			[(int)(mlx->pl.pl_x + mlx->pl.ray_x * (x + dlt))]) &&
			(ft_strchr("0NSWE2", mlx->prm.map_arr
			[(int)(mlx->pl.pl_y + mlx->pl.ray_y * (x))]
			[(int)(mlx->pl.pl_x + mlx->pl.ray_x * (x + dlt))]) &&
			ft_strchr("0NSWE2", mlx->prm.map_arr
			[(int)(mlx->pl.pl_y + mlx->pl.ray_y * (x + dlt))]
			[(int)(mlx->pl.pl_x + mlx->pl.ray_x * (x))])))
			x += dlt;
		else
			dlt = dlt / 10;
	}
	ft_check_wall(mlx, x, dlt * 10, &mlx->prm);
	mlx->wall.delta_dist = x;
}

void	ft_dist_and_dot_wall(t_mlx *mlx, int x)
{
	float tr;

	tr = -(mlx->radian * 0.5) + mlx->radian / mlx->x_win * x;
	mlx->pl.tr = tr;
	mlx->pl.ray_x = mlx->pl.trend_x * cos(tr) - mlx->pl.trend_y * sin(tr);
	mlx->pl.ray_y = mlx->pl.trend_x * sin(tr) + mlx->pl.trend_y * cos(tr);
	ft_calc_dist(mlx);


	//printf("x %f y %f \n", mlx->pl.pl_x, mlx->pl.pl_y);



	mlx->wall.crd_x = mlx->pl.pl_x + mlx->pl.ray_x * mlx->wall.delta_dist;
	mlx->wall.crd_y = mlx->pl.pl_y + mlx->pl.ray_y * mlx->wall.delta_dist;
	mlx->wall.dist = sqrt((mlx->pl.pl_x - mlx->wall.crd_x) * (mlx->pl.pl_x -
		mlx->wall.crd_x) + (mlx->pl.pl_y - mlx->wall.crd_y) *
		(mlx->pl.pl_y - mlx->wall.crd_y)) * cos(tr);
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
