#include "../cub3d.h"


int    ft_make_array(t_prm *params, int str_n)
{
	char    **temp;
	int  i;

	i = 0;


	int	t;

	t = 0;
	while (params->line[t] && params->line[t] == ' ')
		t++;

	if ((params->line[t] == '\0' || t == 0) && str_n == 0)
		return (1);
	if ((params->line[t] == '\0' || t == 0) && str_n != 0)
		return (130);
////////////////////////////// обработать ошибку с пустой строкой посередине




	if (!(temp = (char**)malloc((str_n + 1) * sizeof(char*))))
		return (100); //// ошибка малллока
	while (str_n > i)
	{
		temp[i] = params->map_array[i];
		i++;
	}
	temp[i] = params->line;
	//i++;
	//temp[i] = NULL;
	params->map_array = temp;
	params->line = NULL;
	temp = NULL;
	return (0);
}




