/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reformMap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eej-jama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:03:37 by maneddam          #+#    #+#             */
/*   Updated: 2023/09/04 14:38:05 by eej-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_strlen_tab(char *line)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (line)
	{
		while (line[i])
		{
			if (line[i] == '\t')
				len = len + 3;
			i++;
			len++;
		}
	}
	return (len);
}

int	get_biggest_line_index(char **map)
{
	int	i;
	int	biggest;
	int	index;

	i = 0;
	index = 0;
	biggest = ft_strlen(map[0]);
	while (map[i])
	{
		if (ft_strlen(map[i]) > biggest)
		{
			biggest = ft_strlen(map[i]);
			index = i;
		}
		i++;
	}
	return (index);
}

void	makeit_rectangle(char **map, int maxlen)
{
	int	i;
	int	k;
	int	currentlen;

	i = 0;
	while (map[i])
	{
		currentlen = ft_strlen(map[i]);
		if (currentlen < maxlen)
		{
			k = 0;
			while (k < maxlen - currentlen)
			{
				map[i] = ft_strjoin_char(map[i], 32);
				k++;
			}
		}
		i++;
	}
}

char	**re_forme_map(char **map, t_infos *infos)
{
	infos->index_max_len = get_biggest_line_index(map);
	infos->max_len = ft_strlen(map[infos->index_max_len]);
	makeit_rectangle(map, infos->max_len);
	return (map);
}
