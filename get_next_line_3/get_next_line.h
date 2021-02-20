/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 20:47:31 by emallah           #+#    #+#             */
/*   Updated: 2019/11/19 16:30:54 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

void	*ft_calloc(size_t type, size_t size);
int		check_out(char **str1, char **str2, int *i);
int		fill_it(char **string1, char **string2, int *h, int *s);
int		re_alloc(char **str);
int		len(char *s);
int		after_check(char **str1, char **str2, int *i);
int		get_next_line(int fd, char **line);
#endif
