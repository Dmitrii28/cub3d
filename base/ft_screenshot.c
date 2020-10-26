#include "../cub3d.h"

#include <fcntl.h>

static void	ft_make_bmp(t_mlx *mlx, char *header,	char *dib_header, int fd)
{
	int		win_width;

	win_width = mlx->img.bits_per_pixel / 8 * mlx->x_win;
	write(fd, header, 14);
	write(fd, dib_header, 40);
	mlx->y_win--;
	while (mlx->y_win >= 0)
	{
		write(fd, mlx->img.addr + (mlx->y_win * mlx->img.line_len), win_width);
		mlx->y_win--;
	}
	if (close(fd) < 0)
		mlx->prm.exit = 171;
	ft_putstr_fd("Screenshot done\n", 1);
	ft_clear_close(mlx);
}

static void	ft_make_arr(t_mlx *mlx, char *header, char *dib_header)
{
	int		file_size;

	file_size = 54 + mlx->x_win * mlx->y_win * mlx->img.bits_per_pixel / 8;
	ft_memcpy(header, "BM", 2);
	header[2] = (char)(file_size);
	header[3] = (char)(file_size >> 8);
	header[4] = (char)(file_size >> 16);
	header[5] = (char)(file_size >> 24);
	header[10] = (char)(54);

	dib_header[0] = (char)(40);
	dib_header[4] = (char)(mlx->x_win);
	dib_header[5] = (char)(mlx->x_win >> 8);
	dib_header[6] = (char)(mlx->x_win >> 16);
	dib_header[7] = (char)(mlx->x_win >> 24);
	dib_header[8] = (char)(mlx->y_win);
	dib_header[9] = (char)(mlx->y_win >> 8);
	dib_header[10] = (char)(mlx->y_win >> 16);
	dib_header[11] = (char)(mlx->y_win >> 24);
	dib_header[12] = (char)(1);
	dib_header[14] = (char)(mlx->img.bits_per_pixel);
}


void		ft_screenshot(t_mlx *mlx)
{
	char	header[14];
	char	dib_header[40];
	int 	fd;

	ft_bzero(header, 14);
	ft_bzero(dib_header, 40);
	if ((fd = open("screenshot.bmp", O_WRONLY | O_CREAT, 0666)) < 0)
	{
		mlx->prm.fd_err = fd;
		mlx->prm.exit = 170;
		ft_clear_close(mlx);
	}
	ft_print_line(mlx);
	ft_make_arr(mlx, header, dib_header);
	ft_make_bmp(mlx, header, dib_header, fd);
}



