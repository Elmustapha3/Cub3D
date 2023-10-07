/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eej-jama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 21:17:24 by maneddam          #+#    #+#             */
/*   Updated: 2023/09/04 14:38:05 by eej-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_nord(char *readLine, t_infos *infos, int pos)
{
	static int	duplicated;
	int			i;

	i = pos;
	if ((readLine[pos + 2] != 32 && readLine[pos + 2] != '\t'))
		print_error("Invalid form");
	if (!duplicated)
	{
		duplicated = 1;
		infos->no = NULL;
		i = i + 2;
		while (readLine[i] == 32 || readLine[i] == '\t')
			i++;
		while (readLine[i] && readLine[i] != '\n')
		{
			infos->no = ft_strjoin_char(infos->no, readLine[i]);
			i++;
		}
		infos->parameters++;
	}
	else
		print_error("Duplicated parameter");
}

void	get_south(char *readLine, t_infos *infos, int pos)
{
	int			i;
	static int	duplicated;

	i = pos;
	if ((readLine[pos + 2] != 32 && readLine[pos + 2] != '\t'))
		print_error("Invalid form");
	if (!duplicated)
	{
		duplicated = 1;
		infos->so = NULL;
		i = i + 2;
		while (readLine[i] == 32 || readLine[i] == '\t')
			i++;
		while (readLine[i] && readLine[i] != '\n')
		{
			infos->so = ft_strjoin_char(infos->so, readLine[i]);
			i++;
		}
		infos->parameters++;
	}
	else
		print_error("Duplicated parameter");
}

void	get_west(char *readLine, t_infos *infos, int pos)
{
	static int	duplicated;
	int			i;

	i = pos;
	if ((readLine[pos + 2] != 32 && readLine[pos + 2] != '\t'))
		print_error("Invalid form");
	if (!duplicated)
	{
		duplicated = 1;
		infos->we = NULL;
		i = i + 2;
		while (readLine[i] == 32 || readLine[i] == '\t')
			i++;
		while (readLine[i] && readLine[i] != '\n')
		{
			infos->we = ft_strjoin_char(infos->we, readLine[i]);
			i++;
		}
		infos->parameters++;
	}
	else
		print_error("Duplicated parameter");
}

void	get_east(char *readLine, t_infos *infos, int pos)
{
	static int	duplicated;
	int			i;

	i = pos;
	if ((readLine[pos + 2] != 32 && readLine[pos + 2] != '\t'))
		print_error("Invalid form");
	if (!duplicated)
	{
		duplicated = 1;
		infos->ea = NULL;
		i = i + 2;
		while (readLine[i] == 32 || readLine[i] == '\t')
			i++;
		while (readLine[i] && readLine[i] != '\n')
		{
			infos->ea = ft_strjoin_char(infos->ea, readLine[i]);
			i++;
		}
		infos->parameters++;
	}
	else
		print_error("Duplicated parameter");
}
