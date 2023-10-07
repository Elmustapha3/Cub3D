/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eej-jama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 23:41:13 by eej-jama          #+#    #+#             */
/*   Updated: 2023/09/04 14:38:05 by eej-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_pixel(t_mlx_data *data, int x, int y, int color)
{
	if (x > data->inf->max_len * 60 || x < 0
		|| y > data->inf->y_len * 60 || y < 0)
		return ;
	my_mlx_pixel_put(data, x, y, color);
}

void	circle(t_mlx_data *m, int x, int y, int radius)
{
	int	i;
	int	j;

	i = -radius;
	while (i <= radius)
	{
		j = -radius;
		while (j <= radius)
		{
			if (i * i + j * j <= radius * radius)
				my_mlx_pixel_put(m, x + i, y + j, 0xFF0000);
			j++;
		}
		i++;
	}
}

void	my_mlx_pixel_put(t_mlx_data *data, int x, int y, int color)
{
	char	*dst;

	if (x > WIN_W || y > WIN_H || x < 0 || y < 0)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

bool	is_wall(t_mlx_data *m, double x, double y)
{
	int	grid_x;
	int	grid_y;

	if (x < 0 || y < 0 || x >= m->inf->max_len * SQUARE_SIZE
		|| y >= m->inf->y_len * SQUARE_SIZE)
		return (true);
	grid_x = (int)(floor(x / SQUARE_SIZE));
	grid_y = (int)(floor(y / SQUARE_SIZE));
	if (m->inf->map2d[grid_y][grid_x] == '1'
		|| m->inf->map2d[(int)(m->inf->p.y_position / SQUARE_SIZE)]
			[grid_x] == '1'
		|| m->inf->map2d[grid_y][(int)(m->inf->p.x_position
			/ SQUARE_SIZE)] == '1' || m->inf->map2d[grid_y][grid_x] == 32)
		return (true);
	return (false);
}

bool	is_wall_for_ray(t_mlx_data *m, double x, double y)
{
	int	grid_x;
	int	grid_y;

	grid_x = (int)((x / SQUARE_SIZE));
	grid_y = (int)((y / SQUARE_SIZE));
	if (x < 0 || y < 0 || x >= m->inf->max_len * SQUARE_SIZE
		|| y >= m->inf->y_len * SQUARE_SIZE
		|| grid_x > ft_strlen(m->inf->map2d[grid_y])
		|| grid_y > m->inf->y_len)
		return (true);
	if (m->inf->map2d[grid_y][grid_x] == '1')
		return (true);
	return (false);
}
