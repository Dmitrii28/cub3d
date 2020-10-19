#include "../cub3d.h"
void	ft_forward_and_back(t_mlx *mlx, int trend)
{
	if (ft_strchr("0NSWE", mlx->prm->map_arr[(int)mlx->pl.pl_y]
	[(int)(mlx->pl.pl_x + trend * (mlx->pl.trend_x * (mlx->pl.walk_speed + 0.3)))]))
		mlx->pl.pl_x += trend * (mlx->pl.trend_x * mlx->pl.walk_speed);

//printf(" d %d\n", (int)(mlx->pl.pl_y + trend * (mlx->pl.trend_y * mlx->pl.walk_speed)));
//printf(" cccc %c\n", mlx->prm->map_arr[(int)(mlx->pl.pl_y + trend * (mlx->pl.trend_y * mlx->pl.walk_speed))]
//	[(int)mlx->pl.pl_x]);

	if (ft_strchr("0NSWE",
	mlx->prm->map_arr[(int)(mlx->pl.pl_y + trend * (mlx->pl.trend_y * (mlx->pl.walk_speed + 0.3)))]
	[(int)mlx->pl.pl_x]))
	{


		//printf(" f %f\n", mlx->pl.pl_y);
		mlx->pl.pl_y += trend * (mlx->pl.trend_y * mlx->pl.walk_speed);
		//printf(" f %f\n", mlx->pl.pl_y);



	}

}
void	ft_strafe(t_mlx *mlx, int trend)
{
	if (ft_strchr("0NSWE", mlx->prm->map_arr[(int)mlx->pl.pl_y]
	[(int)(mlx->pl.pl_x + trend * (mlx->pl.vision_x * (mlx->pl.walk_speed + 0.3)))]))
		mlx->pl.pl_x += trend * (mlx->pl.vision_x * mlx->pl.walk_speed);

	if (ft_strchr("0NSWE", mlx->prm->map_arr[(int)(mlx->pl.pl_y + trend * (mlx->pl.vision_y * (mlx->pl.walk_speed + 0.3)))]
	[(int)mlx->pl.pl_x]))
		mlx->pl.pl_y += trend * (mlx->pl.vision_y * mlx->pl.walk_speed);
}
void 	ft_turn(t_mlx *mlx, int trend)
{
	double temp_vision_x;
	double temp_trend_x;

	temp_trend_x = mlx->pl.trend_x;
	mlx->pl.trend_x =
	mlx->pl.trend_x * cos(trend * mlx->pl.turn_speed) - mlx->pl.trend_y * sin(trend * mlx->pl.turn_speed);


	mlx->pl.trend_y =
	temp_trend_x * sin(trend * mlx->pl.turn_speed) + mlx->pl.trend_y * cos(trend * mlx->pl.turn_speed);



	temp_vision_x = mlx->pl.vision_x;

	mlx->pl.vision_x =
	mlx->pl.vision_x * cos(trend * mlx->pl.turn_speed) - mlx->pl.vision_y * sin(trend * mlx->pl.turn_speed);

	mlx->pl.vision_y =
	temp_vision_x * sin(trend * mlx->pl.turn_speed) + mlx->pl.vision_y * cos(trend * mlx->pl.turn_speed);

}
int 	ft_key_scan(t_mlx *mlx)
{
	mlx_do_sync(mlx->mlx_ptr);
	if (mlx->key.w && !mlx->key.s)
		ft_forward_and_back(mlx, 1);
	if (!mlx->key.w && mlx->key.s)
		ft_forward_and_back(mlx, -1);
	if (mlx->key.a && !mlx->key.d)
		ft_strafe(mlx, -1);
	if (!mlx->key.a && mlx->key.d)
		ft_strafe(mlx, 1);
	if (mlx->key.left && !mlx->key.right)
		ft_turn(mlx, -1);
	if (!mlx->key.left && mlx->key.right)
		ft_turn(mlx, 1);
	ft_full_window(mlx);
	return (0);
}