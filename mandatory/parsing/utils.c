/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eej-jama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 21:17:37 by maneddam          #+#    #+#             */
/*   Updated: 2023/09/04 14:38:05 by eej-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	count_words(char *str)
{
	int		count;
	int		i;
	bool	in_word;

	in_word = false;
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t')
		{
			in_word = false;
		}
		else if (!in_word)
		{
			in_word = true;
			count++;
		}
		i++;
	}
	return (count);
}

bool	is_compound(t_infos *infos)
{
	if (count_words(infos->no) > 1 || count_words(infos->so) > 1
		|| count_words(infos->we) > 1 || count_words(infos->ea) > 1)
		return (true);
	return (false);
}

void	count_commas(char *readLine)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (readLine[i] != 'F' && readLine[i] != 'C')
		return ;
	while (readLine[i])
	{
		if ((readLine[i]) == ',')
			count++;
		i++;
	}
	if (count != 2)
		print_error("Invalid commas count");
}

void	invalid_characters(char *readline)
{
	int	i;

	i = 0;
	while (readline[i] == 32 || readline[i] == '\t')
		i++;
	i++;
	while (readline[i])
	{
		if (readline[i] != ',' && !ft_isdigit(readline[i])
			&& readline[i] != '\n' && readline[i] != 32 && readline[i] != '\t')
			print_error("Invalid character");
		i++;
	}
}

void	invalid_form(char *readLine)
{
	int		i;
	bool	is_comma;

	i = 0;
	is_comma = false;
	while (readLine[i])
	{
		if (readLine[i] == ',')
		{
			if (readLine[i + 1])
				i++;
			while (readLine[i] == 32 || readLine[i] == '\t')
				i++;
			if (readLine[i] == ',')
				is_comma = true;
			else
				is_comma = false;
			if (is_comma)
				print_error("Comma after comma");
		}
		i++;
	}
}
