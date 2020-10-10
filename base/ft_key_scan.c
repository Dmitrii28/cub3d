#include "../cub3d.h"
void	ft_forward_back(t_mlx *mlx, int trend)
{
	if (ft_strchr("0NSWE", mlx->prm->map_array[(int)mlx->game.player_y]
	[(int)(mlx->game.player_x + trend * (mlx->game.trend_x * mlx->game.walk_speed))]))
		mlx->game.player_x += trend * (mlx->game.trend_x * mlx->game.walk_speed);



	if (ft_strchr("0NSWE", mlx->prm->map_array[(int)(mlx->game.player_y + trend * (mlx->game.trend_y * mlx->game.walk_speed))]
	[(int)mlx->game.player_x]))
		mlx->game.player_y += trend * (mlx->game.trend_y * mlx->game.walk_speed);
}
int 	ft_key_scan(t_mlx *mlx)
{
	mlx_do_sync(mlx->mlx_ptr);
	if (mlx->key.w && !mlx->key.s)
		ft_forward_back(mlx, 1);
	ft_full_window(mlx);
	return (0);
}