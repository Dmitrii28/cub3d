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

# define XK_MISCELLANY
#  define XK_LATIN1
#  include <X11/keysymdef.h>

#  define KEY_ESC XK_Escape
#  define KEY_W XK_w
#  define KEY_A XK_a
#  define KEY_S XK_s
#  define KEY_D XK_d
#  define KEY_M XK_m
#  define KEY_LEFT XK_Left
#  define KEY_RIGHT XK_Right
#  define KEY_MINUS XK_minus
#  define KEY_PLUS XK_equal
#  define KEY_SHIFT_L XK_Shift_L
#  define KEY_SPACE XK_space

# define MIN_X_WIN 100
# define MIN_Y_WIN 100

#include "libft/libft.h"
#include "libft/get_next_line.h"
#include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
#include "mlx_linux/mlx.h"
#include <math.h> //////////////////////////////

typedef struct  s_img
{
	void        *img;
	char        *addr;
	int         bits_per_pixel;
	int         line_length;
	int         endian;
}               t_img;
typedef struct	s_key
{
	int			w;
	int			a;
	int			s;
	int			d;
	int			left;
	int			right;
}				t_key;

typedef struct	s_game
{
	float		start_pl_x;
	float 		start_pl_y;
	float 		delta_x; //////////////////////////////////////// нада ???????
	float 		delta_y;

	float		player_x;
	float		player_y;
	float		walk_speed;
	float		turn_speed;
	float		trend_x;
	float		trend_y;
	float		old_trend_x;
	float		old_trend_y;
	double		vision_x;
	double		vision_y;

	float		*wall_dist_arr;

	float		old_plane_x;
	float		old_plane_y;
}				t_game;

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
	int 		play_x;
	int 		play_y;
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

typedef struct	s_mlx
{
	t_data		*prm;
	int			exit;
	int			x_resolut;
	int			y_resolut;


	void		*mlx_ptr;
	void		*win_ptr;
	int			x_win;
	int			y_win;
	t_img		img;
	t_game		game;
	t_key		key;
/*	t_sdf		*opts;

	t_img		no_tex;
	t_img		so_tex;
	t_img		we_tex;
	t_img		ea_tex;
	t_img		sp_tex;
	t_game		game;
	t_sp		*sp_list;
	*/

}				t_mlx;


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
int		ft_make_array(t_data *prm, int str_n);
int 	ft_free_array(char **arr, int str);
int 	ft_chek_textur(t_data *prm);
int		ft_check_file(char *argv, char *extension);
int		ft_check_map(t_data *prm);
int		ft_exit(t_data *prm);


void 	ft_base(t_data *prm);
int		ft_key_on(int key, t_mlx *mlx);
int		ft_key_off(int key, t_mlx *mlx);
int 	ft_key_scan(t_mlx *mlx);
int		ft_game_first_param(t_mlx *mlx);
int		ft_full_window(t_mlx *mlx);
void 	ft_draw_map(t_mlx *mlx);
void	ft_put_player(t_mlx *mlx);
void		ft_draw_sky(t_mlx *mlx);
#endif











