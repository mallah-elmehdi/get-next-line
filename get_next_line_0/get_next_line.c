/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teest.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 07:20:55 by emallah           #+#    #+#             */
/*   Updated: 2019/11/15 12:02:16 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	int				a;
	int				i;
	int				j;
	static char		*one_for_all;

	i = 0;
	j = 0;
	a = 0;
	if (BUFFER_SIZE <= 0)
		return (-1);
	if (CheckOut(one_for_all, line, i, j))
		return (1);
	if (one_for_all)
		free(one_for_all);
	if (!(one_for_all = (char*)ft_calloc(sizeof(char), BUFFER_SIZE + 1)))
		return (-1);
	if ((a = FillIt(one_for_all, line, j, fd)))
		return (1);
	free(one_for_all);
	if (a < 0)
		return (-1);
	return (0);
}
