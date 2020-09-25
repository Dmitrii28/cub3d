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


#include "libft/libft.h"
#include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
#include "mlx.h"
#include <math.h> //////////////////////////////

typedef	struct	s_prm
{
    int			x_win_size;
    int			y_win_size;
    char		*no_txr;
    char		*so_txr;
    char		*we_txr;
    char		*ea_txr;
    char		*sp_txr;
    int			floor_txr;
    int			ceiling_txr;
    char		**map_array;
	char		*line;
	int			exit;



    int			gnl_ret;
    int			screenshot;
    int			pars_map_started;
    int			max_mapline_len;
    int			prior_spaces_mapline;

    char		*err_str;

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



#endif











