#include "../cub3d.h"

void 	ft_ypos_and_color(t_mlx *mlx)
{
	mlx->wall.tex_y = (int)mlx->wall.img_pos & (mlx->wall_img.height - 1);
	mlx->wall.color = *(int*)(mlx->wall_img.addr + ((mlx->wall.tex_x +
		(mlx->wall.tex_y * mlx->wall_img.width)) *
		(mlx->wall_img.bits_per_pixel / 8)));
}

static	void 	ft_img_pos_and_step(t_mlx *mlx, int line_height, int draw_start)
{
	int 	revers;

	if (mlx->wall.side == 1 || mlx->wall.side == 3)
		mlx->wall.mod_crd_x = mlx->wall.crd_x - (int)(mlx->wall.crd_x);
	else
		mlx->wall.mod_crd_x = mlx->wall.crd_y - (int)(mlx->wall.crd_y);
	if (mlx->wall.side == 1)
		mlx->wall_img = mlx->no_img;
	else if (mlx->wall.side == 2)
		mlx->wall_img = mlx->ea_img;
	else if (mlx->wall.side == 3)
		mlx->wall_img = mlx->so_img;
	else if (mlx->wall.side == 4)
		mlx->wall_img = mlx->we_img;
	revers = (mlx->wall.side == 3 || mlx->wall.side == 4) ? 1 : 0;
	if (revers == 1)
		mlx->wall.tex_x = (int)((float)(mlx->wall_img.width) -
		mlx->wall.mod_crd_x * (float)(mlx->wall_img.width) - 1);
	else
		mlx->wall.tex_x = (int)(mlx->wall.mod_crd_x *
			(float)(mlx->wall_img.width));
	mlx->wall.img_step = 1.0 * mlx->wall_img.height / line_height;
	mlx->wall.img_pos = (draw_start - mlx->y_win / 2 + line_height / 2) *
						mlx->wall.img_step;
}

void 	ft_print_line(t_mlx *mlx)
{
	int x;
	int y;

	x = 0;
	while (x <= mlx->x_win)
	{
		ft_dist_and_dot_wall(mlx, x);
		y = 0;
		while (y < mlx->draw_start)
			my_mlx_pixel_put(&mlx->img, x, y++, mlx->prm->ceiling);
		ft_img_pos_and_step(mlx, mlx->line_height, mlx->draw_start);
		while (y <= mlx->draw_end)
		{
			ft_ypos_and_color(mlx);
			mlx->wall.img_pos += mlx->wall.img_step;
			my_mlx_pixel_put(&mlx->img, x, y++, mlx->wall.color);
		}
		y--;
		while (y < mlx->y_win)
			my_mlx_pixel_put(&mlx->img, x, y++, mlx->prm->floor);
		ft_check_sprite(mlx, x);
		x++;
	}
}