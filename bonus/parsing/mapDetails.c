/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapDetails.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eej-jama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 17:55:24 by maneddam          #+#    #+#             */
/*   Updated: 2023/09/04 14:38:05 by eej-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	handle_first_line(char *firstline)
{
	int	i;

	i = 0;
	while (firstline[i])
	{
		if (firstline[i] != 32 && firstline[i] != '\t' && firstline[i] != '1')
			print_error("Invalid maaap");
		i++;
	}
}

void	handle_last_line(char *lastline)
{
	int	i;

	i = 0;
	while (lastline[i])
	{
		if (lastline[i] != 32 && lastline[i] != '\t' && lastline[i] != '1')
			print_error("Invalid map");
		i++;
	}
}

void	handle_middle_lines(char **map)
{
	int	i;
	int	j;

	i = 1;
	while (map[i])
	{
		j = 0;
		while (map[i][j] == 32 || map[i][j] == '\t')
			j++;
		if (map[i][j] && (map[i][j] != '1' || map[i][ft_strlen(map[i])
				- 1] == '0'))
			print_error("Invalid maapi");
		i++;
	}
}

void	check_nested_nl(char *fullmap, t_infos *infos)
{
	int	i;

	i = get_map_start(fullmap);
	infos->map1d = fullmap + i;
	i = 0;
	if (infos->map1d[i] == '1' && infos->map1d[i + 1] == '1')
	{
		while (infos->map1d[i])
		{
			if (infos->map1d[i] == '1' && infos->map1d[i + 1] == '\n'
				&& infos->map1d[i + 2] == '\n' && !is_rest_empty(infos->map1d
					+ i))
				print_error("Nested empty lines");
			i++;
		}
	}
}

void	handle_map(char *fullmap, t_infos *infos)
{
	char	**map2d;
	char	**tmp;
	int		i;

	i = 0;
	check_nested_nl(fullmap, infos);
	infos->y_len = 0;
	map2d = ft_split(fullmap, '\n');
	infos->map2d = ft_split(fullmap, '\n');
	infos->tmp_1 = infos->map2d;
	infos->map2d = infos->map2d + infos->map_start_index;
	tmp = map2d;
	map2d = map2d + infos->map_start_index;
	handle_white_spaces(map2d);
	infos->y_len = get_y_len(infos->map2d);
	handle_first_line(infos->map2d[0]);
	handle_middle_lines(infos->map2d);
	handle_last_line(infos->map2d[infos->y_len - 1]);
	handle_player(map2d, infos);
	while (tmp[i])
	{
		free(tmp[i]);
		i++;
	}
	free(tmp);
}
