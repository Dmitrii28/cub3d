# include "../cub3d.h"
int 	ft_textr(t_data *prm)
{
	if ((ft_check_file(prm->no_txr, "xpm")) == 1 ||
		(ft_check_file(prm->so_txr, "xpm")) == 1 ||
		(ft_check_file(prm->we_txr, "xpm")) == 1 ||
		(ft_check_file(prm->ea_txr, "xpm")) == 1 ||
		(ft_check_file(prm->s_txr, "xpm")) == 1)
	{
		return (116); //////wrong   file extention texture
	}
	return (0);
}

int		ft_take_param_s(char *temp, t_data *prm)
{
	if (temp[0] == 'S')
	{
		if (!(ft_strncmp(temp, "SO ", 3)))
		{
			if (prm->so_txr)
				return (120); ///// двойная строка или ошибка маллока
			if (!(prm->so_txr = ft_strtrim(&temp[3], " ")))
				return (100); //// ошибка малллок
			prm->count_line++;
		}
		else if (!(ft_strncmp(temp, "S ", 2)))
		{
			if (prm->s_txr)
				return (121); ///// двойная строка или ошибка маллока
			if (!(prm->s_txr = ft_strtrim(&temp[2], " ")))
				return (100); //// ошибка малллок
			prm->count_line++;
		}
		else
			return (prm->exit = 110);
	}
	return (0);
}
int 	ft_take_param_no_we(char *temp, t_data *prm)
{
	if (temp[0] == 'N' || temp[0] == 'W')
	{
		if (!(ft_strncmp(temp, "NO ", 3)))
		{
			if (prm->no_txr)
				return (122); ///// двойная строка или ошибка маллока
			if (!(prm->no_txr = ft_strtrim(&temp[3], " ")))
				return (100); //// ошибка малллок
			prm->count_line++;
		}
		else if (!(ft_strncmp(temp, "WE ", 3)))
		{
			if (prm->we_txr)
				return (123); ///// двойная строка или ошибка маллока
			if (!(prm->we_txr = ft_strtrim(&temp[3], " ")))
				return (100); //// ошибка малллок
			prm->count_line++;
		}
		else
			return (prm->exit = 110);
	}
	return (0);
}
int 	ft_take_param_ea(char *temp, t_data *prm)
{
	if (temp[0] == 'E')
	{
		if (!(ft_strncmp(temp, "EA ", 3)))
		{
			if (prm->ea_txr)
				return (124); ///// двойная строка или ошибка маллока
			if (!(prm->ea_txr = ft_strtrim(&temp[3], " ")))
				return (100); //// ошибка малллок
			prm->count_line++;
		}
		else
			return (110);
	}
	return (0);
}
int		ft_take_param(t_data *prm)
{
	char *temp;

	if (!(temp = ft_strtrim(prm->line, " ")))
		return (100); //// ошибка маллока
	if ((prm->exit = ft_take_param_no_we(temp, prm)) ||
			(prm->exit = ft_take_param_ea(temp, prm)) ||
			(prm->exit = ft_take_param_s(temp, prm)) ||
			(prm->exit = ft_take_param_2(temp, prm)))
	{
		free(temp);
		temp = NULL;
		return (prm->exit);
	}
	free(temp);
	temp = NULL;
	free(prm->line);
	prm->line = NULL;
	return (0);
}