# include "../cub3d.h"
void 	ft_trend_player(t_mlx *mlx)
{
	mlx->pl.trend_x = 0;
	mlx->pl.trend_y = 0;
	mlx->pl.cam_x = 0;
	mlx->pl.cam_y = 0;
	if (mlx->prm->player == 'N')
	{
		mlx->pl.trend_y = -1;
		mlx->pl.cam_x = tan(M_PI * 90 / 360); /////// 60 угол обзора
	}
	if (mlx->prm->player == 'S')
	{
		mlx->pl.trend_y = 1;
		mlx->pl.cam_x = -tan(M_PI * 90 / 360);
	}
	if (mlx->prm->player == 'W')
	{
		mlx->pl.trend_x = -1;
		mlx->pl.cam_y = -tan(M_PI * 90 /360);
	}
	if (mlx->prm->player == 'E')
	{
		mlx->pl.trend_x = 1;
		mlx->pl.cam_y = tan(M_PI * 90 / 360);
	}
}
int		ft_game_first_param(t_mlx *mlx)
{
	mlx->pl.pl_x = (float)mlx->prm->play_x + 0.5;
	mlx->pl.pl_y = (float)mlx->prm->play_y + 0.5;
	mlx->pl.walk_speed = 0.03;
	mlx->pl.turn_speed = 1 * M_PI / 180; ////// 3 взял от туда
	mlx->exit = 0;
	ft_trend_player(mlx);
	mlx->key.w = 0;
	mlx->key.s = 0;
	mlx->key.a = 0;
	mlx->key.d = 0;
	mlx->key.left = 0;
	mlx->key.right = 0;
	mlx->fov = 60;
	mlx->radian = mlx->fov * M_PI / 180;
	/////// не знаю пока что это такое
	//if (!(mlx->pl.wall_dist_arr = (float*)malloc(sizeof(float) * \
					mlx->x_win_size)))
	//	return (mlx->errcode = 200);


	mlx->half_win = 1;
	return (0);
}