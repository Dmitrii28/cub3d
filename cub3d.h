/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harmida <harmida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 01:24:36 by harmida           #+#    #+#             */
/*   Updated: 2020/09/21 01:24:38 by harmida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define MIN_X_WIN 100
# define MIN_Y_WIN 100

#include "libft/libft.h"
#include "libft/get_next_line.h"
#include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
#include "mlx.h"
#include <math.h> //////////////////////////////



typedef	struct	s_prm
{
    int			x_win;
    int			y_win;
    char		*no_txr;
    char		*so_txr;
    char		*we_txr;
    char		*ea_txr;
    char		*s_txr;
    int			floor;
    int			ceiling;
    int 		count_line;
    char		**map_array;
	char		*line;
	int			exit;
	char		*msg;

    int			gnl_ret;
    int			screenshot;
    int			pars_map_started;
    int			max_mapline_len;
    int			prior_spaces_mapline;
    char		*map_line;
    int			map_row_index;
    int			spawn_point_x;
    int			spawn_point_y;
    char		spawn_orientation;
}				t_prm;




typedef struct  s_data {
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_data;



typedef struct  s_vars {
    void        *mlx;
    void        *win;
}               t_vars;

int		ft_check_args(int argc, char **argv);
int		ft_take_param(t_prm *params);
int 	ft_take_param_2(char *temp, t_prm *params);
int		ft_parser(char *argv, t_prm *params);
int    ft_make_array(t_prm *params, int str_n);

#endif











