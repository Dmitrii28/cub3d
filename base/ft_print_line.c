#include "../cub3d.h"

void 	ft_ypos_and_color(t_mlx *mlx)
{
	mlx->wall.tex_y = (int)mlx->wall.img_pos & (mlx->wall_img.height - 1);
	mlx->wall.color = *(int*)(mlx->wall_img.addr + ((mlx->wall.tex_x + (mlx->wall.tex_y * mlx->wall_img.width)) * (mlx->wall_img.bits_per_pixel / 8)));
}

void	ft_img_pos_and_step_sprite(t_mlx *mlx, int line_height, int draw_start)
{
	int 	revers;

	//wall_img = NULL;  ///////надо ли??????
	//if (mlx->pl.ray_y < 1)
		//mlx->wall.mod_crd_x = mlx->wall.crd_x - (int)(mlx->wall.crd_x);
	//else
		//mlx->wall.mod_crd_x = mlx->wall.crd_y - (int)(mlx->wall.crd_y);


	mlx->wall_img = mlx->s_img;


	revers = (mlx->wall.side == 3 || mlx->wall.side == 4) ? 1 : 0;
	if (revers == 1)
		mlx->wall.tex_x = (int)((float)(mlx->wall_img.width) - mlx->wall.mod_crd_x * (float)(mlx->wall_img.width) - 1);
	else
		mlx->wall.tex_x = (int)(mlx->wall.mod_crd_x * (float)(mlx->wall_img.width));
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
	if (mlx->prm->map_arr[(int)(mlx->pl.pl_y + mlx->pl.ray_y * (mlx->wall.delta_dist + 0.001))]
						 [(int)(mlx->pl.pl_x + mlx->pl.ray_x * (mlx->wall.delta_dist + 0.001))] == '2')
	{

		dist = sqrt(pow((mlx->pl.pl_x - (int)(mlx->pl.pl_x + mlx->pl.ray_x * (mlx->wall.delta_dist + 0.00095)) + 0.5), 2) +
						pow((mlx->pl.pl_y - (int)(mlx->pl.pl_y + mlx->pl.ray_y * (mlx->wall.delta_dist + 0.00095)) + 0.5), 2));


		line_height = (int) (mlx->y_win / dist);
		mlx->wall.crd_x = mlx->pl.pl_x + mlx->pl.ray_x * mlx->wall.delta_dist - (int)(mlx->pl.pl_x + mlx->pl.ray_x * mlx->wall.delta_dist);
			// Рассчитываем высоту линии для рисования на экране
			if (dist == 0)
				dist = 0.001;
			line_height = (int)(mlx->y_win / dist);
			// вычисляем самый низкий и самый высокий пиксели для заполнения текущей полосы
			draw_start = -line_height / 2 + mlx->y_win / 2;
			if (draw_start < 0)
				draw_start = 0;
			draw_end = line_height / 2 + mlx->y_win / 2;
			if (draw_end >= mlx->y_win)
				draw_end = mlx->y_win - 1;
			y = draw_start;
			ft_img_pos_and_step_sprite(mlx, line_height, draw_start);
			while (y <= draw_end) {
//////посчитать цвет
				ft_ypos_and_color(mlx);

				mlx->wall.img_pos += mlx->wall.img_step;
				//if (mlx->wall.color != 0x000000)
					my_mlx_pixel_put(&mlx->img, x, y, mlx->wall.color);
				y++;
			}


		}
	mlx->wall.delta_dist--;


	}
}



void 	ft_img_pos_and_step(t_mlx *mlx, int line_height, int draw_start)
{
	int 	revers;

	//wall_img = NULL;  ///////надо ли??????
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
		mlx->wall.tex_x = (int)((float)(mlx->wall_img.width) - mlx->wall.mod_crd_x * (float)(mlx->wall_img.width) - 1);
	else
		mlx->wall.tex_x = (int)(mlx->wall.mod_crd_x * (float)(mlx->wall_img.width));
	mlx->wall.img_step = 1.0 * mlx->wall_img.height / line_height;
	mlx->wall.img_pos = (draw_start - mlx->y_win / 2 + line_height / 2) * mlx->wall.img_step;





}

void 	ft_print_line(t_mlx *mlx, float dist, float tr)
{
	int x;
	int y;
	int line_height;
	int draw_start;
	int draw_end;



	x = (int)(tr * mlx->x_win);
	// Рассчитываем высоту линии для рисования на экране
	if (dist == 0)
		dist = 0.001;

		line_height = (int)(mlx->y_win / dist);
		// вычисляем самый низкий и самый высокий пиксели для заполнения текущей полосы
		draw_start = -line_height / 2 + mlx->y_win / 2;
		if (draw_start < 0)
			draw_start = 0;
		draw_end = line_height / 2 + mlx->y_win / 2;
		if (draw_end >= mlx->y_win)
			draw_end = mlx->y_win - 1;
		y = draw_start;
		ft_img_pos_and_step(mlx, line_height, draw_start);
		while (y <= draw_end)
		{
//////посчитать цвет
			ft_ypos_and_color(mlx);
			mlx->wall.img_pos += mlx->wall.img_step;
			my_mlx_pixel_put(&mlx->img, x, y++, mlx->wall.color);
		}




	ft_check_sprite(mlx, x);




}