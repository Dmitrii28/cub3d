#include "../cub3d.h"

#include <fcntl.h>

static char	*f_get_filename(t_mlx *mlx)
{
	int		fd;
	char	*filename;
	char	*name_index;
	char	*tmp;
	int		i;

	i = 2;
	filename = ft_strdup("screenshot.bmp");
	while ((fd = open(filename, O_RDONLY)) > 0)
	{
		free(filename);
		if (close(fd) < 0)
			mlx->exit = 500;
		if (mlx->exit)
			return (NULL);
		if (!(name_index = ft_itoa(i++)) || \
			!(tmp = ft_strjoin("screenshot_", name_index)) || \
			!(filename = ft_strjoin(tmp, ".bmp")))
			mlx->exit = 200;
		free((name_index) ? name_index : NULL);
		free((tmp) ? tmp : NULL);
		if (!filename)
			return (NULL);
	}
	return (filename);
}

static int	f_bmp_image_write(t_mlx *mlx, char *bitmap_file_header, \
															char *dib_header)
{
	int		fd;
	char	*filename;
	int		i;
	int		win_width;

	i = 0;
	win_width = mlx->img.bits_per_pixel / 8 * mlx->x_win;
	if (!(filename = f_get_filename(mlx)))
		return (mlx->exit);
	if ((fd = open(filename, O_RDWR | O_CREAT, 0664)) < 0)
		return (fd);
	write(fd, bitmap_file_header, 14);
	write(fd, dib_header, 40);
	while (i < mlx->y_win)
		write(fd, mlx->img.addr + i++ * mlx->img.line_len, win_width);
	ft_putstr_fd(filename, 1);
	ft_putstr_fd(" saved\n", 1);
	free(filename);
	return (close(fd) < 0) ? 320 : 0;
}

static void	f_bmp_headers_generate(t_mlx *mlx, char *bitmap_file_header, \
															char *dib_header)
{
	int		file_size;

	file_size = 14 + 40 + mlx->x_win * mlx->y_win * \
			mlx->img.bits_per_pixel / 8;
	bitmap_file_header[0] = 'B';
	bitmap_file_header[1] = 'M';
	bitmap_file_header[2] = (char)(file_size);
	bitmap_file_header[3] = (char)(file_size >> 8);
	bitmap_file_header[4] = (char)(file_size >> 16);
	bitmap_file_header[5] = (char)(file_size >> 24);
	bitmap_file_header[10] = (char)(14 + 40);
	dib_header[0] = (char)(40);
	dib_header[4] = (char)(mlx->x_win);
	dib_header[5] = (char)(mlx->x_win >> 8);
	dib_header[6] = (char)(mlx->x_win >> 16);
	dib_header[7] = (char)(mlx->x_win >> 24);
	dib_header[8] = (char)(-mlx->y_win);
	dib_header[9] = (char)(-mlx->y_win >> 8);
	dib_header[10] = (char)(-mlx->y_win >> 16);
	dib_header[11] = (char)(-mlx->y_win >> 24);
	dib_header[12] = (char)(1);
	dib_header[14] = (char)(mlx->img.bits_per_pixel);
}


void		ft_screenshot(t_mlx *mlx)
{
	char	bitmap_file_header[14];
	char	dib_header[40];

	//ft_bzero(bitmap_file_header, 14);
	//ft_bzero(dib_header, 40);
	ft_print_line(mlx);
	f_bmp_headers_generate(mlx, bitmap_file_header, dib_header);
	mlx->exit = f_bmp_image_write(mlx, bitmap_file_header, dib_header);
	//f_close_n_exit(mlx);
}



