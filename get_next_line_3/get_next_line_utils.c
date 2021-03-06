/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 14:43:19 by emallah           #+#    #+#             */
/*   Updated: 2019/11/19 16:31:58 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		check_out(char **str1, char **str2, int *q)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (*str1 && str1[0][i] != '\0')
	{
		if (str1[0][i] == '\n')
		{
			str1[0][i] = 'l';
			i++;
			if (after_check(str1, str2, &i))
				return (1);
		}
		i++;
	}
	*q = len(*str2);
	return (0);
}

int		after_check(char **str1, char **str2, int *i)
{
	int j;

	j = 0;
	while (str1[0][*i] != '\0')
	{
		if (str1[0][*i] == '\n')
		{
			str2[0][j] = '\0';
			return (1);
		}
		str2[0][j] = str1[0][*i];
		*i = *i + 1;
		j++;
	}
	str2[0][j] = '\0';
	return (0);
}

int		fill_it(char **string1, char **string2, int *h, int *s)
{
	int		k;

	while ((k = read(*s, *string1, BUFFER_SIZE)))
	{
		if (k < 0)
			return (-1);
		string1[0][k] = '\0';
		if (re_alloc(string2) < 0)
			return (-1);
		k = 0;
		while (string1[0][k] != '\0')
		{
			if (string1[0][k] == '\n')
			{
				string2[0][*h] = '\0';
				return (1);
			}
			string2[0][*h] = string1[0][k];
			*h = *h + 1;
			k++;
		}
		string2[0][*h] = '\0';
	}
	return (0);
}

int		re_alloc(char **str)
{
	int		i;
	char	*h;

	i = 0;
	if (!(h = (char*)ft_calloc(sizeof(char), len(*str) + 1)))
		return (-1);
	if (*str && str[0][0] != '\0')
	{
		while (str[0][i] != '\0')
		{
			h[i] = str[0][i];
			i++;
		}
		free(*str);
		if (!(*str = (char*)ft_calloc(sizeof(char), len(h) + BUFFER_SIZE + 1)))
			return (-1);
		i = 0;
		while (h[i] != '\0')
		{
			str[0][i] = h[i];
			i++;
		}
	}
	free(h);
	return (0);
}

int		len(char *s)
{
	int		i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}
