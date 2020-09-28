# include "../cub3d.h"

int		ft_take_param_s(char *temp, t_prm *params)
{
	if (temp[0] == 'S')
	{
		if (!(ft_strncmp(temp, "SO ", 3)))
		{
			if (params->so_txr)
				return ((params->msg = ft_strdup("SO")) ? 111 : 100); ///// двойная строка или ошибка маллока
			if (!(params->so_txr = ft_strdup(ft_strtrim(&temp[3], " "))))
				return (100); //// ошибка малллок
			params->count_line++;
		}
		else if (!(ft_strncmp(temp, "S ", 2)))
		{
			if (params->s_txr)
				return ((params->msg = ft_strdup("S")) ? 111 : 100); ///// двойная строка или ошибка маллока
			if (!(params->s_txr = ft_strdup(ft_strtrim(&temp[2], " "))))
				return (100); //// ошибка малллок
			params->count_line++;
		}
		else
			return (params->exit = 110);
	}
	return (0);
}
int 	ft_take_param_n_w(char *temp, t_prm *params)
{
	if (temp[0] == 'N' || temp[0] == 'W')
	{
		if (!(ft_strncmp(temp, "NO ", 3)))
		{
			if (params->no_txr)
				return ((params->msg = ft_strdup("NO")) ? 301 : 100); ///// двойная строка или ошибка маллока
			if (!(params->no_txr = ft_strdup(ft_strtrim(&temp[3], " "))))
				return (100); //// ошибка малллок
			params->count_line++;
		}
		else if (!(ft_strncmp(temp, "WE ", 3)))
		{
			if (params->we_txr)
				return ((params->msg = ft_strdup("WE")) ? 301 : 100); ///// двойная строка или ошибка маллока
			if (!(params->we_txr = ft_strdup(ft_strtrim(&temp[3], " "))))
				return (100); //// ошибка малллок
			params->count_line++;
		}
		else
			return (params->exit = 110);
	}
	return (0);
}


int		ft_take_param(t_prm *params)
{
	char *temp;

	if (!(temp = ft_strtrim(params->line, " ")))
		return (100); //// ошибка маллока
	if ((params->exit = ft_take_param_n_w(temp, params)))
		return (params->exit);
	if (temp[0] == 'E')
	{
		if (!(ft_strncmp(temp, "EA ", 3)))
		{
			if (params->ea_txr)
				return ((params->msg = ft_strdup("EA")) ? 111 : 100); ///// двойная строка или ошибка маллока
			if (!(params->ea_txr = ft_strdup(ft_strtrim(&temp[3], " "))))
				return (100); //// ошибка малллок
			params->count_line++;
		}
		else
			return (params->exit = 110);
	}
	if ((params->exit = ft_take_param_s(temp, params)))
		return (params->exit);
	if ((params->exit = ft_take_param_2(temp, params)))
			return (params->exit);
	free(temp);
	temp = NULL;
	return (0);
}