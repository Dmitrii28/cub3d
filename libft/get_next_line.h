/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harmida <harmida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 01:24:36 by harmida           #+#    #+#             */
/*   Updated: 2020/09/21 01:24:38 by harmida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif


typedef struct	s_list_items
{
	ssize_t	result;
	size_t	bf;
	int		error;
	char	*temp;
}				t_list_items;
int     parser();
int		get_next_line(int fd, char **line);
char	*ft_temp_and_newbuffer(char *buffer, t_list_items *li);
char	*ft_first_buffer(int fd, t_list_items *li, char *buffer);
char	*ft_buffer_plus_tmp(int fd, char *buffer, t_list_items *li);
char	*ft_search_n_or_zero(int fd, char *buffer, t_list_items *li);
char	*ft_rewrite_buffer(char *s1, char *buffer);
char	*ft_free(char **str);
char	*ft_realloc(char *buffer, int newsize);
#endif

