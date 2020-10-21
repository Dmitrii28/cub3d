#include "../cub3d.h"

void 	ft_ypos_and_color(t_mlx *mlx)
{
	mlx->wall.tex_y = (int)mlx->wall.img_pos & (mlx->wall_img.height - 1);
	mlx->wall.color = *(int*)(mlx->wall_img.addr + ((mlx->wall.tex_x + (mlx->wall.tex_y * mlx->wall_img.width)) * (mlx->wall_img.bits_per_pixel / 8)));
}

void	ft_img_pos_and_step_sprite(t_mlx *mlx, int line_height, int draw_start)
{
	mlx->wall_img = mlx->s_img;
	mlx->wall.tex_x = (int)((float)(mlx->wall_img.width) - mlx->wall.mod_crd_x * (float)(mlx->wall_img.width) - 1);
	mlx->wall.img_step = 1.0 * mlx->wall_img.height / line_height;
	mlx->wall.img_pos = (draw_start - mlx->y_win / 2 + line_height / 2) * mlx->wall.img_step;
}

void	ft_check_sprite(t_mlx *mlx, int x)
{
	int line_height;
	float dist;
	int y;
	int draw_start;
	int draw_end;

	while (mlx->wall.delta_dist > 0)
	{
		float y1 = (mlx->pl.pl_y + mlx->pl.ray_y * (mlx->wall.delta_dist));
		float x1 = (mlx->pl.pl_x + mlx->pl.ray_x * (mlx->wall.delta_dist));
		if (mlx->prm->map_arr[(int)y1][(int)x1] == '2' ) {
		/////  прямая спрайта
		float sp_y1 = (int) y1 + 0.5;
		float sp_x1 = (int) x1 + 0.5;
		float sp_y2 = sp_y1 + mlx->pl.vision_y * 0.5;
		float sp_x2 = sp_x1 + mlx->pl.vision_x * 0.5;
		//// луч от игрока
		/////первая точка сам игрок
		float pl_y3 = y1;
		float pl_x3 = x1;
		float x_per = ((sp_x1 * sp_y2 - sp_y1 * sp_x2) * (pl_x3 - mlx->pl.pl_x) -
					   (sp_x1 - sp_x2) * (pl_x3 * mlx->pl.pl_y - pl_y3 * mlx->pl.pl_x)) /
					  ((sp_x1 - sp_x2) * (pl_y3 - mlx->pl.pl_y) - (sp_y1 - sp_y2) * (pl_x3 - mlx->pl.pl_x));
		float y_per = ((sp_x1 * sp_y2 - sp_y1 * sp_x2) * (pl_y3 - mlx->pl.pl_y) -
					   (sp_y1 - sp_y2) * (pl_x3 * mlx->pl.pl_y - pl_y3 * mlx->pl.pl_x)) /
					  ((sp_x1 - sp_x2) * (pl_y3 - mlx->pl.pl_y) - (sp_y1 - sp_y2) * (pl_x3 - mlx->pl.pl_x));
		float dist_per_to_centr = 1;
		if (((y_per - (int)y_per) > 0.3 && (y_per - (int)y_per) < 0.7) ||
			((x_per - (int)x_per) > 0.3 && (x_per - (int)x_per) < 0.7 ))
		 dist_per_to_centr = sqrt(pow((sp_x1 - x_per), 2) + pow((sp_y1 - y_per), 2));
		if (dist_per_to_centr <= 0.5)
		{
			mlx->wall.mod_crd_x = sqrt(pow((sp_x2 - x_per), 2) + pow((sp_y2 - y_per), 2));
	printf("\n vis dist %f \n", sqrt(pow((sp_y1 - sp_y1 + mlx->pl.vision_x * 0.5), 2) + pow((sp_y1 - sp_y1 + mlx->pl.vision_y * 0.5), 2)));
			////// растояние от игрока до центра спрайта
			////dist = sqrt(pow((mlx->pl.pl_x - (int)x1 + 0.5), 2) + pow((mlx->pl.pl_y - (int)y1 + 0.5), 2));
/////////////////
////////////////
			dist = sqrt(pow((mlx->pl.pl_x - sp_x1), 2) + pow((mlx->pl.pl_y - sp_y1), 2));
			line_height = (int) (mlx->y_win / dist);
			if (line_height % 2 != 0)
				line_height--;
			draw_start = -line_height / 2 + mlx->y_win / 2 ;
			if (draw_start < 0)
				draw_start = 0;
			draw_end = line_height / 2 + mlx->y_win / 2 ;
			if (draw_end >= mlx->y_win)
				draw_end = mlx->y_win - 1;
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
	}
	if ((int)(mlx->pl.pl_y + mlx->pl.ray_y * (mlx->wall.delta_dist)) ==
	(int)(mlx->pl.pl_y + mlx->pl.ray_y * (mlx->wall.delta_dist - 0.49)))
		mlx->wall.delta_dist -= 0.49;
	mlx->wall.delta_dist -= 0.49;
	}
}

void 	ft_img_pos_and_step(t_mlx *mlx, int line_height, int draw_start)
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
		mlx->wall.tex_x = (int)(mlx->wall.mod_crd_x * (float)(mlx->wall_img.width));
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
		while (y < mlx->y_win)
			my_mlx_pixel_put(&mlx->img, x, y++, mlx->prm->floor);
		ft_check_sprite(mlx, x);
		x++;
	}
}