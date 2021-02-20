/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 14:43:19 by emallah           #+#    #+#             */
/*   Updated: 2019/11/15 12:02:30 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t type, size_t size)
{
	size_t	i;
	void	*the_str;

	i = 0;
	if (!(the_str = malloc(type * size)))
		return (NULL);
	while (i < (type * size))
	{
		((unsigned char*)the_str)[i] = '\0';
		i++;
	}
	return (the_str);
}

int		check_out(char *str1, char **str2, int p, int q)
{
	while (str1 && str1[p] != '\0')
	{
		if (str1[p] == '\n')
		{
			str1[p] = 'l';
			p++;
			while (str1[p] != '\0')
			{
				if (str1[p] == '\n')
				{
					str2[0][q] = '\0';
					return (1);
				}
				str2[0][q] = str1[p];
				p++;
				q++;
			}
			str2[0][q] = '\0';
		}
		p++;
	}
	return (0);
}

int		fill_it(char *string1, char **string2, int h, int s)
{
	int	k;

	k = 0;
	while ((read(s, string1, BUFFER_SIZE)))
	{
		while (string1[k] != '\0')
		{
			if (string1[k] == '\n')
			{
				string2[0][h] = '\0';
				return (1);
			}
			string2[0][h] = string1[k];
			h++;
			k++;
		}
		string2[0][h] = '\0';
	}
	return (0);
}
