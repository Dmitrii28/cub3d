

#include "../cub3d.h"

int 	ft_check_files(t_data *prm)
{
	int	fd;

	if ((fd = open(prm->no_txr, O_RDONLY)) < 0 || close(fd))
		return (151);
	if ((fd = open(prm->so_txr, O_RDONLY)) < 0 || close(fd))
		return (152);
	if ((fd = open(prm->we_txr, O_RDONLY)) < 0 || close(fd))
		return (153);
	if ((fd = open(prm->ea_txr, O_RDONLY)) < 0 || close(fd))
		return (154);
	if ((fd = open(prm->s_txr, O_RDONLY)) < 0 || close(fd))
		return (155);
	if (ft_check_file(prm->no_txr, "xpm"))
		return (157);
	if (ft_check_file(prm->so_txr, "xpm"))
		return (158);
	if (ft_check_file(prm->we_txr, "xpm"))
		return (159);
	if (ft_check_file(prm->ea_txr, "xpm"))
		return (160);
	if (ft_check_file(prm->s_txr, "xpm"))
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
	return (100);
}

int		ft_realloc_line(t_data *prm, int str_n, int max_width)
{
	int		i;
	int 	n;
	char    **temp;

	n = 0;
	if (!(temp = (char**)malloc(((str_n) + 1) * sizeof(char *))))
		return (100); ////// ошибка маллока
	while (n < str_n)
	{
		if (!(temp[n] = (char*)malloc((max_width + 1) * sizeof(char))))
			return (ft_free_array(temp, n - 1)); /////// возвращает 100 ошибка маллока
		i = 0;
		while (prm->map_arr[n][i])
		{
			temp[n][i++] = prm->map_arr[n][i];
		}
		while (i < max_width)
			temp[n][i++] = ' ';
		temp[n++][i] = '\0';
	}
	temp[n] = NULL;
	ft_free_array(prm->map_arr, n - 1);
	prm->map_arr = temp;
	temp = NULL;
	return (0);
}

int		ft_data_and_map(t_data *prm, int fd)
{
	int 	id;

	while ((id = get_next_line(fd, &prm->line)) >= 0)
	{
		printf("                                | # >%d< | | >%d< | >%s<\n", prm->str_n, id, prm->line);
		if (prm->count_line == 8)
		{
			if ((prm->exit = ft_make_array(prm, prm->str_n)) >= 100)
				return (prm->exit); /// обработать ошибк
			prm->str_n = (prm->exit == 0 ? prm->str_n + 1 : prm->str_n);
			if (prm->line)
				free(prm->line);
		}
		if (prm->count_line < 8)
			if ((prm->exit = ft_take_param(prm)))
				return (prm->exit);
		if (prm->count_line == 8 && !prm->str_n && (prm->exit = ft_textr(prm)))
			return (prm->exit);
		if (id == 0)
			break ;
	}
	if (id == 0 && prm->count_line < 8)
		return (prm->exit = 112); ///// мало ссылок на параметры в файле (выяснить чего не хватает?)
	return (prm->exit = 0);
}
int ft_parser(char *argv, t_data *prm)
{
	int		fd;
	int		max_width;
	int 	temp_width;
	int 	i;

	i = 0;
	max_width = 0;
	if ((fd = open(argv, O_RDONLY)) < 0)   ///// obrabotat oshibky
		return (fd);
	if((prm->exit = ft_data_and_map(prm, fd)))
		return (prm->exit);
	if (prm->str_n < 3)
		return (131);
	while (prm->str_n > i)
	{
		printf("------- str %d prm->map_arr >%s<\n", i, prm->map_arr[i]);////////////////
		temp_width = ft_strlen(prm->map_arr[i]);
		max_width = (max_width < temp_width) ? temp_width : max_width;
		i++;
	}
	if((prm->exit = ft_realloc_line(prm, i, max_width)))
		return (prm->exit);
	if((prm->exit = ft_check_map(prm)))
		return (prm->exit);

	printf("!!! NO >%s<\n", prm->no_txr);
	printf("!!! SO >%s<\n", prm->so_txr);
	printf("!!! WE >%s<\n", prm->we_txr);
	printf("!!! EA >%s<\n", prm->ea_txr);
	printf("!!! S >%s<\n", prm->s_txr);
	printf("x-win %d\n", prm->x_win);
	printf("y-win %d\n", prm->y_win);
	printf("floor %x\n", prm->floor);
	printf("ceiling %x\n", prm->ceiling);
	prm->str_n = 0;
	if (prm->map_arr)
	{
		while (prm->map_arr[prm->str_n] != NULL)
		{
			//printf("!!! >%s<\n", prm->map_arr[prm->str_n]);
			prm->str_n++;
		}
	}
	else
		printf("!!! >%s<\n", "exit - массив не создан");
	return ((close(fd) < 0) ? 150 : 0);
}
