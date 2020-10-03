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



typedef	struct	s_data
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
	int 		str_n;
	char 		**color_arr;
	int 		player_x;
	int 		player_y;
	char		player;

    int			gnl_ret;
    int			screenshot;
    int			pars_map_started;
    int			max_mapline_len;
    int			prior_spaces_mapline;
    int			map_row_index;
    int			spawn_point_x;
    int			spawn_point_y;
}				t_data;




typedef struct  s_d {
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_d;



typedef struct  s_vars {
    void        *mlx;
    void        *win;
}               t_vars;

int		ft_check_args(int argc, char **argv);
int		ft_take_param(t_data *prm);
int 	ft_take_param_2(char *temp, t_data *prm);
int		ft_parser(char *argv, t_data *prm);
int    ft_make_array(t_data *prm, int str_n);
int 	ft_free_array(char **arr, int str);
int 	ft_chek_textur(t_data *prm);
int		ft_check_file(char *argv, char *extension);
int		ft_check_map(t_data *prm);


#endif











