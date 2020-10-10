#include "../cub3d.h"
void	ft_forward_and_back(t_mlx *mlx, int trend)
{
	if (ft_strchr("0NSWE", mlx->prm->map_array[(int)mlx->game.player_y]
	[(int)(mlx->game.player_x + trend * (mlx->game.trend_x * mlx->game.walk_speed))]))
		mlx->game.player_x += trend * (mlx->game.trend_x * mlx->game.walk_speed);

	if (ft_strchr("0NSWE", mlx->prm->map_array[(int)(mlx->game.player_y + trend * (mlx->game.trend_y * mlx->game.walk_speed))]
	[(int)mlx->game.player_x]))
		mlx->game.player_y += trend * (mlx->game.trend_y * mlx->game.walk_speed);
}
void	ft_strafe(t_mlx *mlx, int trend)
{
	if (ft_strchr("0NSWE", mlx->prm->map_array[(int)mlx->game.player_y]
	[(int)(mlx->game.player_x + trend * (mlx->game.player_x * mlx->game.walk_speed))]))
		mlx->game.player_x += trend * (mlx->game.vision_x * mlx->game.walk_speed);

	if (ft_strchr("0NSWE", mlx->prm->map_array[(int)(mlx->game.player_y + trend * (mlx->game.vision_y * mlx->game.turn_speed))]
	[(int)mlx->game.player_x]))
		mlx->game.player_y += trend * (mlx->game.vision_y * mlx->game.walk_speed);
}
void 	ft_turn(t_mlx *mlx, int trend)
{
	float temp_vision_x;
	float temp_trend_x;

	temp_trend_x = mlx->game.trend_x;
	mlx->game.trend_x = mlx->game.trend_x * cos(trend * mlx->game.turn_speed) - mlx->game.trend_y * sin(trend * mlx->game.turn_speed);
	mlx->game.trend_y = temp_trend_x * sin(trend * mlx->game.turn_speed) + mlx->game.trend_y * cos(trend * mlx->game.turn_speed);
	temp_vision_x = mlx->game.vision_x;
	mlx->game.vision_x = mlx->game.vision_x * cos(trend * mlx->game.turn_speed) - mlx->game.vision_y * sin(trend * mlx->game.turn_speed);
	mlx->game.vision_y = temp_vision_x * sin(trend * mlx->game.turn_speed) + mlx->game.vision_y * cos(trend * mlx->game.turn_speed);

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