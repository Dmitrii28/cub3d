#include "../cub3d.h"

int				ft_key_on(int key, t_mlx *mlx)
{
	/*if (key == KEY_ESC)
		f_close_n_exit(mlx);
	else */if (key == KEY_W)
		mlx->key.w = 1;
	else if (key == KEY_A)
		mlx->key.a = 1;
	else if (key == KEY_S)
		mlx->key.s = 1;
	else if (key == KEY_D)
		mlx->key.d = 1;
	else if (key == KEY_LEFT)
		mlx->key.left = 1;
	else if (key == KEY_RIGHT)
		mlx->key.right = 1;
	else if (key == KEY_SHIFT_L)
		mlx->key.shift = 1;
	return (0);

}

int				ft_key_off(int key, t_mlx *mlx)
{
	if (key == KEY_W)
		mlx->key.w = 0;
	else if (key == KEY_A)
		mlx->key.a = 0;
	else if (key == KEY_S)
		mlx->key.s = 0;
	else if (key == KEY_D)
		mlx->key.d = 0;
	else if (key == KEY_LEFT)
		mlx->key.left = 0;
	else if (key == KEY_RIGHT)
		mlx->key.right = 0;
	else if (key == KEY_SHIFT_L)
		mlx->key.shift = 0;
	return (0);
}
