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
#include "cub3d.h"

void        my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}
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
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
                                 &img.endian);
    my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);


    while (y < 100)
    {
        i = 300;
        while (i  < 600 )
        {
            my_mlx_pixel_put(&img, y, i, 0x909900);
            i++;
        }
        y++;
        smesh++;
    }




    while (y < 250)
    {
        i = 200 + smesh;
        while (smesh < i && i  < 700 - smesh)
        {
            my_mlx_pixel_put(&img, y, i, color);
            i++;
        }
        y++;
        smesh++;
        color = color - 0x00000001;
    }
    y = 270;
    smesh--;
    while (y < 420)
    {
        i = 200 + smesh;
        while (smesh > 1 && i  < 700 - smesh)
        {
            my_mlx_pixel_put(&img, y, i, color);
            i++;
        }
        y++;
        smesh--;
        color = color + 0x00000001;
    }
    while (y < 1000)
    {
        i = 300;
        while (i  < 600 )
        {
            my_mlx_pixel_put(&img, y, i, 0x909900);
            i++;
        }
        y++;
        smesh++;
    }

    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    mlx_loop(mlx);
}