#include "get_next_line.h"

char	*ft_temp_and_newbuffer(char *buffer, t_list_items *li)
{
	li->error = 1;
	if (!(li->temp = (char *)malloc(sizeof(char) * (li->bf + 1))))
		return (ft_free(&buffer));
	li->bf = 0;
	while (buffer[li->bf] != '\0' && buffer[li->bf] != '\n')
	{
		li->temp[li->bf] = buffer[li->bf];
		li->bf++;
	}
	li->temp[li->bf] = '\0';

	if (buffer[li->bf] == '\n')
		li->bf++;
	if (buffer[li->bf] != '\0')
	{
		if (!(buffer = ft_rewrite_buffer(&buffer[li->bf], buffer)))
			return (ft_free(&li->temp));
	}
	else
	{
		free(buffer);
		buffer = NULL;
	}
	li->error = 0;
	return (buffer);
}

char	*ft_first_buffer(int fd, t_list_items *li, char *buffer)
{
	if (!buffer)
	{
		if(!(buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		{
			li->error = 1;
			return (NULL);
		}
		li->result = read(fd, buffer, BUFFER_SIZE);
		if (li->result < 0)
		{
			li->error = 1;
			free(buffer);
			return (NULL);
		}
		if (li->result == 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[li->result] = '\0';
	}
	while (buffer[li->bf] != '\n' && buffer[li->bf] != '\0')
		li->bf++;
	return (buffer);
}

char	*ft_buffer_plus_tmp(int fd, char *buffer, t_list_items *li)
{
	size_t i;

	i = 0;
	if(!(li->temp = (char *)malloc(BUFFER_SIZE + 1)))
	{
		free(buffer);
		return (NULL);
	}
	li->result = read(fd, li->temp, BUFFER_SIZE);
	if (li->result < 0)
	{
		free(buffer);
		return (ft_free(&li->temp));
	}
	if (li->result > 0)
	{
		li->temp[li->result] = '\0';
		if (!(buffer = ft_realloc(buffer, (li->result + li->bf))))
			return (ft_free(&li->temp));
		while (li->temp[i] != '\0')
			buffer[li->bf++] = li->temp[i++];
		buffer[li->bf] = '\0';
	}
	ft_free(&li->temp);
	return (buffer);
}

char	*ft_search_n_or_zero(int fd, char *buffer, t_list_items *li)
{
	while (buffer[li->bf] != '\n' && li->result != 0)
	{
		if(!(buffer = ft_buffer_plus_tmp(fd, buffer, li)))
			return (NULL);
		li->bf = 0;
		while (buffer[li->bf] != '\0' && buffer[li->bf] != '\n')
			li->bf++;
	}
	return (buffer);
}

int		get_next_line(int fd, char **line)
{
	t_list_items	li;
	static char		*buffer;

	li.result = 1;
	li.bf = 0;
	li.error = 0;
	if (fd < 0 || BUFFER_SIZE < 1 || !line)
		return (-1);
	if (!(buffer = ft_first_buffer(fd, &li, buffer)))
	{
		if (li.error == 1)
			return (-1);
		if(!(*line = (char *)malloc(sizeof(char) * 1)))
			return (-1);
		*line[0] = '\0';
		return (0);
	}
	if (!(buffer = ft_search_n_or_zero(fd, buffer, &li)))
		return (-1);
	if (!(buffer = ft_temp_and_newbuffer(buffer, &li)) && li.error == 1)
		return (-1);
	*line = li.temp;
	li.temp= NULL;
	return (li.result = li.result > 0 ? 1 : 0);
}