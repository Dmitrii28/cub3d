#include "../cub3d.h"

static	void	ft_img_pos_and_step_sprite(t_mlx *mlx, int line_height, int draw_start)
{
	mlx->wall_img = mlx->s_img;
	mlx->wall.tex_x = (int)(mlx->wall.mod_crd_x * (float)(mlx->wall_img.width));
	mlx->wall.img_step = 1.0 * mlx->wall_img.height / line_height;
	mlx->wall.img_pos = (draw_start - mlx->y_win / 2 + line_height / 2) *
		mlx->wall.img_step;
}

static	void 	ft_draw_sprite(t_mlx *mlx, int x)
{
	int 	y;
	int 	line_height;
	int 	draw_start;
	int 	draw_end;
	float 	dist;

	dist = sqrt((mlx->pl.pl_x - mlx->spr.crs_x) *
		(mlx->pl.pl_x - mlx->spr.crs_x) + (mlx->pl.pl_y - mlx->spr.crs_y) *
		(mlx->pl.pl_y - mlx->spr.crs_y)) * cos(mlx->pl.tr * 0.9);
	line_height = (int)(mlx->y_win / dist);
	line_height -= line_height % 2 != 0 ? 1 : 0;
	draw_start = (-line_height / 2 + mlx->y_win / 2 < 0) ? 0 :
				 (-line_height / 2 + mlx->y_win / 2);
	draw_end = (line_height / 2 + mlx->y_win / 2 >= mlx->y_win) ?
				mlx->y_win - 1 : (line_height / 2 + mlx->y_win / 2);
	y = draw_start;
	ft_img_pos_and_step_sprite(mlx, line_height, draw_start);
	while (y <= draw_end)
	{
		ft_ypos_and_color(mlx);
		mlx->wall.img_pos += mlx->wall.img_step;
		if (mlx->wall.color != 0x000000)
			my_mlx_pixel_put(&mlx->img, x, y, mlx->wall.color);
		y++;
	}
}

static	int 	ft_find_crs_and_dist_to_center(t_mlx *mlx, float ray_x, float ray_y)
{
	mlx->spr.crs_x = ((mlx->spr.right_x * mlx->spr.lft_y - mlx->spr.right_y *
			mlx->spr.lft_x) * (ray_x - mlx->pl.pl_x) - (mlx->spr.right_x -
			mlx->spr.lft_x) * (ray_x * mlx->pl.pl_y - ray_y * mlx->pl.pl_x)) /
			((mlx->spr.right_x - mlx->spr.lft_x) * (ray_y - mlx->pl.pl_y) -
			(mlx->spr.right_y - mlx->spr.lft_y) * (ray_x - mlx->pl.pl_x));
	mlx->spr.crs_y = ((mlx->spr.right_x * mlx->spr.lft_y - mlx->spr.right_y *
			mlx->spr.lft_x) * (ray_y - mlx->pl.pl_y) - (mlx->spr.right_y -
			mlx->spr.lft_y) * (ray_x * mlx->pl.pl_y - ray_y * mlx->pl.pl_x)) /
			((mlx->spr.right_x - mlx->spr.lft_x) * (ray_y - mlx->pl.pl_y) -
			(mlx->spr.right_y - mlx->spr.lft_y) * (ray_x - mlx->pl.pl_x));
	mlx->spr.cntr_to_crs = ((mlx->spr.centr_x - mlx->spr.crs_x) *
			(mlx->spr.centr_x - mlx->spr.crs_x) + (mlx->spr.centr_y -
			mlx->spr.crs_y) * (mlx->spr.centr_y - mlx->spr.crs_y));
	if (mlx->spr.cntr_to_crs > 0.25)
		return (0);
	else
		mlx->spr.cntr_to_crs = sqrt(mlx->spr.cntr_to_crs);
	mlx->wall.mod_crd_x = sqrt(pow((mlx->spr.lft_x - mlx->spr.crs_x), 2) +
		pow((mlx->spr.lft_y - mlx->spr.crs_y), 2));
	return (1);
}

static	void  ft_sprite_line(t_mlx *mlx, float ray_x, float ray_y)
{
	float ab;
	float v1x;
	float v1y;
	float v3x;
	float v3y;

	mlx->spr.centr_y = (int)ray_y + 0.5;
	mlx->spr.centr_x = (int)ray_x + 0.5;
	ab = sqrt(((mlx->pl.pl_x - mlx->spr.centr_x) * (mlx->pl.pl_x -
		mlx->spr.centr_x)) + ((mlx->pl.pl_y - mlx->spr.centr_y) *
		(mlx->pl.pl_y - mlx->spr.centr_y)));
	v1x = (mlx->spr.centr_x - mlx->pl.pl_x) / ab;
	v1y = (mlx->spr.centr_y - mlx->pl.pl_y) / ab;
	v3x = -v1y * 0.5;
	v3y = v1x * 0.5;
	mlx->spr.lft_x = mlx->spr.centr_x - v3x;
	mlx->spr.lft_y = mlx->spr.centr_y - v3y;
	mlx->spr.right_x = mlx->spr.centr_x + v3x;
	mlx->spr.right_y = mlx->spr.centr_y + v3y;
}

void	ft_check_sprite(t_mlx *mlx, int x)
{
	float y1;
	float x1;

	while (mlx->wall.delta_dist > 0.1) {
		y1 = (mlx->pl.pl_y + mlx->pl.ray_y * (mlx->wall.delta_dist));
		x1 = (mlx->pl.pl_x + mlx->pl.ray_x * (mlx->wall.delta_dist));
		if (mlx->prm->map_arr[(int) y1][(int) x1] == '2')
		{
			ft_sprite_line(mlx, x1, y1);
			if (ft_find_crs_and_dist_to_center(mlx, x1, y1))
				ft_draw_sprite(mlx, x);
		}
		while ((int)y1 == (int)(mlx->pl.pl_y + mlx->pl.ray_y *
			(mlx->wall.delta_dist - 0.4)) && (int)x1 == (int)(mlx->pl.pl_x +
			mlx->pl.ray_x * (mlx->wall.delta_dist - 0.4)))
				mlx->wall.delta_dist -= 0.4;
		mlx->wall.delta_dist -= 0.1;
	}
}