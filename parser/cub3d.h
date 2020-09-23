#ifndef CUB3D_H
# define CUB3D_H

# include "get_next_line.h"
# include <unistd.h>
# include <stdlib.h>


typedef struct	s_str
{
	int	max_width;
	
	
	int	minus;
	int	star_accuracy;
	int	dot;
	int	shift;
	int	result;
	int	width;
	int	accur;
	int	percent;
}				t_str;


size_t	ft_strlen(const char *s);













# endif