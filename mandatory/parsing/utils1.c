/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eej-jama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 04:57:52 by maneddam          #+#    #+#             */
/*   Updated: 2023/09/04 14:38:05 by eej-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	handle_white_spaces(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '\t')
				print_error("Invalid character");
			j++;
		}
		i++;
	}
}

bool	is_rest_empty(char *rest)
{
	int	i;

	i = 1;
	while (rest[i])
	{
		if (rest[i] != 32 && rest[i] != '\t' && rest[i] != '\n')
			return (false);
		i++;
	}
	return (true);
}

int	get_y_len(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	get_map_start(char *fullmap)
{
	int	i;

	i = 0;
	while (fullmap[i])
	{
		if (fullmap[i] == 'N' || fullmap[i] == 'S' || fullmap[i] == 'E'
			|| fullmap[i] == 'W' || fullmap[i] == 'C' || fullmap[i] == 'f')
		{
			while (fullmap[i] && fullmap[i] != '\n')
				i++;
			i--;
			continue ;
		}
		if (fullmap[i] == '1' && fullmap[i + 1] == '1' && fullmap[i + 2] == '1')
			break ;
		i++;
	}
	return (i);
}
