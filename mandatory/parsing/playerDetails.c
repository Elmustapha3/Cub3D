/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playerDetails.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eej-jama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 15:26:43 by maneddam          #+#    #+#             */
/*   Updated: 2023/09/04 17:41:12 by eej-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_player	player_pos(char **table_2d)
{
	t_player	p;
	int			i;
	int			j;

	p.x_start_pos = 0;
	p.y_start_pos = 0;
	i = 0;
	while (table_2d[i])
	{
		j = 0;
		while (table_2d[i][j])
		{
			if (table_2d[i][j] == 'N' || table_2d[i][j] == 'E'
				|| table_2d[i][j] == 'W' || table_2d[i][j] == 'S')
			{
				p.x_start_pos = j;
				p.y_start_pos = i;
				return (p);
			}
			j++;
		}
		i++;
	}
	return (p);
}

void	player_path(t_infos *infos, char **map, int x, int y)
{
	if (x < 0 || y < 0 || x > ft_strlen(map[y - 1]) || y > infos->y_len)
		return ;
	if (map[y][x] == '1' || map[y][x] == '*')
		return ;
	if (map[y][x] == 32 || map[y][x] == '\t')
	{
		print_error("Invalid path");
	}
	if (map[y][x] == '0' || map[y][x] == 'N' || map[y][x] == 'S'
		|| map[y][x] == 'W' || map[y][x] == 'E')
	{
		map[y][x] = '*';
		player_path(infos, map, x, y - 1);
		player_path(infos, map, x + 1, y);
		player_path(infos, map, x, y + 1);
		player_path(infos, map, x - 1, y);
	}
}

void	space_path(char **map2d)
{
	int	i;
	int	j;

	i = 0;
	while (map2d[i])
	{
		j = 0;
		while (map2d[i][j])
		{
			if (map2d[i][j] == '0')
			{
				is_space(map2d, i - 1, j);
				is_space(map2d, i + 1, j);
				is_space(map2d, i, j - 1);
				is_space(map2d, i, j + 1);
			}
			j++;
		}
		i++;
	}
}

void	check(char **map2d, t_infos *infos, int player_exist)
{
	if (player_exist != 1)
		print_error("It must be just one player");
	map2d = re_forme_map(map2d, infos);
	space_path(map2d);
	player_path(infos, map2d, infos->p.x_start_pos, infos->p.y_start_pos);
}

void	handle_player(char **map2d, t_infos *infos)
{
	int	i;
	int	j;
	int	player_exist;

	i = 0;
	j = 0;
	player_exist = 0;
	while (infos->map2d[i])
	{
		j = 0;
		while (infos->map2d[i][j])
		{
			if (infos->map2d[i][j] == 'N' || infos->map2d[i][j] == 'S'
				|| infos->map2d[i][j] == 'W' || infos->map2d[i][j] == 'E')
			{
				player_exist++;
				infos->p.x_start_pos = j;
				infos->p.y_start_pos = i;
			}
			j++;
		}
		i++;
	}
	check(map2d, infos, player_exist);
}
