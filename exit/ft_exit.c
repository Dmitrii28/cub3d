#include "../cub3d.h"
int			ft_exit(t_param *prm)
{




	//ft_putstr_fd("Error\ncode #101: ' \n", 2);


	printf("exit %d\n", prm->exit);


	//ft_free_array(prm->map_arr, 5);
//	free(prm.line);

	free((prm->no_txr) ? prm->no_txr : NULL);
	free((prm->so_txr) ? prm->so_txr : NULL);
	free((prm->we_txr) ? prm->we_txr : NULL);
	free((prm->ea_txr) ? prm->ea_txr : NULL);
	free((prm->s_txr) ? prm->s_txr : NULL);


	printf("str %d\n",  prm->str_n);


	if (prm->map_arr)
		ft_free_array(prm->map_arr, prm->str_n - 1);
	printf("ошибка str %d\n",  prm->err_n);

	//return (errcode);


	if (prm->exit < 0)
	{
		///// напечатать ошибку
		ft_putstr_fd(strerror(errno), 2);
	}
	return (prm->exit);
}

int			ft_close(t_mlx *mlx)
{
	/////t_sp		*sp_tmp;


	if (mlx->win_ptr)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);

	free(mlx->mlx_ptr);
	exit(ft_exit(mlx->prm));
}