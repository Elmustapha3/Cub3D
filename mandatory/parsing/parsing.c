/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eej-jama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 21:17:31 by maneddam          #+#    #+#             */
/*   Updated: 2023/09/04 17:46:39 by eej-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_infos_count(char *readLine, t_infos *infos)
{
	int	i;

	i = 0;
	while (readLine[i] == 32 || readLine[i] == '\t')
		i++;
	if (readLine[i] == '\n')
		return ;
	if (readLine[i] == 'N' && readLine[i + 1] == 'O')
		infos->infos_arr[0] = "no";
	else if (readLine[i] == 'S' && readLine[i + 1] == 'O')
		infos->infos_arr[1] = "so";
	else if (readLine[i] == 'W' && readLine[i + 1] == 'E')
		infos->infos_arr[2] = "we";
	else if (readLine[i] == 'E' && readLine[i + 1] == 'A')
		infos->infos_arr[3] = "ea";
	else if (readLine[i] == 'F' && (readLine[i + 1] == '\0'
			|| readLine[i + 1] == 32))
		infos->infos_arr[4] = "f";
	else if (readLine[i] == 'C' && (readLine[i + 1] == '\0'
			|| readLine[i + 1] == 32))
		infos->infos_arr[5] = "c";
	else if (readLine[i] != '1')
		print_error("Invalid attribute");
}

void	is_all_infos_in(t_infos *infos)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (ft_strcmp(infos->infos_arr[i], "00") == 0)
			print_error("Missing parameter");
		i++;
	}
	if (!infos->no || !infos->so || !infos->we || !infos->ea || !infos->f
		|| !infos->c)
		print_error("Missing parameter");
	if (is_compound(infos))
		print_error("Compound value");
	i = 0;
	while (i < 6)
	{
		free(infos->infos_arr_tmp[i]);
		i++;
	}
}

void	fill_arr_infos(char *readline, t_infos *infos)
{
	static int	line_pos;
	int			i;
	static bool	done;

	i = 0;
	while (readline[i] == 32 || readline[i] == '\t')
		i++;
	check_attr(readline, infos, i);
	if (readline[i] == '1' && infos->parameters == 6)
	{
		if (done == false)
		{
			infos->map_start_index = line_pos;
			done = true;
		}
	}
	if (ft_strcmp(readline, "\n") != 0)
		line_pos++;
}

void	get_file_elements(char *mapPath, t_infos *infos)
{
	char	*map;
	char	*fullmap;
	int		fd;

	fullmap = NULL;
	fd = open(mapPath, O_RDONLY);
	if (fd < 0)
		print_error("Error opening file");
	map = get_next_line(fd);
	if (!map)
		print_error("Invalid map");
	while (map != NULL)
	{
		fullmap = ft_strjoin_free(fullmap, map);
		get_infos_count(map, infos);
		fill_arr_infos(map, infos);
		free(map);
		map = get_next_line(fd);
	}
	is_all_infos_in(infos);
	handle_map(fullmap, infos);
	free(fullmap);
	check_map_items(infos->map2d);
}

void	parsing(char *argv, t_infos *infos)
{
	infos->p.x_start_pos = 0;
	infos->p.y_start_pos = 0;
	check_arg(argv);
	get_file_elements(argv, infos);
}
