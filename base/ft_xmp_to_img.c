#include "../cub3d.h"

int 	ft_img_id_to_addr(t_mlx *mlx)
{
	if (!(mlx->no_img.addr = mlx_get_data_addr(mlx->no_img.img_ptr,
		&mlx->no_img.bits_per_pixel, &mlx->no_img.line_len,
		&mlx->no_img.endian)))
		return (206);
	if (!(mlx->so_img.addr = mlx_get_data_addr(mlx->so_img.img_ptr,
		&mlx->so_img.bits_per_pixel, &mlx->so_img.line_len,
		&mlx->so_img.endian)))
		return (207);
	if (!(mlx->we_img.addr = mlx_get_data_addr(mlx->we_img.img_ptr,
		&mlx->we_img.bits_per_pixel, &mlx->we_img.line_len,
		&mlx->we_img.endian)))
		return (208);
	if (!(mlx->ea_img.addr = mlx_get_data_addr(mlx->ea_img.img_ptr,
		&mlx->ea_img.bits_per_pixel, &mlx->ea_img.line_len,
		&mlx->ea_img.endian)))
		return (209);
	if (!(mlx->s_img.addr = mlx_get_data_addr(mlx->s_img.img_ptr,
		&mlx->s_img.bits_per_pixel, &mlx->s_img.line_len,
		&mlx->s_img.endian)))
		return (210);
	printf("img ------------------------------------------------ %d\n", mlx->so_img.addr[2232]);
	printf("img   %d\n", mlx->s_img.line_len);
	printf("img   %d\n", mlx->no_img.height);
	printf("img   %d\n", mlx->s_img.bits_per_pixel);
	return (0);
}

int 	ft_xpm_to_img(t_mlx *mlx)
{
	if (!(mlx->no_img.img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr,
	   mlx->prm->no_txr, &mlx->no_img.width, &mlx->no_img.height)))
		return (200);
	if (!(mlx->so_img.img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr,
	   mlx->prm->so_txr, &mlx->so_img.width, &mlx->so_img.height)))
		return (201);
	if (!(mlx->we_img.img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr,
	   mlx->prm->we_txr, &mlx->we_img.width, &mlx->we_img.height)))
		return (202);
	if (!(mlx->ea_img.img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr,
	   mlx->prm->ea_txr, &mlx->ea_img.width, &mlx->ea_img.height)))
		return (203);
	if (!(mlx->s_img.img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr,
	  mlx->prm->s_txr, &mlx->s_img.width, &mlx->s_img.height)))
		return (204);
	return (ft_img_id_to_addr(mlx));
}