/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harmida <harmida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 01:24:36 by harmida           #+#    #+#             */
/*   Updated: 2020/09/21 01:24:38 by harmida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../libft/get_next_line.h"
# include <fcntl.h>
#include "../cub3d.h"

int	ft_check_args(int argc, char **argv);

typedef struct	s_str
{
	int	max_width;
	
	
	int	minus;
	int	star_accuracy;
	int	dot;
	int	result;
	int	width;
	int	accur;
	int	percent;
}				t_str;















# endif