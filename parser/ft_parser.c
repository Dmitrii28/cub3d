

#include "../cub3d.h"

int 	ft_check_files(t_param *prm)
{
	int	fd;

	if ((fd = open(prm->no_txr, O_RDONLY)) < 0 || close(fd) < 0)
		return (151);
	if ((fd = open(prm->so_txr, O_RDONLY)) < 0 || close(fd) < 0)
		return (152);
	if ((fd = open(prm->we_txr, O_RDONLY)) < 0 || close(fd) < 0)
		return (153);
	if ((fd = open(prm->ea_txr, O_RDONLY)) < 0 || close(fd) < 0)
		return (154);
	if ((fd = open(prm->s_txr, O_RDONLY)) < 0 || close(fd) < 0)
		return (155);
	if ((ft_check_file(prm->no_txr, "xpm")) == 1)
		return (157);
	if ((ft_check_file(prm->so_txr, "xpm")) == 1)
		return (158);
	if ((ft_check_file(prm->we_txr, "xpm")) == 1)
		return (159);
	if ((ft_check_file(prm->ea_txr, "xpm")) == 1)
		return (160);
	if ((ft_check_file(prm->s_txr, "xpm")) == 1)
		return (161);
	return (0);

}

int 	ft_free_array(char **arr, int str)
{
	while (str >= 0)
	{
		free(arr[str]);
		arr[str] = NULL;
		str--;
	}
	free(arr);
	arr = NULL;
	return (100);
}

int		ft_data_and_map(t_param *prm, int fd)
{
	while ((prm->id = get_next_line(fd, &prm->line)) >= 0)
	{
		if (prm->count_line == 8)
		{
			if ((prm->exit = ft_make_array(prm, prm->str_n)) >= 100)///////
				return (prm->exit); /// обработать ошибк
			prm->str_n = (prm->exit == 0 ? prm->str_n + 1 : prm->str_n);
		}
		printf("                                | # >%d< | | >%d< | >%s<\n", prm->str_n, prm->id, prm->line);
		if (prm->count_line < 8) {
			if (ft_take_param(prm))
				return (prm->exit);
		}
		if (prm->line)
			free(prm->line);
		if (prm->id == 0)
			break ;
		prm->err_n++;
	}
	prm->line = NULL;
	if (prm->id < 0)
		return (prm->exit = prm->id); //// ошибки в ГНЛ -1 и -10
	if (prm->id == 0 && prm->count_line < 8)
		return (prm->exit = 112); ///// мало ссылок на параметры в файле (выяснить чего не хватает?)
	return (prm->exit = 0);
}
int ft_parser(char *argv, t_param *prm)
{
	int		fd;

	if ((prm->fd_err = (fd = open(argv, O_RDONLY))) < 0)   ///// obrabotat oshibky
		return (156);
	if((prm->exit = ft_data_and_map(prm, fd)))
		return (prm->exit);
	if (prm->str_n < 3)
		return (131);
	//if((prm->exit = ft_realloc_line(prm, prm->str_n, prm->m_len)))//////////////////////
		//return (prm->exit);
	if((prm->exit = ft_check_map(prm)))//////////////////////////////
		return (prm->exit);
	if (close(fd) < 0)
		ft_putstr_fd(strerror(errno), fd);


	prm->str_n = 0;
	if (prm->map_arr)
	{
		while (prm->map_arr[prm->str_n] != NULL)
		{
			printf("!!! >%s<\n", prm->map_arr[prm->str_n]);
			prm->str_n++;
		}
	}
	else
		printf("!!! >%s<\n", "exit - массив не создан");
	return (0);
}
