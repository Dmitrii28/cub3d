#include "../cub3d.h"
/*
static 	char	*ft_copy_line(char *temp, char *orig, int max_width)
{
	int i;

	i = 0;
	while (orig[i])
	{
		temp[i] = orig[i];
		i++;
	}
	while (i < max_width)
	{
		temp[i] = ' ';
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

int		ft_realloc_line(t_param *prm, int str_n, int max_width)
{
	int 	n;
	char    **temp;

	n = 0;
	if (!(temp = (char**)malloc(((str_n) + 1) * sizeof(char *))))
		return (100); ////// ошибка маллока
	while (n < str_n)
	{
		if (!(temp[n] = (char*)malloc((max_width + 1) * sizeof(char))))
			return (ft_free_array(temp, n - 1)); /////// возвращает 100 ошибка маллока
		temp[n] = ft_copy_line(temp[n], prm->map_arr[n], max_width);
		n++;
	}
	temp[n] = NULL;
	ft_free_array(prm->map_arr, n - 1);
	prm->map_arr = temp;
	temp = NULL;
	return (0);
}
*/
char **ft_copy_arr(char **arr, int str_n, int old_str)
{
	char **new;
	int i;
	int len;

	i = 0;
	if (!(new = (char**)malloc((str_n) * sizeof(char*))))
		return (NULL);
	while (i < old_str && arr[i] && arr)
	{
		len = ft_strlen(arr[i]);
		if (!(new[i] = (char*)malloc((len) * sizeof(char))))
		{
			ft_free_array(new, i - 1);
			return (NULL);
		}
		new[i] = ft_strdup(arr[i]);
		i++;
	}
	return (new);
}

int    ft_make_array(t_param *prm, int str_n)
{
	char    **temp_arr;
	int 	len;

	len = ft_strlen(prm->line);
	if (len == 0 && str_n == 0)
		return (1);
	prm->m_len = (prm->m_len < len) ? len : prm->m_len;
	if (len == 0 && prm->m_len > 0)
		return (90);
	if (len > 0 && prm->exit == 90)
		return (130); ///// пустая строка в карте
	if (!(temp_arr = ft_copy_arr(prm->map_arr, str_n + 1, str_n)))
		return (100);
	if (!(temp_arr[str_n] = ft_strdup(prm->line)))
		return (ft_free_array(temp_arr, str_n - 1));
	if (prm->map_arr)
		ft_free_array(prm->map_arr, str_n - 1);
	if (!(prm->map_arr = ft_copy_arr(temp_arr, str_n + 2, str_n + 1)))
		return (ft_free_array(temp_arr, str_n - 1));
	str_n++;
	prm->map_arr[str_n] = NULL;
	ft_free_array(temp_arr, str_n - 1);
	return (0);
}




