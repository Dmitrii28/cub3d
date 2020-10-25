#include "../cub3d.h"
int 	ft_take_param_r(char *temp, t_param *prm, int i)
{
	if (!(ft_strncmp(temp, "R ", 2)))
	{
		if (prm->x_win != -1)
			return (125); ///// двойная строка или ошибка маллока
		prm->x_win = ft_atoi(&temp[i]);
		while (temp[i] == ' ')
			i++;
		while ((temp[i] >= '0') && (temp[i] <= '9'))
			i++;
		prm->y_win = ft_atoi(&temp[i]);
		while (temp[i] == ' ')
			i++;
		while ((temp[i] >= '0') && (temp[i] <= '9'))
			i++;
		while (temp[i] == ' ' && temp[i] != '\0')
			i++;
		if (temp[i] != '\0')
			return (113); ///// неверный формат разрешения экрана
		prm->count_line++;
	}
	else
		return (110);
	return (0);
}
int		ft_final_color(char **arr, t_param *prm, char fc_color) ///// сделать универсальный
{
	int	color_1;
	int	color_2;
	int	color_3;
	int	color;
	int i;

	i = 0;
	if ((color_1 = ft_atoi(arr[0])) < 0 || color_1 > 255 ||
		(color_2 = ft_atoi(arr[1])) < 0 || color_2 > 255 ||
		(color_3 = ft_atoi(arr[2])) < 0 || color_3 > 255)
			return (fc_color == 'F' ? 114 : 115); ///////   на двоих F C неверный формат
	while (arr[2][i++] == ' ');
	while ((arr[2][i] >= '0') && (arr[2][i++] <= '9'));
	while (arr[2][i] == ' ' && arr[2][i++] != '\0');
	if (arr[2][i] != '\0')
		return (fc_color == 'F' ? 114 : 115); ///////   на двоих F C неверный формат
	if (fc_color == 'F')
		prm->floor = (color_1 << 16 | color_2 << 8 | color_3);
	else
		prm->ceiling = (color_1 << 16 | color_2 << 8 | color_3);
	prm->count_line++;
	color = (color_1 << 16 | color_2 << 8 | color_3);
	printf("1 %d\n", color_1);
	printf("2 %d\n", color_2);
	printf("3 %d\n", color_3);
	printf("all %x\n", color);
	return (0); //////// много строк удалить printf
}

int 	ft_take_param_f(char *temp, t_param *prm, int i, int count_ch)
{
	if (!(ft_strncmp(temp, "F ", 2)))
	{
		if (prm->floor != -1)
			return (127); ///// двойная строка
		if (!(temp = ft_strtrim(&temp[2], " ")))
			return (100);
		while (temp[i] != '\0')
		{
			if (!(ft_strchr(",0123456789", temp[i])))
				return (115); ///// неверный формат floor
			if (temp[i++] == ',')
				count_ch++;
		}
		if (count_ch != 2)
			return (115); ///// неверный формат floor
		if (!(prm->color_arr = ft_split(temp, ',')))
			return (100); /////ошибка маллока
		free(temp);
	}
	else
		return (110); /////неверно начинается строка
	if ((prm->exit = ft_final_color(prm->color_arr, prm, 'F')))
		return (prm->exit);
	ft_free_array(prm->color_arr, 2);
	return (0);
}
int 	ft_take_param_c(char *temp, t_param *prm, int i, int count_ch)
{
	if (!(ft_strncmp(temp, "C ", 2)))
	{
		if (prm->ceiling != -1)
			return (127); ///// двойная строка
		if (!(temp = ft_strtrim(&temp[2], " ")))
			return (100);
		while (temp[i] != '\0')
		{
			if (!(ft_strchr(",0123456789", temp[i])))
				return (115); ///// неверный формат floor
			if (temp[i++] == ',')
				count_ch++;
		}
			if (count_ch != 2)
			return (115); ///// неверный формат floor
		if (!(prm->color_arr = ft_split(temp, ',')))
			return (100); /////ошибка маллока
		free(temp);
	}
	else
		return (110); /////неверно начинается строка
	if ((prm->exit = ft_final_color(prm->color_arr, prm, 'C')))
		return (prm->exit);
	ft_free_array(prm->color_arr, 2);
	return (0);
}

int 	ft_take_param_2(char *temp, t_param *prm)
{
	int	i;
	int	count_ch;

	i = 2;
	count_ch = 0;
	if (temp[0] == 'R')
	{
		if ((prm->exit = ft_take_param_r(temp, prm, i)))
			return (prm->exit);
	}
	else if (temp[0] == 'F')
	{
		if ((prm->exit = ft_take_param_f(temp, prm, i, count_ch)))
			return (prm->exit);
	}
	else if (temp[0] == 'C')
	{
		if ((prm->exit = ft_take_param_c(temp, prm, i, count_ch)))
			return (prm->exit);
	}
	else
		return(110);
	return (0);
}
