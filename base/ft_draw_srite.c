#include "../cub3d.h"


void	ft_img_pos_and_step_sprite(t_mlx *mlx, int line_height, int draw_start)
{
	mlx->wall_img = mlx->s_img;
	mlx->wall.tex_x = (int)(mlx->wall.mod_crd_x * (float)(mlx->wall_img.width));
	mlx->wall.img_step = 1.0 * mlx->wall_img.height / line_height;
	mlx->wall.img_pos = (draw_start - mlx->y_win / 2 + line_height / 2) * mlx->wall.img_step;
}

void 	ft_draw_sprite(t_mlx *mlx, float x1, float y1, int x)
{
	int 	y;
	int 	line_height;
	int 	draw_start;
	int 	draw_end;
	float 	dist;

	//float cos =

	float dist_centr = sqrt((mlx->pl.pl_x - mlx->spr.sp_centr_x) * (mlx->pl.pl_x - mlx->spr.sp_centr_x) +
				(mlx->pl.pl_y - mlx->spr.sp_centr_y) * (mlx->pl.pl_y - mlx->spr.sp_centr_y)) ;
	dist = sqrt((mlx->pl.pl_x - mlx->spr.cross_x) * (mlx->pl.pl_x - mlx->spr.cross_x) +
				(mlx->pl.pl_y - mlx->spr.cross_y) * (mlx->pl.pl_y - mlx->spr.cross_y)) ;
	//dist = dist * (dist_centr / dist * 0.8);
	//dist = sqrt((mlx->pl.pl_x - mlx->spr.sp_centr_x) * (mlx->pl.pl_x - mlx->spr.sp_centr_x) +
				//(mlx->pl.pl_y - mlx->spr.sp_centr_y) * (mlx->pl.pl_y - mlx->spr.sp_centr_y));
	//if (dist > 2)
		dist = dist * cos(mlx->pl.tr);



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
		//if (mlx->wall.color != 0x000000)
			my_mlx_pixel_put(&mlx->img, x, y, mlx->wall.color);
		y++;
	}
}

int 	ft_find_in_circle(t_mlx *mlx, float x1, float y1)
{
	float sp_y1 = (int)y1 + 0.5;/////
	float sp_x1 = (int)x1 + 0.5; ////

	if ((x1 - sp_x1) * (x1 - sp_x1) + (y1 - sp_y1) * (y1 - sp_y1) < 0.5)
		return (1);
	else
		return (0);
}




int 	ft_find_cross_and_dist_to_center(t_mlx *mlx, float x1, float y1)
{
	float sp_y1;
	float sp_x1;
	float sp_y2;
	float sp_x2;

	sp_y1 = (int)y1 + 0.5;/////
	sp_x1 = (int)x1 + 0.5; ////

	sp_y1 = mlx->spr.sp_right_y;
	sp_x1 = mlx->spr.sp_right_x;
	//sp_y2 = sp_y1 - mlx->pl.cam_y * 0.5;  ////меняем на новые
	//sp_x2 = sp_x1 - mlx->pl.cam_x * 0.5; ////меняем на новые
	mlx->spr.sp_centr_y = sp_y1;
	mlx->spr.sp_centr_x = sp_x1;
	sp_y2 = mlx->spr.sp_left_y;  ////меняем на новые
	sp_x2 = mlx->spr.sp_left_x; ////меняем на новые
/*
	float y1 = sp_y1;
	float x1 = sp_x1;
	float y2 = sp_y2;
	float x2 = sp_x2;

	float y3 = mlx->pl.pl_y;
	float x3 = mlx->pl.pl_x;
	float y4 = cell_y;
	float x4 = cell_x;
*/
	/*
	float fi;
	fi = atan(((sp_x1 - mlx->pl.pl_x) / (sp_y1 - mlx->pl.pl_y)));
	sp_x2 = sp_x1 + cos(M_PI / 2 - fi);
	sp_y2 = sp_y1 + sin(M_PI / 2 - fi);
mlx->spr.cross_x =((x1*y2-x2*y1)*(x3-x4)-(x4*y3-y4*x3)*(x1-x2))/((x1-x2)*(y4-y3)-(y1-y2)*(x4-x3));
	mlx->spr.cross_y =((y3-y4)*mlx->spr.cross_x-(x3*y4-x4*y3))/(x4-x3);

	 ///////////////////////// рабочая
	 mlx->spr.cross_x = ((sp_x1 * sp_y2 - sp_y1 * sp_x2) * (x1 - mlx->pl.pl_x) -
						(sp_x1 - sp_x2) * (x1 * mlx->pl.pl_y - y1 * mlx->pl.pl_x)) /
					   ((sp_x1 - sp_x2) * (y1 - mlx->pl.pl_y) - (sp_y1 - sp_y2) * (x1 - mlx->pl.pl_x));

	mlx->spr.cross_y = ((sp_x1 * sp_y2 - sp_y1 * sp_x2) * (y1 - mlx->pl.pl_y) -
						(sp_y1 - sp_y2) * (x1 * mlx->pl.pl_y - y1 * mlx->pl.pl_x)) /
					   ((sp_x1 - sp_x2) * (y1 - mlx->pl.pl_y) - (sp_y1 - sp_y2) * (x1 - mlx->pl.pl_x));


	*/


	float pl_x3 = mlx->pl.pl_x;
	float pl_y3 = mlx->pl.pl_y;
	float pl_x4 = x1;
	float pl_y4 = y1;
	float temp;
	if (sp_x1 >= sp_x2)
	{
		temp = sp_x1;
		sp_x1 = sp_x2;
		sp_x2 = temp;
		temp = sp_y1;
		sp_y1 = sp_y2;
		sp_y2 = temp;

	}
	if (pl_x3 >= pl_x4)
	{
		temp = pl_x3;
		pl_x3 = pl_x4;
		pl_x4 = temp;
		temp = pl_y3;
		pl_y3 = pl_y4;
		pl_y4 = temp;
	}

	mlx->spr.cross_x = ((sp_x1 * sp_y2 - sp_y1 * sp_x2) * (pl_x4 - pl_x3) -
						(sp_x1 - sp_x2) * (pl_x4 * pl_y3 - pl_y4 * pl_x3)) /
					   ((sp_x1 - sp_x2) * (pl_y4 - pl_y3) - (sp_y1 - sp_y2) * (pl_x4 - pl_x3));

	mlx->spr.cross_y = ((sp_x1 * sp_y2 - sp_y1 * sp_x2) * (pl_y4 - pl_y3) -
						(sp_y1 - sp_y2) * (pl_x4 * pl_y3 - pl_y4 * pl_x3)) /
					   ((sp_x1 - sp_x2) * (pl_y4 - pl_y3) - (sp_y1 - sp_y2) * (pl_x4 - pl_x3));


	if ((((sp_x1<=mlx->spr.cross_x) && (sp_x2>=mlx->spr.cross_x) && (pl_x3<=mlx->spr.cross_x) && (pl_x4 >=mlx->spr.cross_x)) ||
	((sp_y1<=mlx->spr.cross_y) && (sp_y2>=mlx->spr.cross_y) && (pl_y3<=mlx->spr.cross_y) && (pl_y4>=mlx->spr.cross_y))))
		return (1);
		//printf(" true mlx->spr.cross_x %f mlx->spr.cross_y %f \n", mlx->spr.cross_x, mlx->spr.cross_y);
	//else
		//printf(" false mlx->spr.cross_x %f mlx->spr.cross_y %f \n", mlx->spr.cross_x, mlx->spr.cross_y);
return (0);

	/*
	float x3 = mlx->pl.pl_x;
	float y3 = mlx->pl.pl_y;
	float x4 = x1;
	float y4 = y1;
	mlx->spr.cross_x = ((sp_x1 * sp_y2 - sp_x2 * sp_y1) * (x4 - x3) -
			(x3 * y4 - x4 * y3) * (sp_x2 - sp_x1)) /
					   ((sp_y1 - sp_y2) * (x4 - x3) - (y3 - y4) * (sp_x2 - sp_x1));


	mlx->spr.cross_y =  ((y3 - y4) * mlx->spr.cross_x - (x3 * y4 - x4 * y3)) / (x4 - x3);

*/

	float test = (mlx->spr.cross_x - mlx->spr.sp_left_x) * (mlx->spr.sp_right_y - mlx->spr.sp_left_y) -
			(mlx->spr.cross_y - mlx->spr.sp_left_y) * (mlx->spr.sp_right_x - mlx->spr.sp_left_x);


	mlx->spr.dist = sqrt(pow((sp_x1 - mlx->spr.cross_x), 2) + pow((sp_y1 - mlx->spr.cross_y), 2));

	mlx->spr.sp_y1 = sp_y1;
	mlx->spr.sp_x1 = sp_x1;
	//mlx->spr.sp_y2 = sp_y2;
	//mlx->spr.sp_x2 = sp_x2;;

}

void  ft_sprite_line(t_mlx *mlx, float x1, float y1)
{
	float bc = 0.49;
	float sp_y1 = (int)y1 + 0.5;///// центр спрайта точка B
	float sp_x1 = (int)x1 + 0.5; ////
////точка A
	////mlx->pl.pl_y
	/// mlx->pl.pl_x

	float x2x1 = mlx->pl.pl_x - sp_x1;
	float y2y1 = mlx->pl.pl_y - sp_y1;
	float ab = (float)sqrt(x2x1 * x2x1 + y2y1 * y2y1);
	float v1x = (sp_x1 - mlx->pl.pl_x) / ab;
	float v1y = (sp_y1 - mlx->pl.pl_y) / ab;
	float v3x = -v1y * bc;
	float v3y = v1x * bc;

	mlx->spr.sp_left_x = sp_x1 - v3x;
	mlx->spr.sp_left_y = sp_y1 - v3y;
	mlx->spr.sp_right_x = sp_x1 + v3x;
	mlx->spr.sp_right_y = sp_y1 + v3y;


}

void	ft_check_sprite(t_mlx *mlx, int x)
{
	float y1;
	float x1;
	float y1_t;
	float x1_t;
	float sp_y1;
	float sp_x1;
	float sp_y2;
	float sp_x2;
	float cross_x;
	float cross_y;

	while (mlx->wall.delta_dist > 0)
	{
		y1 = (mlx->pl.pl_y + mlx->pl.ray_y * (mlx->wall.delta_dist));
		x1 = (mlx->pl.pl_x + mlx->pl.ray_x * (mlx->wall.delta_dist));


		if (mlx->prm->map_arr[(int)y1][(int)x1] == '2') {
			//
			//printf("dist %f\n", mlx->spr.dist);
			if (ft_find_in_circle(mlx, x1, y1)) {
				/////найдем прямую у спрайта
				ft_sprite_line(mlx, x1, y1);
				/*
				ft_find_cross_and_dist_to_center(mlx, x1, y1);
				sp_y1 = mlx->spr.sp_y1;
				sp_x1 = mlx->spr.sp_x1;
				sp_y2 = mlx->spr.sp_y2;
				sp_x2 = mlx->spr.sp_x2;
*/
			if (ft_find_cross_and_dist_to_center(mlx, x1, y1))
			{
				cross_x = mlx->spr.cross_x;
				cross_y = mlx->spr.cross_y;

				mlx->wall.mod_crd_x = sqrt(
						pow((mlx->spr.sp_left_x - cross_x), 2) + pow((mlx->spr.sp_left_y - cross_y), 2));
				ft_draw_sprite(mlx, x1, y1, x);
			}




			}
		}

		while ((int)y1 == (int)(mlx->pl.pl_y + mlx->pl.ray_y * (mlx->wall.delta_dist - 0.4)) &&
				(int)x1 == (int)(mlx->pl.pl_x + mlx->pl.ray_x * (mlx->wall.delta_dist - 0.4)))
			mlx->wall.delta_dist -= 0.4;
		mlx->wall.delta_dist -= 0.1;  /////////разобратся
	}
}
