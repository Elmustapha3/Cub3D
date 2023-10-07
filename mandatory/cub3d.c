/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eej-jama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 21:17:42 by maneddam          #+#    #+#             */
/*   Updated: 2023/09/04 17:42:48 by eej-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

int	main(int argc, char *argv[])
{
	t_infos	*infos;
	int		i;

	i = 0;
	infos = malloc(sizeof(t_infos));
	infos->parameters = 0;
	infos->max_len = 0;
	infos->index_max_len = 0;
	while (i < 6)
	{
		infos->infos_arr[i] = malloc(3);
		infos->infos_arr_tmp[i] = infos->infos_arr[i];
		infos->infos_arr[i] = "00";
		i++;
	}
	if (argc == 2)
	{
		parsing(argv[1], infos);
		raycasting(infos);
	}
	else
		print_error("Invalid argument number");
}
