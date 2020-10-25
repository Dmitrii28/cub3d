#include "../cub3d.h"

int				ft_key_on(int key, t_mlx *mlx)
{
	if (key == KEY_ESC)
		ft_clear_close(mlx);
	if (key == KEY_W)
		mlx->key.w = 1;
	if (key == KEY_A)
		mlx->key.a = 1;
	if (key == KEY_S)
		mlx->key.s = 1;
	if (key == KEY_D)
		mlx->key.d = 1;
	if (key == KEY_LEFT)
		mlx->key.left = 1;
	if (key == KEY_RIGHT)
		mlx->key.right = 1;
	return (0);
}

int				ft_key_off(int key, t_mlx *mlx)
{
	if (key == KEY_W)
		mlx->key.w = 0;
	if (key == KEY_A)
		mlx->key.a = 0;
	if (key == KEY_S)
		mlx->key.s = 0;
	if (key == KEY_D)
		mlx->key.d = 0;
	if (key == KEY_LEFT)
		mlx->key.left = 0;
	if (key == KEY_RIGHT)
		mlx->key.right = 0;
	return (0);
}
