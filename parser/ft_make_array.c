#include "../cub3d.h"

char **ft_copy_arr(char **arr, int str_n, int old_str)
{
	char **new;
	int i;

	i = 0;
	if (!(new = (char **)malloc((str_n) * sizeof(char *))))
		return (NULL);
	while (i < old_str)
	{
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
		return (ft_free_array(temp_arr, str_n));
	if (prm->map_arr)
		ft_free_array(prm->map_arr, str_n - 1);
	if (!(prm->map_arr = ft_copy_arr(temp_arr, str_n + 1, str_n + 1)))
		return (ft_free_array(temp_arr, str_n));
	ft_free_array(temp_arr, str_n);
	return (0);
}




