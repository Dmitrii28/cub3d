///https://onlinegdb.com/rkfXkCJ7w
//#include "get_next_line.h"
#include <stdio.h>
# include <fcntl.h>
# include "cub3d.h"
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s)
	{
	    while (s[i] != '\0')
		    i++;
	}
	return (i);
}

char    **ft_realloc_array(char **array, int str_n, char *line)
{
    char    **temp;
    int  i;
    
    i = 0;
    if (!(temp = (char**)malloc((str_n + 1) * sizeof(char*))))
	    return (NULL);
	while (str_n > i)
	{
	    temp[i] = array[i];
	    i++;
	}
	temp[i] = line;
	//free(array);
    //array = NULL;
    return (temp);
}

char *ft_realloc_line(char *array, size_t max_width)
{
    size_t  i;
    char    *temp;
    
    i = 0;
    if (!(temp = (char*)malloc((max_width + 1) * sizeof(char))))
	    return (NULL);
    while (array[i] != '\0')
    {
        temp[i] = array[i];
        i++;
    }
    while (i < max_width)
    {
        temp[i] = ' ';
        i++;
    }
    temp[i] = '\0';
   // free(array);
    //array = NULL;
    return (temp);
}

int main()
{
	char    *line;
	int     id = 0;
	int     str_n;
	int     height_array;
	t_str   *li;
	size_t  max_width;
	size_t  width_line;
	char    **array;
	
    height_array = 0;
    max_width = 0;
    str_n = 0;
	line = "";
	int fd = open("test.txt", O_RDONLY); 
    
     
	while ((id = get_next_line(fd, &line))>0  )
	{
		printf("                                | # >%d< | | >%d< | >%s<\n", str_n, id, line);
		
		width_line = ft_strlen(line);
		if (width_line > max_width)
		    max_width = width_line;
		if (!(array = ft_realloc_array(array, str_n, line)))
		{
		    //free all array;
		    return (0);
		}
		 //printf(">%s<\n", array[str_n]);
		str_n++;
	}
	printf("                                | # >%d< | | >%d< | >%s<\n", str_n, id, line);
    if (!(array = ft_realloc_array(array, str_n, line)))
		{
		    //free all array;
		    return (0);
		}
    //printf("!!! >%s<\n", array[str_n]);
    height_array = str_n;
    while(str_n >= 0)
    {
        if(ft_strlen(array[str_n]) < max_width)
        {
            if(!(array[str_n] = ft_realloc_line(array[str_n], max_width)))
           	{
	            //free all array;
	            return (0);
		    }
        }
        str_n--;
    }
    
    str_n++;
    while (str_n <= height_array)
    {
        printf("!!! >%s<\n", array[str_n]);
        str_n++;
    }
    
    
    
    
    //printf("!!! >%d<\n", max_width);
	return (0);
}
