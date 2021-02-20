/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 20:47:31 by emallah           #+#    #+#             */
/*   Updated: 2019/11/18 15:02:46 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

void	*ft_calloc(size_t type, size_t size);
int		check_the_n(char **str);
int		join_ft(char **str, char **str0);
int		simple_join(char **ok, char **ofa);
int		re_size_ok(char ***str);
int		fill_it(char ***str1, char **str2, int *i);
int		re_size_ofa(char ***s1, int *j);
int		len_ft(char *s);
int		len_ft_n(char *s);
int		get_next_line(int fd, char **line);
int		check_ofa(char **ofa);
int		re_size_ofa_2(char **ofa, int *j);

#endif
