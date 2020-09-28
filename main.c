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

void        my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

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
int		ft_params_fill(t_prm *params)
{
	params->x_win = -1;
	params->y_win = -1;
	params->no_txr = NULL;
	params->so_txr = NULL;
	params->we_txr = NULL;
	params->ea_txr = NULL;
	params->s_txr = NULL;
	params->floor = -1;
	params->ceiling = -1;
	params->map_array = NULL;
	params->exit = 0;
	params->count_line = 0;
	params->msg = NULL;


	return (0);


}
int			ft_exit(int exit, t_prm *params)
{
	printf("error %d\n", params->exit);



	//ft_putstr_fd("Error\ncode #101: ' \n", 2);
	if (params->msg)
		printf("%s\n", params->msg);
}
int		main(int argc, char **argv)
{
    t_prm	params;

    if ((params.exit = ft_params_fill(&params)) > 0)
        return (ft_exit(params.exit, &params));
	if ((params.exit = ft_check_args(argc, argv)) > 0)
		return (ft_exit(params.exit, &params));
	//if ((params.exit = f_pars_desc_file(argv[1], &opts)))
		//return (f_exit(errcode, &opts));


	if((params.exit = parser(argv[1], &params)))
		return (ft_exit(params.exit, &params));


	//printf("%d\n", 5 << 10 && 5 << 2);


	return (0);







}


