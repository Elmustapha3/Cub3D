/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eej-jama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 21:17:08 by maneddam          #+#    #+#             */
/*   Updated: 2023/09/04 17:44:37 by eej-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	is_space(char **map2d, int i, int j)
{
	if (map2d[i][j] == 32)
		print_error("Map not surronded by walls");
}

void	print_error(char *msg)
{
	printf(RED "Error\n%s" RESET, msg);
	exit(EXIT_FAILURE);
}
