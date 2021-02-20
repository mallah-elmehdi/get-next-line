/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 15:00:40 by emallah           #+#    #+#             */
/*   Updated: 2019/11/18 22:06:18 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	int				a;
	char			*ok;
	static char		*one_for_all;

	ok = NULL;
	if (BUFFER_SIZE < 0)
		return (-1);
	if ((a = check_ofa(&one_for_all)))
	{
		if (fill_it(&line, &one_for_all, &a) < 0)
			return (-1);
		if (re_size_ofa_2(&one_for_all, &a) < 0)
			return (-1);
		return (1);
	}
	if (simple_join(&ok, &one_for_all))
		return (-1);
	if (!(one_for_all = (char*)ft_calloc(sizeof(char), BUFFER_SIZE + 1)))
		return (-1);
	while ((a = read(fd, one_for_all, BUFFER_SIZE)))
	{
		if (a < 0)
			return (-1);
		if (((a = join_ft(&ok, &one_for_all)) < 0))
			return (-1);
		if (a < len_ft(ok))
		{
			fill_it(&line, &ok, &a);
			free(ok);
			return (1);
		}
	}
	free(ok);
	return (0);
}
