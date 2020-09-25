

# include "parser.h"

int    ft_realloc_array(t_prm *params, int str_n)
{
	char    **temp;
	int  i;

	i = 0;
	if (!(temp = (char**)malloc((str_n + 1) * sizeof(char*))))
	{
		// очистить массив на n строк и строку
		return (200);
	}
	while (str_n > i)
	{
		temp[i] = params->map_array[i];
		i++;
	}
	temp[i] = params->line;
	params->map_array = temp;
	params->line = NULL;
	temp = NULL;
	//free(map_array);
	//map_array = NULL;
	return (0);
}

int		ft_realloc_line(t_prm *params, int str_n, size_t max_width)
{
	int  i;
	char    *temp;

	i = 0;


	if (!(temp = (char*)malloc((max_width + 1) * sizeof(char))))
		return (200); ////обработать ошибку
	while (params->map_array[str_n][i] != '\0')
		temp[i++] = params->map_array[str_n][i];
	while (i < max_width)
		temp[i++] = ' ';
	temp[i] = '\0';

	free(params->map_array[str_n]);
	params->map_array[str_n] = temp;
	temp = NULL;
	return (0);
}

int parser(char *argv, t_prm *params)
{
	int     id;
	int     str_n;
	int		fd;

	str_n = 0;
	if ((fd = open(argv, O_RDONLY)) < 0)   ///// obrabotat oshibky
		return (fd);
	while ((id = get_next_line(fd, &params->line)) >= 0)
	{
		printf("        1                        | # >%d< | | >%d< | >%s<\n", str_n, id, params->line);
		if (ft_strlen(ft_strtrim(params->line, " ")) > 0) ///////неправильно есть маллок
		{
			if ((params->exit = ft_realloc_array(params, str_n)))
				return (params->exit); /// обработать ошибк
			str_n++;
		}
		if (id == 0)
			break ;
	}






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





	str_n = 0;
	while (params->map_array[str_n])
	{
		printf("!!! >%s<\n", params->map_array[str_n]);
		str_n++;
	}
	return (0);
}
