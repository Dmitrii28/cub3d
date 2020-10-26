#include "../cub3d.h"
int			ft_exit(t_param *prm)
{

	if (prm->map_arr)
		ft_free_array(prm->map_arr, prm->str_n - 1);

	printf("exit %d\n", prm->exit);


	free((prm->no_txr) ? prm->no_txr : NULL);
	free((prm->so_txr) ? prm->so_txr : NULL);
	free((prm->we_txr) ? prm->we_txr : NULL);
	free((prm->ea_txr) ? prm->ea_txr : NULL);
	free((prm->s_txr) ? prm->s_txr : NULL);
	free((prm->line) ? prm->line : NULL);

	printf("str %d\n",  prm->str_n);

	printf("ошибка str %d\n",  prm->err_n);

	//return (errcode);


	if (prm->exit < 0)
	{
		///// напечатать ошибку
		ft_putstr_fd(strerror(errno), 2); /////////вставить fd
	}
	return (prm->exit);
}

int			ft_clear_close(t_mlx *mlx)
{
	if (mlx->win_ptr)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);

	free(mlx->mlx_ptr);



	exit(ft_exit(mlx->prm));
}