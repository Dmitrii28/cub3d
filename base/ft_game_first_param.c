# include "../cub3d.h"
void 	ft_trend_player(t_mlx *mlx)
{
	mlx->game.trend_x = 0;
	mlx->game.trend_y = 0;
	mlx->game.vision_x = 0;
	mlx->game.vision_y = 0;
	if (mlx->prm->player == 'N')
	{
		mlx->game.trend_y = -1;
		mlx->game.vision_x = tan(M_PI * 66 / 360); /////// 60 угол обзора
	}
	if (mlx->prm->player == 'S')
	{
		mlx->game.trend_y = 1;
		mlx->game.vision_x = -tan(M_PI * 66 / 360);
	}
	if (mlx->prm->player == 'W')
	{
		mlx->game.trend_x = -1;
		mlx->game.vision_y = -tan(M_PI * 66 /360);
	}
	if (mlx->prm->player == 'E')
	{
		mlx->game.trend_x = 1;
		mlx->game.vision_y = tan(M_PI * 66 / 360);
	}
}
int		ft_game_first_param(t_mlx *mlx)
{
	mlx->game.player_x = (float)mlx->prm->play_x + 0.5;
	mlx->game.player_y = (float)mlx->prm->play_y + 0.5;
	mlx->game.walk_speed = 0.1;
	mlx->game.turn_speed = 2 * M_PI / 180; ////// 3 взял от туда
	mlx->exit = 0;
	ft_trend_player(mlx);
	mlx->key.w = 0;
	mlx->key.s = 0;
	mlx->key.a = 0;
	mlx->key.d = 0;
	mlx->key.left = 0;
	mlx->key.right = 0;
	/////// не знаю пока что это такое
	//if (!(mlx->game.wall_dist_arr = (float*)malloc(sizeof(float) * \
					mlx->x_win_size)))
	//	return (mlx->errcode = 200);



	return (0);
}