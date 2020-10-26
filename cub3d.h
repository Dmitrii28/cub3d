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


#include <errno.h>

#define MLX_SYNC_IMAGE_WRITABLE		1
#define MLX_SYNC_WIN_FLUSH_CMD		2
#define MLX_SYNC_WIN_CMD_COMPLETED	3








#  define KEY_ESC XK_Escape
#  define KEY_W XK_w
#  define KEY_A XK_a
#  define KEY_S XK_s
#  define KEY_D XK_d
#  define KEY_LEFT XK_Left
#  define KEY_RIGHT XK_Right


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
	void        *img_ptr;
	char        *addr;
	int         bits_per_pixel;
	int         line_len;
	int         endian;
	int			width;
	int 		height;
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

typedef struct	s_player
{
	float		pl_x;
	float		pl_y;
	float		walk_speed;
	float		turn_speed;
	float		trend_x;
	float		trend_y;
	float 		ray_x;
	float 		ray_y;
	float 		tr;
	double		cam_x;
	double		cam_y;
}				t_player;

typedef	struct	s_param
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
    char		**map_arr;
	char		*line;
	int 		m_len;
	int			exit;
	int 		str_n;
	char 		**color_arr;
	int 		play_x;
	int 		play_y;
	char		player;
	int 		screenshot;
	int 		err_n;
	int 		id;
	int 		fd_err;
}				t_param;

typedef struct	s_wall
{
	int 		side;
	int			color;
	float 		delta_dist;
	float 		crd_x;
	float 		crd_y;
	float 		mod_crd_x;
	float 		dist;
	float 		img_step;
	float 		img_pos;
	int 		tex_x;
	int 		tex_y;

}				t_wall;
typedef struct	s_spr
{
	float		centr_y;
	float		centr_x;
	float		lft_y;
	float		lft_x;
	float		right_y;
	float		right_x;
	float 		crs_x;
	float 		crs_y;
	float 		cntr_to_crs;
}				t_spr;

typedef struct	s_mlx
{
	t_param		prm;
	t_img		img;
	t_img		wall_img;
	t_img		no_img;
	t_img		so_img;
	t_img		we_img;
	t_img		ea_img;
	t_img		s_img;
	t_wall		wall;
	t_spr		spr;
	t_player	pl;
	t_key		key;
	void		*mlx_ptr;
	void		*win_ptr;
	int			x_win;
	int			y_win;
	int 		fov;
	float 		radian;
	int			line_height;
	int 		draw_start;
	int 		draw_end;
}				t_mlx;

int		ft_check_args(int argc, char **argv);
int		ft_take_param(t_param *prm);
int 	ft_take_param_2(char *temp, t_param *prm);
int		ft_parser(char *argv, t_param *prm);
int 	ft_check_files(t_param *prm);
int		ft_make_array(t_param *prm, int str_n);
int 	ft_free_array(char **arr, int str);
int		ft_check_file(char *argv, char *extension);
int		ft_check_map(t_param *prm);


int 	ft_base(t_mlx *mlx);
int		ft_key_on(int key, t_mlx *mlx);
int		ft_key_off(int key, t_mlx *mlx);
int 	ft_key_scan(t_mlx *mlx);
void		ft_game_first_param(t_mlx *mlx);
void	ft_dist_and_dot_wall(t_mlx *mlx, int x);
int 	ft_xpm_to_img(t_mlx *mlx);
void        my_mlx_pixel_put(t_img *img, int x, int y, int color);
void 	ft_print_line(t_mlx *mlx);
void 	ft_y_pos_and_color(t_mlx *mlx);
void	ft_check_sprite(t_mlx *mlx, int x);
int			ft_clear_close(t_mlx *mlx);
void		ft_screenshot(t_mlx *mlx);
void	ft_error(t_param *prm);
#endif











