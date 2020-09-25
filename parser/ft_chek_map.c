

#include "../cub3d.h"
///// proverit 4tobi bil 1 igrok na karte
int ft_check_yacheik(char **array, int j, int i, int height_array)
{


	if (j == 0)
	{
		if (array[j][i] == ' ' && !(ft_strchr("1 ", array[j][i + 1])) && !(ft_strchr("1 ", array[j + 1][i])))
			return (-1);
		if(ft_strchr("02NSWE", array[j][i]))
			return (-1);

	}
	else if (j == height_array)
	{
		if (array[j][i] == ' ' && !(ft_strchr("1 ", array[j][i + 1])) )
			return (-1);
		if(ft_strchr("02NSWE", array[j][i]))
			return (-1);
	}
	else
	{
		if (array[j][i] == ' ' && !(ft_strchr("1 ", array[j][i + 1])) && !(ft_strchr("1 ", array[j + 1][i])))
			return (-1);
		if ((i == 0 || array[j][i + 1] == '\0') && ft_strchr("02NSWE", array[j][i]))
			return (-1);

	}
	return (0);
}

int ft_check_map(char **array, int height_array)
{
	int     j;
	int     i;

	j = 0;
	i = 0;
	while (j <= height_array)
	{
		i = 0;
		while (array[j][i] != '\0')
		{
			if (!(ft_strchr("012 NSWE", array[j][i])))
				return (-1);
			if (j > 0 && j < height_array)
			{
				if (ft_strchr("02NSWE", array[j][i]) && (array[j][i + 1] ==' ' || array[j + 1][i] == ' '))
					return (-1);
			}
			if (ft_check_yacheik(array, j, i, height_array) == -1)
				return (-1);

			i++;
		}
		j++;
	}
	return (0);
}