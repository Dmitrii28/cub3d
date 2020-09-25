#include "get_next_line.h"

char	*ft_rewrite_buffer(char *s1, char *buffer)
{
	char		*str;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
	{
		free(buffer);
		return (NULL);
	}
	while (s1[j] != '\0')
	{
		str[j] = s1[j];
		j++;
	}
	str[j] = '\0';
	free(buffer);
	return (str);
}

char	*ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

char	*ft_realloc(char *buffer, int newsize)
{
	char	*str;
	int		i;

	i = 0;
	if (!(str = (char *)malloc(sizeof(char) * (newsize + 1))))
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	while (buffer[i] != '\0')
	{
		str[i] = buffer[i];
		i++;
	}
	str[i] = '\0';
	free(buffer);
	buffer = NULL;
	return (str);
}
