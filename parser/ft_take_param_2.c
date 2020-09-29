#include "../cub3d.h"
int 	ft_take_param_r(char *temp, t_prm *params, int i)
{
	if (!(ft_strncmp(temp, "R ", 2)))
	{
		if (params->x_win != -1)
			return ((params->msg = ft_strdup("R")) ? 111 : 100); ///// двойная строка или ошибка маллока
		params->x_win = ft_atoi(&temp[i]);
		while (temp[i++] == ' ');
		while ((temp[i] >= '0') && (temp[i++] <= '9'));
		params->y_win = ft_atoi(&temp[i]);
		while (temp[i++] == ' ');
		while ((temp[i] >= '0') && (temp[i++] <= '9'));
		while (temp[i] == ' ' && temp[i++] != '\0');
		if (temp[i] != '\0')
			return (113); ///// неверный формат разрешения экрана
		params->count_line++;
	}
	else
		return (110);
	return (0);
}
int		ft_final_color(char **arr, t_prm *params, char fc_color) ///// сделать универсальный
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
		params->floor = (color_1 << 16 | color_2 << 8 | color_3);
	else
		params->ceiling = (color_1 << 16 | color_2 << 8 | color_3);
	params->count_line++;
	color = (color_1 << 16 | color_2 << 8 | color_3);
	printf("1 %d\n", color_1);
	printf("2 %d\n", color_2);
	printf("3 %d\n", color_3);
	printf("all %x\n", color);
	return (0); //////// много строк удалить printf
}

int 	ft_take_param_f(char *temp, t_prm *params, int i, int count_ch)
{
	char	**arr;
	int		str;

	str = 0;
	if (!(ft_strncmp(temp, "F ", 2)))
	{
		if (params->floor != -1)
			return ((params->msg = ft_strdup("F")) ? 111 : 100); ///// двойная строка или ошибка маллока
		while (temp[i] != '\0')
			if (temp[i++] == ',')
				count_ch++;
		i = 2;
		if (!(arr = ft_split(&temp[i], ',')))
			return (100); /////ошибка маллока
		while (arr[str] != NULL)
			str++;
		if (str != 3 || count_ch != 2)
			return (114); ///// неверный формат floor
	}
	else
		return (110); /////неверно начинается строка
	if ((params->exit = ft_final_color(arr, params, 'F')))
		return (params->exit);
	return (0); //////// много строк
}
int 	ft_take_param_c(char *temp, t_prm *params, int i, int count_ch)
{
	char	**arr;
	int		str;

	str = 0;
	if (!(ft_strncmp(temp, "C ", 2)))
	{
		if (params->ceiling != -1)
			return ((params->msg = ft_strdup("C")) ? 111 : 100); ///// двойная строка или ошибка маллока
		while (temp[i] != '\0')
			if (temp[i++] == ',')
				count_ch++;
		i = 2;
		if (!(arr = ft_split(&temp[i], ',')))
			return (100); /////ошибка маллока
		while (arr[str] != NULL)
			str++;
		if (str != 3 || count_ch != 2)
			return (115); ///// неверный формат floor
	}
	else
		return (110); /////неверно начинается строка
	if ((params->exit = ft_final_color(arr, params, 'C')))
		return (params->exit);
	return (0);
}

int 	ft_take_param_2(char *temp, t_prm *params)
{
	int	i;
	int	count_ch;

	i = 2;
	count_ch = 0;
	if (temp[0] == 'R')
	{
		if ((params->exit = ft_take_param_r(temp, params, i)))
			return (params->exit);
	}
	if (temp[0] == 'F')
	{
		if ((params->exit = ft_take_param_f(temp, params, i, count_ch)))
			return (params->exit);
	}
	if (temp[0] == 'C')
	{
		if ((params->exit = ft_take_param_c(temp, params, i, count_ch)))
			return (params->exit);
	}
	return (0);
}
