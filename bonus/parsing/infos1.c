/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infos1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eej-jama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 04:50:13 by maneddam          #+#    #+#             */
/*   Updated: 2023/09/04 17:07:51 by eej-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_floor(char *readLine, t_infos *infos, int pos)
{
	infos->f = malloc(3 * sizeof(int));
	if ((readLine[pos + 1] != 32 && readLine[pos + 1] != '\t'))
		print_error("Invalid form");
	handle_floor_details(readLine, infos);
	infos->parameters++;
}

void	get_ceiling(char *readLine, t_infos *infos, int pos)
{
	infos->c = malloc(3 * sizeof(int));
	if ((readLine[pos + 1] != 32 && readLine[pos + 1] != '\t'))
		print_error("Invalid form");
	handle_ceiling_details(readLine, infos);
	infos->parameters++;
}

void	check_arg(char *mapPath)
{
	int	fd;
	int	i;

	fd = open(mapPath, O_RDONLY);
	if (fd < 0)
		print_error("Map not found");
	i = 0;
	while (mapPath[i])
		i++;
	i--;
	if (mapPath[i] != 'b' || mapPath[--i] != 'u' || mapPath[--i] != 'c'
		|| mapPath[--i] != '.' || mapPath[--i] == '/')
		print_error("Map extension must be as follow '.cub' !!");
}

void	check_attr(char *readline, t_infos *infos, int i)
{
	if (readline[i] == 'N')
		get_nord(readline, infos, i);
	else if (readline[i] == 'S')
		get_south(readline, infos, i);
	else if (readline[i] == 'W')
		get_west(readline, infos, i);
	else if (readline[i] == 'E')
		get_east(readline, infos, i);
	else if (readline[i] == 'F')
		get_floor(readline, infos, i);
	else if (readline[i] == 'C')
		get_ceiling(readline, infos, i);
	if (readline[i] == '1' && infos->parameters != 6)
		print_error("Invalid order");
}

void	check_map_items(char **map2d)
{
	int	i;
	int	j;

	i = 0;
	while (map2d[i])
	{
		j = 0;
		while (map2d[i][j])
		{
			if (map2d[i][j] != '1' && map2d[i][j] != '0' && map2d[i][j] != 32
				&& map2d[i][j] != '\t' && map2d[i][j] != 'N'
				&& map2d[i][j] != 'S' && map2d[i][j] != 'W'
				&& map2d[i][j] != 'E')
			{
				print_error("Invalid character");
			}
			j++;
		}
		i++;
	}
}
