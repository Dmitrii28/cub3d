

#include "../cub3d.h"



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
	if (!(temp = (char**)malloc((str_n) * sizeof(char *))))
		return (100); ////// ошибка маллока
	while (n < str_n)
	{
		if (!(temp[n] = (char*)malloc((max_width + 1) * sizeof(char))))
			return (ft_free_array(temp, n - 1)); /////// возвращает 100 ошибка маллока
		i = 0;
		while (prm->map_arr[n][i])
		{
			temp[n][i] = prm->map_arr[n][i];
			i++;
		}
		while (i < max_width)
			temp[n][i++] = ' ';
		temp[n++][i] = '\0';
	}
	temp[n] = NULL;
	ft_free_array(prm->map_arr, n);
	prm->map_arr = temp;
	temp = NULL;
	return (0); ///////// дописать и добавить удаление первых пустых строк  и проверит

/*
	if (!(temp = (char*)malloc((max_width + 1) * sizeof(char))))
		return (100); ////обработать ошибку
	while (prm->map_arr[str_n][i] != '\0')
	{
		temp[i] = prm->map_arr[str_n][i];
		i++;
	}
		while (i < max_width)
		temp[i++] = ' ';
	temp[i] = '\0';

	free(prm->map_arr[str_n]);
	prm->map_arr[str_n] = temp;
	temp = NULL;*/

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
		if (prm->count_line == 8 && (prm->exit = ft_chek_textur(prm)) != 0)
			return (prm->exit);
		if (id == 0)
			break;
	}
	if (id == 0 && prm->count_line < 8)
		return (prm->exit = 112); ///// мало ссылок на параметры в файле (выяснить чего не хватает?)
	prm->exit = 0;
	return (0);
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
		printf("------- str %d prm->map_arr >%s<\n", i, prm->map_arr[i]);
		temp_width = ft_strlen(prm->map_arr[i]);
		max_width = (max_width < temp_width) ? temp_width : max_width;
		i++;
	}
	if((prm->exit = ft_realloc_line(prm, i, max_width)))
		return (prm->exit);
	if((prm->exit = ft_check_map(prm)))
		return (prm->exit);






/*
	while(str_n >= 0)
	{
		if((ft_strlen(prm->map_arr[str_n])) < max_width)
		{
			if((prm->exit = ft_realloc_line(prm, str_n, max_width)))
			{
				//free all map_arr;
				return (prm->exit);
			}
		}
		str_n--;
	}
*/
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
		printf("!!! >%s<\n", "error - массив не создан");
	//printf("!!! >str #%d %s<\n", prm->str_n, prm->map_arr[prm->str_n]);



	return (0);
}
