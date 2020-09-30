

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

int		ft_realloc_line(t_prm *params, int str_n, int max_width)
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
			return (ft_free_array(temp, n)); /////// возвращает 100 ошибка маллока
		i = 0;
		while (params->map_array[n][i])
		{
			temp[n][i] = params->map_array[n][i];
			i++;
		}
		while (i < max_width)
			temp[n][i++] = ' ';
		temp[n++][i] = '\0';
	}
	ft_free_array(params->map_array, n - 1);
	params->map_array = temp;
	temp = NULL;
	return (0); ///////// дописать и добавить удаление первых пустых строк  и проверит

/*
	if (!(temp = (char*)malloc((max_width + 1) * sizeof(char))))
		return (100); ////обработать ошибку
	while (params->map_array[str_n][i] != '\0')
	{
		temp[i] = params->map_array[str_n][i];
		i++;
	}
		while (i < max_width)
		temp[i++] = ' ';
	temp[i] = '\0';

	free(params->map_array[str_n]);
	params->map_array[str_n] = temp;
	temp = NULL;*/

}
int		ft_prm_and_map(t_prm *params, int fd)
{
	int 	id;
	int 	str_n;

	str_n = 0;
	while ((id = get_next_line(fd, &params->line)) >= 0)
	{
		printf("                                | # >%d< | | >%d< | >%s<\n", str_n, id, params->line);
		if (params->count_line == 8)
		{
			if ((params->exit = ft_make_array(params, str_n)) >= 100)
				return (params->exit); /// обработать ошибк
			if (params->exit == 0)
				str_n++;
		}
		if (params->count_line < 8)
			if ((params->exit = ft_take_param(params)))
				return (params->exit);
		if (id == 0)
			break;
	}
	if (id == 0 && params->count_line < 8)
		return (params->exit = 112); ///// мало ссылок на параметры в файле (выяснить чего не хватает?)
	//if ((params->exit = ft_realloc_array(params, str_n)))
	//return (params->exit); /// обработать ошибк
	params->exit = 0;
	return (0);
}
int ft_parser(char *argv, t_prm *params)
{
	int     str_n;
	int		fd;
	int		max_width;
	int 	temp_width;

	max_width = 0;
	str_n = 0;
	if ((fd = open(argv, O_RDONLY)) < 0)   ///// obrabotat oshibky
		return (fd);
	if((params->exit = ft_prm_and_map(params, fd)))
		return (params->exit);


	char *temp333; //////////////////////// delit


	while (params->map_array[str_n])
	{

		temp333 = params->map_array[str_n];

		printf("------- str %d params->map_array >%s<\n", str_n, params->map_array[str_n]);

		temp_width = ft_strlen(params->map_array[str_n]);
		max_width = (max_width < temp_width) ? temp_width : max_width;
		str_n++;
	}









	if((params->exit = ft_realloc_line(params, str_n, max_width)))
		return (params->exit);



/*
	while(str_n >= 0)
	{
		if((ft_strlen(params->map_array[str_n])) < max_width)
		{
			if((params->exit = ft_realloc_line(params, str_n, max_width)))
			{
				//free all map_array;
				return (params->exit);
			}
		}
		str_n--;
	}
*/
	printf("!!! NO >%s<\n", params->no_txr);
	printf("!!! SO >%s<\n", params->so_txr);
	printf("!!! WE >%s<\n", params->we_txr);
	printf("!!! EA >%s<\n", params->ea_txr);
	printf("!!! S >%s<\n", params->s_txr);
	printf("x-win %d\n", params->x_win);
	printf("y-win %d\n", params->y_win);
	printf("floor %x\n", params->floor);
	printf("ceiling %x\n", params->ceiling);
	str_n = 0;

	if (params->map_array)
	{
		while (params->map_array[str_n])
		{
			printf("!!! >%s<\n", params->map_array[str_n]);
			str_n++;
		}
	}
	else
		printf("!!! >%s<\n", "error - массив не создан");
	printf("!!! >str #%d %s<\n", str_n, params->map_array[str_n]);



	return (0);
}
