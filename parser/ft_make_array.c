#include "../cub3d.h"


int    ft_make_array(t_data *prm, int str_n)
{
	char    **temp_arr;
	int  i;

	i = 0;
	while (prm->line[i] && prm->line[i] == ' ')
		i++;
	if ((prm->line[i] == '\0' ) && str_n == 0)
		return (1);
	if ((prm->line[i] == '\0' ) && str_n != 0)
		return (90);
	if ((prm->line[i] != '\0') && str_n != 0 && prm->exit == 90)
		return (130); ///// пустая строка в карте
	i = 0;
	if (!(temp_arr = (char**)malloc((str_n + 1) * sizeof(char*))))
		return (100); //// ошибка малллока
	while (str_n > i)
	{
		temp_arr[i] = prm->map_array[i];
		i++;
	}
	temp_arr[i] = ft_strdup(prm->line);
	//temp_arr[i] = NULL; //// добавить эту строку ??????
	if (prm->map_array)
		free(prm->map_array);
	prm->map_array = temp_arr;
	temp_arr = NULL;
	return (0);
}




