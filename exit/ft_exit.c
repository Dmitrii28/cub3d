#include "../cub3d.h"


int			ft_close(t_mlx *mlx)
{
	/////t_sp		*sp_tmp;


	if (mlx->win_ptr)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);

	/*
	if (mlx->sp_list)
	{
		while (mlx->sp_list)
		{
			sp_tmp = mlx->sp_list->next;
			free(mlx->sp_list);
			mlx->sp_list = sp_tmp;
		}
	}
*/

	free(mlx->mlx_ptr);
	exit(ft_exit(mlx));
}