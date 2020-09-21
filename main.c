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
    int i;

    i = 3;
    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 520, 580, "Hello world!");
    img.img = mlx_new_image(mlx, 520, 580);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
                                 &img.endian);
    my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
    while (i < 400)
    {
        my_mlx_pixel_put(&img, sqrt(i) + i , i, 0x00FF0000 + i + 150);
        i++;
    }

    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    mlx_loop(mlx);
}