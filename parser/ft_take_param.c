# include "../cub3d.h"


int		ft_take_param_s(char *temp, t_param *prm)
{
	if (temp[0] == 'S')
	{
		if (!(ft_strncmp(temp, "SO ", 3)))
		{
			if (prm->so_txr)
				return (prm->exit = 120); ///// двойная строка или ошибка маллока
			if (!(prm->so_txr = ft_strtrim(&temp[3], " ")))
				return (prm->exit = 100); //// ошибка малллок
			prm->count_line++;
		}
		else if (!(ft_strncmp(temp, "S ", 2)))
		{
			if (prm->s_txr)
				return (prm->exit = 121); ///// двойная строка или ошибка маллока
			if (!(prm->s_txr = ft_strtrim(&temp[2], " ")))
				return (prm->exit = 100); //// ошибка малллок
			prm->count_line++;
		}
		else
			return (prm->exit = 110);
	}
	return (0);
}
int 	ft_take_param_no_we(char *temp, t_param *prm)
{
	if (temp[0] == 'N' || temp[0] == 'W')
	{
		if (!(ft_strncmp(temp, "NO ", 3)))
		{
			if (prm->no_txr)
				return (prm->exit = 122); ///// двойная строка или ошибка маллока
			if (!(prm->no_txr = ft_strtrim(&temp[3], " ")))
				return (prm->exit = 100); //// ошибка малллок
			prm->count_line++;
		}
		else if (!(ft_strncmp(temp, "WE ", 3)))
		{
			if (prm->we_txr)
				return (prm->exit = 123); ///// двойная строка или ошибка маллока
			if (!(prm->we_txr = ft_strtrim(&temp[3], " ")))
				return (prm->exit = 100); //// ошибка малллок
			prm->count_line++;
		}
		else
			return (prm->exit = 110);
	}
	return (0);
}
int 	ft_take_param_ea(char *temp, t_param *prm)
{
	if (temp[0] == 'E')
	{
		if (!(ft_strncmp(temp, "EA ", 3)))
		{
			if (prm->ea_txr)
				return (prm->exit = 124); ///// двойная строка или ошибка маллока
			if (!(prm->ea_txr = ft_strtrim(&temp[3], " ")))
				return (prm->exit = 100); //// ошибка малллок
			prm->count_line++;
		}
		else
			return (prm->exit = 110);
	}
	return (0);
}
int		ft_take_param(t_param *prm)
{
	if (ft_strchr("CRWSECFN", prm->line[0]))
	{
		if (ft_take_param_no_we(prm->line, prm))
			return (prm->exit);
		if (ft_take_param_ea(prm->line, prm))
			return (prm->exit);
		if (ft_take_param_s(prm->line, prm))
			return (prm->exit);
		if (ft_take_param_2(prm->line, prm))
			return (prm->exit);
	}
	else
		return (prm->exit = 110);
	return (0);
}