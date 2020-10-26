#include "../cub3d.h"

int			ft_clear_close(t_mlx *mlx)
{
	if (mlx->win_ptr)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	if (mlx->mlx_ptr)
		free(mlx->mlx_ptr);
	if (mlx->prm.map_arr)
		ft_free_array(mlx->prm.map_arr, mlx->prm.str_n - 1);
	free((mlx->prm.no_txr) ? mlx->prm.no_txr : NULL);
	free((mlx->prm.so_txr) ? mlx->prm.so_txr : NULL);
	free((mlx->prm.we_txr) ? mlx->prm.we_txr : NULL);
	free((mlx->prm.ea_txr) ? mlx->prm.ea_txr : NULL);
	free((mlx->prm.s_txr) ? mlx->prm.s_txr : NULL);
	free((mlx->prm.line) ? mlx->prm.line : NULL);

	ft_error(mlx->prm);


	printf("exit %d\n", mlx->prm.exit);
	printf("str %d\n",  mlx->prm.str_n);
	printf("ошибка str %d\n",  mlx->prm.err_n);
	if (mlx->prm.exit < 0)
	{
		///// напечатать ошибку
		ft_putstr_fd(strerror(errno), 2); /////////вставить fd
	}



	exit(mlx->prm.exit);
	return (0);
}