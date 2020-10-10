/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harmida <harmida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 23:19:32 by harmida           #+#    #+#             */
/*   Updated: 2020/09/20 23:19:40 by harmida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <zconf.h>
#include "cub3d.h"

//int             close(int keycode, t_vars *vars)
//{
  //  mlx_destroy_window(vars->mlx, vars->win);
//}
/*
void        my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}
*/
/*
int             main(void)
{
    void    *mlx;
    void    *mlx_win;
    t_data  img;
    int i, y, color, smesh;

    i = 3;
    y = 1;
    color = 0x000000cc;
    smesh = 0;
    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 1020, 1080, "Hello world!");
    img.img = mlx_new_image(mlx, 1020, 1080);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    printf("%d img.bits_per_pixel, %d img.line_length, %d img.endian \n", img.bits_per_pixel, img.line_length, img.endian);

    my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);

    printf("%s", ft_itoa(1000));

    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);

    //mlx_loop(mlx);


}*/
int		ft_prm_fill(t_data *prm)
{
	prm->x_win = -1;
	prm->y_win = -1;
	prm->no_txr = NULL;
	prm->so_txr = NULL;
	prm->we_txr = NULL;
	prm->ea_txr = NULL;
	prm->s_txr = NULL;
	prm->floor = -1;
	prm->ceiling = -1;
	prm->map_array = NULL;
	prm->exit = 0;
	prm->count_line = 0;
	prm->msg = NULL;
	prm->str_n = 0;
	prm->color_arr = NULL;
	prm->player = '0';
	prm->play_x = 0;
	prm->play_y = 0;
	return (0);


}
int			ft_exit(t_data *prm)
{


	if (prm->exit == 114 || prm->exit == 115)
		ft_free_array(prm->color_arr, 2); /////очистка временого массива для пола потолка

	//ft_putstr_fd("Error\ncode #101: ' \n", 2);
	if (prm->msg)
		printf("%s\n", prm->msg);

	printf("error %d\n", prm->exit);

	/*
	ft_free_array(prm->map_array, 5);
//	free(prm.line);

	free(prm->no_txr);
	free(prm->so_txr);
	free(prm->we_txr);
	free(prm->ea_txr);
	free(prm->s_txr);

	*/
	return (prm->exit);
}
int		main(int argc, char **argv)
{
    t_data	prm;

    if ((prm.exit = ft_prm_fill(&prm))) ///////разобраться почему &&&&&&&
		return (ft_exit(&prm));
	if ((prm.exit = ft_check_args(argc, argv)) > 0)
		return (ft_exit(&prm));
	//if ((prm.exit = f_pars_desc_file(argv[1], &opts)))
		//return (f_exit(errcode, &opts));


	if((prm.exit = ft_parser(argv[1], &prm)))
		ft_exit(&prm);
	ft_base(&prm);

	//printf("%d\n", 5 << 10 && 5 << 2);
/*
	ft_free_array(prm.map_array, 5);
//	free(prm.line);

	free(prm.no_txr);
	free(prm.so_txr);
	free(prm.we_txr);
	free(prm.ea_txr);
	free(prm.s_txr);
*/
	return (0);







}


