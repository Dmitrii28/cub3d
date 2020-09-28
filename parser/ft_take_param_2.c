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
			return (params->exit = 113); ///// неверный формат разрешения экрана
		params->count_line++;
	}
	else
		return (params->exit = 110);
	return (0);
}



int 	ft_take_param_f(char *temp, t_prm *params, int i)
{
	int floor_1;
	int floor_2;
	int floor_3;
	char **arr;
	int count;

	count = 0;
	if (!(ft_strncmp(temp, "F ", 2)))
	{
		if (params->floor != -1)
			return ((params->msg = ft_strdup("F")) ? 111 : 100); ///// двойная строка или ошибка маллока
		while (temp[i++] != '\0')
			if (temp[i] == ',' && count++);
		i = 2;
printf("ch = %d \n", count);
		if (count != 2)
			return (params->exit = 114); ///// неверный формат floor
		count = 0;
		if (!(arr = ft_split(&temp[i], ',')))
			return (100); /////ошибка маллока
		while (arr[count] != NULL)
			count++;
		if (count != 3)
			return (params->exit = 114); ///// неверный формат floor
		printf("arr = %d \n", count);
/*
		floor_1 = ft_atoi(&temp[i]);
		while (temp[i++] == ' ');
		while ((temp[i] >= '0') && (temp[i++] <= '9'));

		floor_2 = ft_atoi(&temp[i]);

		while (temp[i++] == ' ');
		while ((temp[i] >= '0') && (temp[i++] <= '9'));
		while (temp[i] == ' ' && temp[i++] != '\0');
		if (temp[i] != '\0')
			return (params->exit = 113); ///// неверный формат разрешения экрана
		params->count_line++;
		*/
	}
	else
		return (params->exit = 110888);

	return (0);
}







int 	ft_take_param_2(char *temp, t_prm *params)
{
	int i;

	i = 2;
	if (temp[0] == 'R')
	{
		if ((params->exit = ft_take_param_r(temp, params, i)))
			return (params->exit);
	}
	if (temp[0] == 'F')
	{
		if ((params->exit = ft_take_param_f(temp, params, i)))
			return (params->exit);
	}
	return (0);
}
