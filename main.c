/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harmida <harmida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 23:19:32 by harmida           #+#    #+#             */
/*   Updated: 2020/09/20 23:19:40 by harmida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <zconf.h>
#include "cub3d.h"

int		ft_prm_fill(t_mlx * mlx, t_param *prm)
{
	prm->x_win = -1;
	prm->y_win = -1;
	prm->no_txr = NULL;
	prm->so_txr = NULL;
	prm->we_txr = NULL;
	prm->ea_txr = NULL;
	prm->s_txr = NULL;
	prm->floor = -1;
	prm->ceiling = -1;
	prm->map_arr = NULL;
	prm->exit = 0;
	prm->count_line = 0;
	prm->str_n = 0;
	prm->m_len = 0;
	prm->color_arr = NULL;
	prm->line = NULL;
	prm->player = '0';
	prm->play_x = 0;
	prm->play_y = 0;
	prm->screenshot = 0;
	prm->err_n = 0;
	prm->id = 0;
	prm->fd_err = 0;
	mlx->win_ptr = NULL;
	mlx->mlx_ptr = NULL;
}

int		main(int argc, char **argv)
{
    t_mlx mlx;

    ft_prm_fill(&mlx, &mlx.prm);
	if ((mlx.prm.fd_err = ft_check_args(argc, argv)) != 0)
	{
		mlx.prm.exit = 156;
		return (ft_clear_close(&mlx.prm));
	}
	if ((mlx.prm.exit = ft_parser(argv[1], &mlx.prm)))
		return (ft_clear_close(&mlx.prm));
	if ((mlx.prm.exit = ft_check_files(&mlx.prm)))
		return (ft_clear_close(&mlx.prm));
	if (argc == 3)
		mlx.prm.screenshot = 1;
	ft_base(&mlx);
	return (0);
}
