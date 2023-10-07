/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deleting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maneddam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 01:18:40 by maneddam          #+#    #+#             */
/*   Updated: 2023/02/28 18:50:43 by maneddam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	show_msg(const char *message, int x)
{
	printf("%s", message);
	if (x % 4 == 0 && x > 0)
		printf(" \n");
	if (x % 4 == 1 && x > 0)
		printf(" .\n");
	else if (x % 4 == 2 && x > 0)
		printf(" ..\n");
	else if (x % 4 == 3 && x > 0)
		printf(" ...\n");
}

void	progress_bar(int percent, const char *message, int x)
{
	int	bar_width;
	int	num_bars;
	int	i;

	i = 0;
	printf("\033[2J");
	printf("\033[H");
	bar_width = 50;
	num_bars = (percent * bar_width) / 100;
	while (i++ < num_bars)
		printf("\e[1;31m▇");
	i = num_bars;
	while (i++ < bar_width)
		printf(" ");
	printf("  %d%%\n", percent);
	show_msg(message, x);
}

int	main(void)
{
	int			i;
	static int	x;

	i = 0;
	while (i <= 100)
	{
		if (i == 100)
		{
			progress_bar(i, "\nDeleted !\n", -1);
			usleep(100000);
		}
		else
		{
			progress_bar(i, "\nDeleting in progress", i);
			usleep(20000);
		}
		i++;
	}
	return (0);
}
