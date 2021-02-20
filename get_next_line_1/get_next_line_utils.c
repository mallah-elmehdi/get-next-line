/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 14:43:19 by emallah           #+#    #+#             */
/*   Updated: 2019/11/18 20:52:48 by emallah          ###   ########.fr       */
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

int		join_ft(char **ok, char **ofa)
{
	int i;
	int j;

	i = len_ft(*ok);
	j = 0;
	if (re_size_ok(&ok) < 0)
		return (-1);
	if (*ok == NULL)
	{
		if(!(*ok = (char*)ft_calloc(sizeof(char), BUFFER_SIZE + 1)))
			return (-1);
	}
	while (ofa[0][j] != '\0')
	{
		if(ofa[0][j] == '\n')
		{
			j++;
			if (re_size_ofa(&ofa, &j) < 0)
				return (-1);
			return (len_ft(*ok) - len_ft_n(*ok));
		}
		ok[0][i] = ofa[0][j];
		i++;
		j++;
	}
	return (len_ft(*ok));
}

int		simple_join(char **ok, char **ofa)
{
	int i;

	i = 0;
	if (*ok && *ofa)
	{
		if (!(*ok = (char*)ft_calloc(sizeof(char), len_ft(*ofa) + 1)))
			return (-1);
		while (ofa[0][i] != '\0')
		{
			ok[0][i] = ofa[0][i];
			i++;
		}
		free (*ofa);
	}
	return (0);
}

int		re_size_ok(char ***ok)
{
	int i;
	char *holder;

	i = 0;
	if (**ok == NULL)
		return (0);
	if(!(holder = (char*)ft_calloc(sizeof(char), (len_ft(**ok)) + 1)))
		return (-1);
	while (ok[0][0][i] != '\0')
	{
		holder[i] = ok[0][0][i];
		i++;
	}
	free(**ok);
	if(!(**ok = (char*)ft_calloc(sizeof(char), BUFFER_SIZE + len_ft(holder) + 1)))
		return (-1);
	i = 0;
	while (holder[i] != '\0')
	{
		ok[0][0][i] = holder[i];
		i++;
	}
	free (holder);
	return (0);
}

int		fill_it(char ***line, char **ok, int *a)
{
	int i;

	i = 0;
	if(!(**line = (char*)ft_calloc(sizeof(char), *a)))
		return (-1);
	while (ok[0][i] != '\0')
	{
		if (ok[0][i] == '\n')
		{
			*a = i + 1;
			break ;
		}
		line[0][0][i] = ok[0][i];
		i++;
	}
	return (1);
}

int re_size_ofa(char ***ofa, int *j)
{
	int i;
	char *s;

	i = 0;
	if(!(s = (char*)ft_calloc(sizeof(char), len_ft_n(**ofa) + 1)))
		return (-1);
	while (ofa[0][0][*j] != '\0')
	{
		s[i] = ofa[0][0][*j];
		i++;
		*j = *j + 1;
	}
	free(**ofa);
	if(!(**ofa = (char*)ft_calloc(sizeof(char), len_ft(s) + 1)))
		return (-1);
	i = 0;
	while (s[i] != '\0')
	{
		ofa[0][0][i] = s[i];
		i++;
	}
	free(s);
	return (0);
}
int re_size_ofa_2(char **ofa, int *j)
{
	int i;
	char *s;

	i = 0;
	if(!(s = (char*)ft_calloc(sizeof(char), len_ft_n(*ofa) + 1)))
		return (-1);
	while (ofa[0][*j] != '\0')
	{
		s[i] = ofa[0][*j];
		i++;
		*j = *j + 1;
	}
	free(*ofa);
	if(!(*ofa = (char*)ft_calloc(sizeof(char), len_ft(s) + 1)))
		return (-1);
	i = 0;
	while (s[i] != '\0')
	{
		ofa[0][i] = s[i];
		i++;
	}
	free(s);
	return (0);
}

int len_ft(char *s)
{
	int i;

	i = 0;
	if (s)
	{
		while (s[i] != '\0')
			i++;
	}
	return (i);
}

int len_ft_n(char *s)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		i++;
		if (s[i] != '\n')
		{
			i++;
			while (s[i] != '\0')
			{
				j++;
				i++;
			}
		}
	}
	return (j);
}

int	check_ofa(char **ofa)
{
	int i;

	i = 0;
	if (*ofa)
	{
		while (ofa[0][i] != '\0')
		{
			if (ofa[0][i] == '\n')
				return (i + 1);
			i++;
		}
	}
	return (0);
}
