/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ceilingDetails.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eej-jama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 10:37:36 by maneddam          #+#    #+#             */
/*   Updated: 2023/09/04 14:38:05 by eej-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	get_c_single_value(char *readline)
{
	static int	i;
	char		*num;
	int			r;

	num = NULL;
	if (readline[i] == 'f' || readline[i] == 'C' || readline[i] == ',')
		i++;
	while (readline[i] == 32 || readline[i] == '\t' || readline[i] == ',')
		i++;
	while (readline[i] && readline[i] != ',' && readline[i] != '\n'
		&& readline[i] != '\t')
	{
		num = ft_strjoin_char(num, readline[i]);
		i++;
	}
	if (!num)
		print_error("Invalid value");
	if (ft_strlen(num) > 3 || ft_atoi(num) > 255 || ft_atoi(num) < 0)
		print_error("Out of range");
	if (count_words(num) != 1)
		print_error("Invalid value");
	r = ft_atoi(num);
	free(num);
	return (r);
}

void	handle_ceiling_details(char *readLine, t_infos *infos)
{
	int	i;

	i = 0;
	while (readLine[i] == 32 || readLine[i] == '\t')
		i++;
	readLine = readLine + i;
	count_commas(readLine);
	invalid_characters(readLine);
	invalid_form(readLine);
	infos->c[0] = get_c_single_value(readLine);
	infos->c[1] = get_c_single_value(readLine);
	infos->c[2] = get_c_single_value(readLine);
}
