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

int		ft_prm_fill(t_data *prm)
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
	prm->color_arr = NULL;
	prm->player = '0';
	prm->play_x = 0;
	prm->play_y = 0;
	prm->screenshot = 0;
}
int			ft_exit(t_data *prm)
{




	//ft_putstr_fd("Error\ncode #101: ' \n", 2);


	printf("exit %d\n", prm->exit);

	/*
	ft_free_array(prm->map_arr, 5);
//	free(prm.line);

	free(prm->no_txr);
	free(prm->so_txr);
	free(prm->we_txr);
	free(prm->ea_txr);
	free(prm->s_txr);

	*/
	if (prm->exit < 0)
	{
		///// напечатать ошибку
		ft_putstr_fd(strerror(errno), 2);
	}
		return (prm->exit);
}
int		main(int argc, char **argv)
{
    t_data	prm;

    ft_prm_fill(&prm);
	if ((prm.exit = ft_check_args(argc, argv)) > 0)
		return (ft_exit(&prm));
	if ((prm.exit = ft_parser(argv[1], &prm)))
		return (ft_exit(&prm));
	if ((prm.exit = ft_check_files(&prm)))
		return (ft_exit(&prm));
	if (argc == 3)
		prm.screenshot = 1;
	ft_base(&prm);
	return (0);
}


